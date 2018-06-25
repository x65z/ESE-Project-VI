<?php
  //authenticate.php (modified to use sessions)
	session_start(); //starts a session and creates a session variable
  $username = $_POST['username'];
  $password = $_POST['password'];

if ($username&&$password){
  $_SESSION['username']=$username;
  echo "<p>Congragulations! You are logging into the site.</p>"
  echo "<p>Please click <a href=\"member.php\">here</a> to be taken to our members only page</p>"
}

else{
  echo "<p>Please enter a username and password</p>";
}

?>
