<?php
  //PHP to process elevator request, send to database
	session_start(); //starts a session and creates a session variable

	$out = $_POST["pval"];

	$db = new PDO(
		'mysql:host=127.0.0.1;dbname=project', //Data Source Name
		'ESE',					   //Username
		'ese'					   //Password
	);

		$query = 'UPDATE status SET requestedFloor = :out WHERE id =1';


		$statement = $db->prepare($query);
		$params = [
		'out' => $out    // Array containing the data
	];
	$result = $statement->execute($params); // execute is the method for inserting the formatted array into the database

	echo "<br/>Wrote to database";

?>
