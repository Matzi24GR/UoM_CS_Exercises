<?php

  require_once "database.php";
  // Initialize the session
  session_start();
  
  // Check if the user is logged in, if not then redirect him to login page
  if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
      header("location: login.php");
      exit;
  }

  $formErr = "";
  $nameErr = $emailErr = $genderErr = $countryErr = $phoneErr = "";
  $name = $email = $gender = $country = $phone = $message = "";

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["name"])) {
      $nameErr = "name is required";
    } else {
      $name = test_input($_POST["name"]);
    }

    if (empty($_POST["email"])) {
      $emailErr = "email is required";
    } else if(filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)){
      $email = test_input($_POST["email"]);
    } else {
      $emailErr = "Invalid Email";
    }

    if (empty($_POST["country"])) {
      $countryErr = "A country is required";
    } else {
      $country = test_input($_POST["country"]);
    }

    if (empty($_POST["gender"])) {
      $genderErr = "Choose an option";
    } else {
      $gender = test_input($_POST["gender"]);
    }

    
    if (empty($_POST["phone"])) {
      $phone = test_input($_POST["phone"]);
    } else if (preg_match("/\d{10}/", test_input($_POST["phone"]))==1) {
      $phone = test_input($_POST["phone"]);
    } else {
      $phoneErr = "Invalid phone number";
    }
    $message = test_input($_POST["message"]);

    if (empty($nameErr) && empty($emailErr) && empty($genderErr) && empty($countryErr) && empty($phoneErr)) {
      try {
        $servername = "localhost";
        $username = "root";
        $password = "";

        $stmt = $pdo->prepare("INSERT INTO data (userId, name, email, country, gender, phone, message) VALUES (:userId, :name, :email, :country, :gender, :phone, :message)");
        $stmt->bindParam(':userId', $_SESSION["id"]);
        $stmt->bindParam(':name', $name);
        $stmt->bindParam(':email', $email);
        $stmt->bindParam(':country', $country);
        $stmt->bindParam(':gender', $gender);
        $stmt->bindParam(':phone', $phone);
        $stmt->bindParam(':message', $message);

        $stmt->execute();

      } catch(PDOException $e) {
        //echo "Connection failed: " . $e->getMessage();
        $formErr = "Form is disabled. Try again later";
      }
    }

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
    <meta charset="UTF-8">
    <title>Welcome</title>
    <link rel="stylesheet" href="style.css">
</head>
  <body>

  <div class="card">
    <h2>Hi, <b><?php echo htmlspecialchars($_SESSION["username"]); ?></b>. Welcome to our online form.</h2>
      <p>
          <a href="logout.php">Sign Out of Your Account</a>
      </p>
      <hr>

      <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">

        <table>
          <tr>
            <td>Name: <span class="error">* <br><?php echo $nameErr;?></span> </td>
            <td> <input type="text" name="name" value="<?php echo $name;?>"> </td>
          </tr>
          <tr>
            <td>Email: <span class="error">* <br><?php echo $emailErr;?></span></td>
            <td> <input type="text" name="email" value="<?php echo $email;?>"> </td>
          </tr>
          <tr>
            <td>Phone: <span class="error"><br><?php echo $phoneErr;?></span> </td></td>
            <td> <input type="tel" id="phone" name="phone" value="<?php echo $phone;?>"> </td>
          </tr>
          <tr>
            <td>Country:</td>
            <td> <select name="country" id="country"><span class="error">* <?php echo $countryErr;?></span><br>
              <option value="greece" <?php echo (isset($_POST['country']) && $_POST['country'] === 'greece') ? 'selected' : ''; ?> >Greece</option>
              <option value="usa" <?php echo (isset($_POST['country']) && $_POST['country'] === 'usa') ? 'selected' : ''; ?> >U.S.A</option>
              <option value="canada" <?php echo (isset($_POST['country']) && $_POST['country'] === 'canada') ? 'selected' : ''; ?> >Canada</option>
              <option value="uk" <?php echo (isset($_POST['country']) && $_POST['country'] === 'uk') ? 'selected' : ''; ?> >U.K.</option>
              <option value="germany" <?php echo (isset($_POST['country']) && $_POST['country'] === 'germany') ? 'selected' : ''; ?> >Germany</option>
              <option value="france" <?php echo (isset($_POST['country']) && $_POST['country'] === 'france') ? 'selected' : ''; ?> >France</option>
              <option value="spain" <?php echo (isset($_POST['country']) && $_POST['country'] === 'spain') ? 'selected' : ''; ?> >Spain</option>
              <option value="italy" <?php echo (isset($_POST['country']) && $_POST['country'] === 'italy') ? 'selected' : ''; ?> >Italy</option>
            </select> </td>
          </tr>
          <tr>
            <td>Gender: <span class="error">* <br><?php echo $genderErr;?></span> </td>
            <td> <input type="radio" id="male" name="gender" value="male" <?php echo (isset($_POST['gender']) && $_POST['gender'] === 'male') ? 'checked' : ''; ?> >
            <label for="male">Male</label><br>
            <input type="radio" id="female" name="gender" value="female" <?php echo (isset($_POST['gender']) && $_POST['gender'] === 'female') ? 'checked' : ''; ?> >
            <label for="female">Female</label><br>
            <input type="radio" id="other" name="gender" value="other" <?php echo (isset($_POST['gender']) && $_POST['gender'] === 'other') ? 'checked' : ''; ?> >
            <label for="other">Other</label> </td>
          </tr>
          <tr>
            <td>Message:</td>
            <td> <textarea name="message"><?php echo $message;?></textarea> </td>
          </tr>
        </table>

        <button>Submit</button>
        <input type="reset">
        <br>
        <?php echo $formErr;?></span><br>
      </form>  
  </div>

  

  </body>
</html>