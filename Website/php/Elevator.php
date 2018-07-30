<?php
  //ZH PHP to process elevator request, send to database
	session_start(); //starts a session and creates a session variable
$out = NULL;
	//$name = $_POST["Username"];
	//$password = $_POST["Password"];

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
		} else if (isset($_POST['Halt'])) {
			echo "Halt";
			$out = 0;
		} else {
			echo "Button Error";
		}
	}

if ($out != NULL)
{
	//connection to database starts
	$db = new PDO(
		'mysql:host=127.0.0.1:3306;dbname=project', //Data Source Name
		'ESE',					  //Username
		'ese'					  //Password
	);

		//$query = 'SELECT elevatorNetwork, password FROM users WHERE user = :user AND  password = :password'; // Formatted Query, parameters identified by ':'
		$query = 'UPDATE status (requestedFloor) VALUES (:out);';
		$statement = $db->prepare($query);
		$params = [
		'out' => $out    // Array containing the data
	];
	$result = $statement->execute($params); // execute is the method for inserting the formatted array into the database

	echo "<br/>Wrote to database";
}
?>
