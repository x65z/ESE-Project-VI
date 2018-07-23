<?php
  //ZH PHP to process elevator request, send to database
	session_start(); //starts a session and creates a session variable

	$out = $_POST["pval"]; 
	
	if ($out == 0)
	{
		$out = "Requested Stop";
	}
	elseif ($out == 1)
	{
		$out = "Requested Floor 1";
	}
	elseif ($out == 2)
	{
		$out = "Requested Floor 2";
	}
	elseif ($out == 3)
	{
		$out = "Requested Floor 3";
	}
	
	
	//$name = $_POST["Username"]; 
	//$password = $_POST["Password"]; 
	//$out = intval($_GET['q']);
	//connection to database starts
	$db = new PDO(
		'mysql:host=127.0.0.1;dbname=project', //Data Source Name
		'ESE',					   //Username
		'ese'					   //Password
	);

	 // Formatted Query, parameters identified by ':'
		
		$query = "INSERT INTO debugLog (timestamp, nodeID, node, message) VALUES (NOW(),'N/A', 'Website' , ':out')";

		
		$statement = $db->prepare($query);	
		$params = [
		'out' => $out    // Array containing the data
	];
	$result = $statement->execute($params); // execute is the method for inserting the formatted array into the database	
	
	echo "<br/>Wrote to database";

?>
