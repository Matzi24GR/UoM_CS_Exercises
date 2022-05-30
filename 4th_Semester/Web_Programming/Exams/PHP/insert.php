<?php

  require_once "index.php";

  $formErr = "";
  $emailErr = $countryErr = $phoneErr = "";
  $email = $country = $telephone = "";

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
    
    if (empty($_POST["telephone"])) {
      $phoneErr = "A phone number is required";
      $telephone = test_input($_POST["telephone"]);
    } else {
      $telephone = test_input($_POST["telephone"]);
    }

    if (empty($emailErr) && empty($countryErr) && empty($phoneErr)) {
      try {
        $servername = "localhost";
        $username = "root";
        $password = "";

        $stmt = $pdo->prepare("INSERT INTO ics20009 (email, telephone) VALUES (:email, :telephone)");
        $stmt->bindParam(':email', $email);
        $stmt->bindParam(':telephone', $telephone);

        $stmt->execute();

      } catch(PDOException $e) {
        //echo "Connection failed: " . $e->getMessage();
        $formErr = "Form is disabled. Try again later";
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

      <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">

        <table>
          <tr>
            <td>Email: <span class="error">* <br><?php echo $emailErr;?></span></td>
            <td> <input type="text" name="email" value="<?php echo $email;?>"> </td>
          </tr>
          <tr>
            <td>Phone: <span class="error"><br><?php echo $phoneErr;?></span> </td></td>
            <td> <input type="tel" id="telephone" name="telephone" value="<?php echo $telephone;?>"> </td>
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
        </table>

        <button>Submit</button>
        <input type="reset">
        <br>
        <?php echo $formErr;?></span><br>
      </form>  
  </div>

  

  </body>
</html>