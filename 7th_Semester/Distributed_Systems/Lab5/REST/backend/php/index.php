<?php
require_once "./database.php";

$uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
$uri = explode( '/', $uri );

if (isset($uri[1]) && $uri[1] == 'users') {
    $output = $pdo->query('SELECT * FROM users')->fetchAll(PDO::FETCH_ASSOC);
    header('Content-type: application/json');
    echo json_encode(['users'=>$output]);
    exit();
}

// LOGIN
if (isset($uri[1]) && $uri[1] == 'login') {

    if($_SERVER["REQUEST_METHOD"] == "POST"){
        $username = trim($_POST["username"]);
        $password = trim($_POST["password"]);

        if (empty($username) || empty($password)) {
            echo "FAILED";
            exit();
        }

        // Prepare a select statement
        $sql = "SELECT username, password FROM users WHERE username = :username";

        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":username", $param_username, PDO::PARAM_STR);

            // Set parameters
            $param_username = trim($_POST["username"]);

            // Attempt to execute the prepared statement
            if($stmt->execute()){
                // Check if username exists, if yes then verify password
                if($stmt->rowCount() == 1){
                    if($row = $stmt->fetch()){
                        $username = $row["username"];
                        $hashed_password = $row["password"];
                        if(password_verify($password, $hashed_password)){
                            // Store data in session variables
                            $_SESSION["loggedin"] = true;
                            $_SESSION["username"] = $username;

                        } else{
                            // Password is not valid, display a generic error message
                            echo "INVALID";
                            exit();
                        }
                    }
                } else{
                    // Username doesn't exist, display a generic error message
                    echo "INVALID";
                    exit();
                }
            } else{
                echo "Oops! Something went wrong. Please try again later.";
                exit();
            }

            // Close statement
            unset($stmt);
            }
    } else {
        echo "NOT POST REQUEST";
    }
}

if (isset($uri[1]) && $uri[1] == 'check') {
    if($_SERVER["REQUEST_METHOD"] == "POST"){

        $username = trim($_POST["username"]);

        if (empty($username)) {
            echo "FAILED";
            exit();
        }

        $sql = "SELECT balance FROM users WHERE username = :username";

        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":username", $param_username, PDO::PARAM_STR);

            // Attempt to execute the prepared statement
            if($stmt->execute()){
                if($row = $stmt->fetch()) {
                    $balance = $row["balance"];
                    echo $balance;
                };
                exit();
            } else{
                echo "FAILED";
                exit();
            }

            // Close statement
            unset($stmt);
        }

        // Close connection
        unset($pdo);
    } else {
        echo "NOT POST REQUEST";
    }
}

if (isset($uri[1]) && $uri[1] == 'withdraw') {
    if($_SERVER["REQUEST_METHOD"] == "POST"){

        $username = trim($_POST["username"]);
        $amount = trim($_POST["amount"]);

        if (empty($username) || empty($amount) || $amount <0) {
            echo "FAILED";
            exit();
        }

        $sql = "SELECT balance FROM users WHERE username = :username";

        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":username", $param_username, PDO::PARAM_STR);

            // Attempt to execute the prepared statement
            if($stmt->execute()){
                if($row = $stmt->fetch()) {
                    $balance = $row["balance"];
                    if ($amount > $balance) {
                        echo "Failed";
                    } else {
                        $sql = "UPDATE users SET balance = :balance WHERE username = :username";
                        if ($stmt = $pdo->prepare($sql)) {
                            $stmt->bindParam(":username", $param_username, PDO::PARAM_STR);
                            $balance2 = $balance-$amount;
                            $stmt->bindParam(":balance", $balance2, PDO::PARAM_STR);
                            $stmt->execute();
                        }
                    }
                };
                exit();
            } else{
                echo "FAILED";
                exit();
            }

            // Close statement
            unset($stmt);
        }

        // Close connection
        unset($pdo);
    } else {
        echo "NOT POST REQUEST";
    }
}

if (isset($uri[1]) && $uri[1] == 'deposit') {
    if($_SERVER["REQUEST_METHOD"] == "POST"){

        $username = trim($_POST["username"]);
        $amount = trim($_POST["amount"]);

        if (empty($username) || empty($amount) || $amount <0) {
            echo "FAILED";
            exit();
        }

        $sql = "SELECT balance FROM users WHERE username = :username";

        if($stmt = $pdo->prepare($sql)){
            // Bind variables to the prepared statement as parameters
            $stmt->bindParam(":username", $param_username, PDO::PARAM_STR);

            // Attempt to execute the prepared statement
            if($stmt->execute()){
                if($row = $stmt->fetch()) {
                    $balance = $row["balance"];
                    $sql = "UPDATE users SET balance = :balance WHERE username = :username";
                    if ($stmt = $pdo->prepare($sql)) {
                        $stmt->bindParam(":username", $param_username, PDO::PARAM_STR);
                        $balance2 = $balance+$amount;
                        $stmt->bindParam(":balance", $balance2, PDO::PARAM_STR);
                        $stmt->execute();
                    }
                };
                exit();
            } else{
                echo "FAILED";
                exit();
            }

            // Close statement
            unset($stmt);
        }

        // Close connection
        unset($pdo);
    } else {
        echo "NOT POST REQUEST";
    }
}

?>
