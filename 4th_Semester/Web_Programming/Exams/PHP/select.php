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
        <th>ID</th>
        <th>Email</th>
        <th>Phone</th>
      </tr>
    
    <?php
        require_once "index.php";

        try {
            $sql = 'SELECT * FROM ics20009 WHERE email LIKE "%9@uom.edu.gr"';

            $data = $pdo->query($sql)->fetchAll(PDO::FETCH_ASSOC);


            if ($data) {
              foreach ($data as $entry) {
                echo "<tr>";
                echo "<td>".$entry['id']."</td>";
                echo "<td>".$entry['email']."</td>";
                echo "<td>".$entry['telephone']."</td>";
                echo "</tr>";
              }
            }

        } catch(PDOException $e) {
        echo "Connection failed: " . $e->getMessage();
        }
    ?>

  </body>
</html>