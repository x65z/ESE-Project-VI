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
	
	$result1 = $mysqli->query("SELECT user, password FROM users WHERE user = '".$name."' AND  password = '".$password."'");
	
	if(mysqli_num_rows($result1) > 0 )
	{ 
		$_SESSION["logged_in"] = true; 
		$_SESSION["name1"] = $name; 
		
		echo 'Login successful';
	}
	else
	{
		echo 'The username or password are incorrect!';
		//echo $result1 ? 'true' : 'false';
	}


?>
