<?php

function update_elevatorNetwork(int $node_ID, int $new_status = 1): void{
	$db = new PDO(
		'mysql:host=127.0.0.1;dbname=project', //Data Source Name
		'ESE',					   //Username
		'ese'					   //Password
	);
	//Return arrays with keys that are the name of the feilds
	$db->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
	$db->beginTransaction();			//START TRANSACTION

	try{
		//Change elevatorNetwork
		$query = 	'UPDATE status
				 SET status = :stat
				 WHERE nodeID = :id';
		$statement = $db->prepare($query);
		$statement->bindValue('stat', $new_status);
		$statement->bindValue('id', $node_ID);
		if (!$statement->execute()){
			throw new Exception('Error - exception thrown in try block');				
		}
		$db->commit();			//COMMIT (if no exception in try block)
		}
		catch (Exception $e)	
		{	
			echo "FAILED";
			$db->rollBack();		//ROLL BACK(if exception in try block)
		}
	}
update_elevatorNetwork(2, 20);			//Change status of nodeID=2 to 15 - OK
update_elevatorNetwork(100,5);			//Should throw an exception and ROLL BACK


//Show changes to elevatorNetwork
$db = new PDO(
	'mysql:host=127.0.0.1;dbname=project', //Data Source Name
	'ESE',					   //Username
	'ese'					   //Password
);
$db->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
$query2 = 'SELECT * FROM status';
$rows = $db->query($query2);
foreach ($rows as $row) 
{
	var_dump($row);
	echo "<br /><br />";
}

?>
