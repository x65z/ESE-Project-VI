<?php
  //authenticate.php (modified to use sessions)
	session_start(); //starts a session and creates a session variable
  $username = $_POST['username'];
  $password = $_POST['password'];

if (($username=="TESTING")&&($password=="testing")){
  $_SESSION['username']=$username;
  echo "<p>Congragulations! You are logging into the site.</p>";
  echo "<p>Please click <a href=\"members.php\">here</a> to be taken to our members only page</p>";
}

else{
  echo "<p>Invalid Username or Password</p>";
  echo "Click <a href='../html/Login.html'>here</a> to login again";

}

?>
