<?php
define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');
define('DB_NAME', 'ics20009_DB');
 
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
    $sql = "CREATE TABLE IF NOT EXISTS users (
        id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
        username VARCHAR(50) NOT NULL UNIQUE,
        password VARCHAR(255) NOT NULL,
        isAdmin BOOLEAN NOT NULL,
        created_at DATETIME DEFAULT CURRENT_TIMESTAMP
    )";
    $pdo->query($sql);

    $sql = 'SELECT COUNT(*) FROM users WHERE isAdmin=TRUE';
    $adminCount = $pdo->query($sql)->fetchColumn();

    if ($adminCount == 0) {
        // Create Admin Users
        $sql = "INSERT INTO users (username, password, isAdmin) VALUES (:username, :password, true)";
         
        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":username", $param_username);
            $stmt->bindParam(":password", $param_password);
            
            // Set parameters
            $param_username = "admin";
            $param_password = password_hash("ics20009", PASSWORD_DEFAULT);
            
            $stmt->execute();
        }
        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":username", $param_username);
            $stmt->bindParam(":password", $param_password);
            
            // Set parameters
            $param_username = "root";
            $param_password = password_hash("ics20009", PASSWORD_DEFAULT);
            
            $stmt->execute();
        }
    }


} catch(PDOException $e){
    die("ERROR: Could not connect. " . $e->getMessage());
}
?>