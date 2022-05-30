<?php

  require_once "database.php";
  // Initialize the session
  session_start();
  
  // Check if the user is logged in, if not then redirect him to login page
  if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
      header("location: login.php");
      exit;
  }

  $name = $gender = $country = $message = "";

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = "%".(test_input($_POST["name"]))."%";
    $gender = (test_input($_POST["gender"]))."%";
    $message = "%".(test_input($_POST["message"]))."%";

    $sql = "SELECT * FROM data WHERE 
        (gender LIKE :gender) AND 
        (name LIKE :name) AND 
        (message LIKE :message)";
  }


  function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }

?>
<!DOCTYPE html>
<html lang="en"></html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Show DB</title>
    <link rel="stylesheet" href="style.css">
    <style>
      table, th, td {
        border: 2px solid black;
      }
      table {
        width: 100%;
      }
    </style>
  </head>
  <body>

  <table>
      <tr>
        <th>Name</th>
        <th>Email</th>
        <th>Country</th>
        <th>Gender</th>
        <th>Phone</th>
        <th>Message</th>
      </tr>
    
    <?php
        require_once "database.php";

        try {

            $stmt = $pdo->prepare($sql);
            $stmt->bindParam(':gender', $gender);
            $stmt->bindParam(':name', $name);
            $stmt->bindParam(':message', $message);
            
            $stmt->execute();

            $data = $stmt->fetchAll(PDO::FETCH_ASSOC);
            
            if ($data) {
                foreach ($data as $entry) {
                    echo "<tr>";
                    echo "<td>".$entry['name']."</td>";
                    echo "<td>".$entry['email']."</td>";
                    echo "<td>".$entry['country']."</td>";
                    echo "<td>".$entry['gender']."</td>";
                    echo "<td>".$entry['phone']."</td>";
                    echo "<td>".$entry['message']."</td>";
                    echo "</tr>";
                }
            }
    
        } catch(PDOException $e) {
            echo "Connection failed: " . $e->getMessage();
        }
    ?>

  </body>
</html>