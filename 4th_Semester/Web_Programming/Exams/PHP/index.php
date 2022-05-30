<?php
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_NAME', 'ics20009');

$dbErr = "";
 
/* Attempt to connect to MySQL database */
try{
    $pdo = new PDO("mysql:host=".DB_SERVER, DB_USERNAME, DB_PASSWORD);
    // Set the PDO error mode to exception
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Create Database
    $sql = "CREATE DATABASE IF NOT EXISTS ".DB_NAME;
    $pdo->query($sql);

    // Use Database
    $pdo->query("use ".DB_NAME);

    // Create users Table
    $sql = "CREATE TABLE IF NOT EXISTS ics20009 (
        id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
        email VARCHAR(50) NOT NULL UNIQUE,
        telephone VARCHAR(11) NOT NULL
    )";
    $pdo->query($sql);

} catch(PDOException $e){
    $dbErr = $e->getMessage();
    die("ERROR: Could not connect. " . $e->getMessage());
}
?>
<!DOCTYPE html>
<html lang="en"></html>
<html>
    <head>
        <meta charset="utf-8">
        <title>ics20009</title>
        <link rel="stylesheet" href="style.css">
    </head>
    <body>

        <header>
            <h1>Γεώργιος Ματζιάρας ics20009</h1>
            <nav>
                <a href="index.php"> Αρχική</a>
                <a href="insert.php"> Καταχώριση</a>
                <a href="select.php"> Επιλογή</a>
            </nav>
        </header>

        <h3><?php if ($dbErr == "") echo "Database Created Successfully"; else echo $dbErr?></h3>

    <script src="app.js" defer></script>
    <noscript>You need to enable JavaScript to view the full site.</noscript>
  </body>
</html>