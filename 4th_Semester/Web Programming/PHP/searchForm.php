<?php
  // Initialize the session
  session_start();
  
  // Check if the user is logged in, if not then redirect him to login page
  if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
      header("location: login.php");
      exit;
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
      <h2>Enter your search filters <br> (leave empty to match any)</h2>
      <form action="<?php echo htmlspecialchars("./searchDB.php");?>" method="post">
        <table>
            <tr>
              <td>Name:</td>
              <td> <input type="text" name="name"></input> </td>
            </tr>
            <tr>
              <td>Gender:</td>
              <td>
              <input type="radio" id="male" name="gender" value="male">       
              <label for="male">Male</label>
              <input type="radio" id="female" name="gender" value="female">
              <label for="female">Female</label>
              <input type="radio" id="other" name="gender" value="other">
              <label for="other">Other</label>
              </td>
            </tr>
            <tr>
              <td>Message:</td>
              <td> <textarea name="message"></textarea></td>
            </tr>
          </table>
          <button>Search</button>
        </form>
    </div>

  </body>
</html>