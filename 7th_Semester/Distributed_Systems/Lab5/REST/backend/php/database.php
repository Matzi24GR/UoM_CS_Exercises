<?php
define('DB_HOST', $_ENV["DB_HOST"]);
define('DB_NAME', $_ENV["DB_NAME"]);
define('DB_USERNAME', $_ENV["DB_USERNAME"]);
define('DB_PASSWORD', $_ENV["DB_PASSWORD"]);
 
/* Attempt to connect to MySQL database */
try{
    $pdo = new PDO("mysql:host=".DB_HOST, DB_USERNAME, DB_PASSWORD);
    // Set the PDO error mode to exception
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Create Database
    $sql = "CREATE DATABASE IF NOT EXISTS ".DB_NAME;
    $pdo->query($sql);

    // Use Database
    $pdo->query("use ".DB_NAME);

    // Create users Table
    $sql = "CREATE TABLE IF NOT EXISTS users (
        username VARCHAR(50) NOT NULL PRIMARY KEY,
        password VARCHAR(255) NOT NULL,
        balance DOUBLE NOT NULL,
        created_at DATETIME DEFAULT CURRENT_TIMESTAMP
    )";
    $pdo->query($sql);
    
    // Create Users
    $sql = "INSERT IGNORE INTO users (username, password, balance) VALUES (:username, :password, :balance)";

    if($stmt = $pdo->prepare($sql)){
        // Bind variables to the prepared statement as parameters
        $stmt->bindParam(":username", $param_username);
        $stmt->bindParam(":password", $param_password);
        $stmt->bindParam(":balance", $param_balance);

        // Set parameters
        $param_username = "Deliverer3334";
        $param_password = password_hash("Y4B&JLkb$6fj", PASSWORD_DEFAULT);
        $param_balance = 2136.32;

        $stmt->execute();

        $param_username = "Partridge6105";
        $param_password = password_hash("xzjUj@M5PqY#", PASSWORD_DEFAULT);
        $param_balance = 8420.12;

        $stmt->execute();

        $param_username = "Truffle8604";
        $param_password = password_hash("8vo5c9&nFx\$q", PASSWORD_DEFAULT);
        $param_balance = 320.87;

        $stmt->execute();

        $param_username = "admin";
        $param_password = password_hash("admin", PASSWORD_DEFAULT);
        $param_balance = 320.87;

        $stmt->execute();
    }

} catch(PDOException $e){
    die("ERROR: Could not connect. " . $e->getMessage());
}

?>
