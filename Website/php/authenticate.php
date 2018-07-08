<?php
  //authenticate.php (modified to use sessions)
	session_start(); //starts a session and creates a session variable

	$name = $_POST["username"]; 
	$password = $_POST["password"]; 

	$mysqli = new mysqli('localhost', 'admin', 'password', 'elevator');
	
	$result1 = $mysqli->query("SELECT username, password FROM users WHERE username = '".$name."' AND  password = '".$password."'");

	if(mysqli_num_rows($result1) > 0 )
	{ 
		$_SESSION["logged_in"] = true; 
		$_SESSION["naam"] = $name; 
		echo 'Login successful';
	}
	else
	{
		echo 'The username or password are incorrect!';
	}


?>
