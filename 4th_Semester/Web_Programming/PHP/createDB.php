<!DOCTYPE html>
<html lang="en"></html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Create DB</title>
    <link rel="stylesheet" href="style.css">
  </head>
  <body>
    
  <?php
    require_once "database.php";

    try {
        $sql = "CREATE TABLE IF NOT EXISTS data (
            id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
            userId INT,
            name VARCHAR(30) NOT NULL,
            email VARCHAR(30) NOT NULL,
            country VARCHAR(30) NOT NULL,
            gender VARCHAR(30) NOT NULL,
            phone VARCHAR(12),
            message MEDIUMTEXT,
            FOREIGN KEY (userId) REFERENCES users(id)
        )";
        $pdo->query($sql);
        echo "<br>Table created successfully";
        
        header("location: admin.php");

    } catch(PDOException $e) {
       echo "Connection failed: " . $e->getMessage();
    }
    ?>

  </body>
</html>