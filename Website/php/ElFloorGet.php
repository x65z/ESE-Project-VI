<?php

	session_start(); //starts a session and creates a session variable

	$out = $_POST["pval"];

	$name = $_POST["Username"];
	$password = $_POST["Password"];
	$out = intval($_GET['q']);
	//connection to database starts
	$db = new PDO(
		'mysql:host=127.0.0.1;dbname=project', //Data Source Name
		'ESE',					   //Username
		'ese'					   //Password
	);


		$query = $db->query('SELECT currentFloor FROM status WHERE id = 1');

	    $floor = $query->fetch(PDO::FETCH_ASSOC);

	    echo '<h2>The car is now on floor: '.$floor['currentFloor'].'</h2>';
	?>
