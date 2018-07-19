<?php
  //ZH PHP to process elevator request, send to database
	session_start(); //starts a session and creates a session variable

	//$name = $_POST["Username"]; 
	//$password = $_POST["Password"]; 
	
	if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    //something posted
	echo "button pressed";
	echo "<br/>";
    if (isset($_POST['Floor1'])) {
        echo "Floor1";
    } else if (isset($_POST['Floor2'])) {
		echo "Floor2";
	} else if (isset($_POST['Floor3'])) {
		echo "Floor3";
	} else {
        //assume halt
		echo "Halt";
    }
}
/*
	$db = new PDO(
		'mysql:host=127.0.0.1;dbname=elevator', //Data Source Name
		'root',					  //Username
		''					  //Password
	);

		$query = 'SELECT user, password FROM users WHERE user = :user AND  password = :password'; // Formatted Query, parameters identified by ':'
		$statement = $db->prepare($query);	
		$params = [
		'user' => $name,    // Array containing the data
		'password' => $password
	];
	$result = $statement->execute($params); // execute is the method for inserting the formatted array into the database
	$count = $statement->rowCount();
	//$mysqli = new mysqli('localhost', 'admin', 'password', 'elevator');
	
	 //mysqli_select_db($mysqli,'elevator');
	
	//$result1 = $mysqli->query("SELECT user, password FROM users WHERE user = '".$name."' AND  password = '".$password."'");
	
	if($count > 0)
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

*/
?>
