<?php
  //ZH PHP to process elevator request, send to database
	session_start(); //starts a session and creates a session variable

	//$name = $_POST["Username"]; 
	//$password = $_POST["Password"]; 
	
	$out = 0;
	
	//input processing starts
	if ($_SERVER['REQUEST_METHOD'] === 'POST') {
		//something posted
		echo "button pressed";
		echo "<br/>";
		if (isset($_POST['Floor1'])) {
			echo "Floor1";
			$out = 1;
		} else if (isset($_POST['Floor2'])) {
			echo "Floor2";
			$out = 2;
		} else if (isset($_POST['Floor3'])) {
			echo "Floor3";
			$out = 3;
		} else {
			//assume halt
			echo "Halt";
		}
	}
	
	//connection to database starts
	$db = new PDO(
		'mysql:host=127.0.0.1;dbname=elevator', //Data Source Name
		'root',					  //Username
		''					  //Password
	);

		//$query = 'SELECT elevatorNetwork, password FROM users WHERE user = :user AND  password = :password'; // Formatted Query, parameters identified by ':'
		$query = 'INSERT INTO elevatorNetwork (requestedFloor) VALUES (:out);';
		$statement = $db->prepare($query);	
		$params = [
		'out' => $out    // Array containing the data
	];
	$result = $statement->execute($params); // execute is the method for inserting the formatted array into the database	
	
	echo "<br/>Wrote to database";

?>
