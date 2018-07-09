<?php
  //authenticate.php (modified to use sessions)
	session_start(); //starts a session and creates a session variable

	$name = $_POST["Username"]; 
	$password = $_POST["Password"]; 


	$mysqli = new mysqli('localhost', 'admin', 'password', 'elevator');
	//if($mysqli){
	//	echo 'connected';   
    //}
    //else {
	//	echo 'Failed:'.mysqli_error();  
    //}
	
	 mysqli_select_db($mysqli,'elevator');
	
	$result1 = $mysqli->query("SELECT user FROM users WHERE user = '".$name."'");
	
	if(mysqli_num_rows($result1) > 0 )
	{ 	
		echo "Username already exists, try again: <a href='../html/Signup.html'>here</a>.";
	}
	else
	{
		//echo 'Username Valid.';
		$result1 = $mysqli->query("INSERT INTO users (user, password) VALUES ('".$name."', '".$password."');");
		echo "Account created, login: <a href='../html/Login.html'>here</a>.";
		//echo $result1 ? 'true' : 'false';
	}


?>
