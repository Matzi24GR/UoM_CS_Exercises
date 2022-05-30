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
            $sql = 'SELECT * FROM data';

            $data = $pdo->query($sql)->fetchAll(PDO::FETCH_ASSOC);


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