<?php
$db = new PDO(
	'mysql:host=127.0.0.1;dbname=elevator', //Data Source Name
	'root',					  //Username
	''					  //Password
);
//Return arrays with keys that are the name of the feilds
$db->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
/*
$query = 'SELECT * FROM elevatorNetwork WHERE node ID = :nodeID';

$statement = $db->prepare($query); // Object created from query that contains methods for executing (inserting) and fetching data
$statement->bindValue('nodeID', 1);

$result = $statement->execute();
$rows = $statement->fetchAll();
var_dump($rows);
*/

date_default_timezone_set("America/Toronto");


$Flag = 0;

echo "Current time is: " . date("Y-m-d G:i:s T") . "<br /><br />";

$Date = date("Y-m-d");
$Time = date("G:i:s");
$nodeID = 6;
$Status = 1;
$CurrentFloor = 2;
$RequestedFloor = 3;
$OtherInfo = 'Elevator Car';



$query = 'INSERT INTO elevatorNetwork (date,time,nodeID, status, currentFLoor,requestedFloor, otherInfo)
	  VALUES (:date,:time,:nodeID, :status,:currentFloor,:requestedFloor,:otherInfo)'; // Formatted Query, parameters identified by ':'

foreach ($rows as $row)
{
	if($nodeID == 'nodeID')
	{
		$db->query('DELETE FROM elevatorNetwork WHERE nodeID = :nodeID'); 
	}

}



$statement = $db->prepare($query);
$params = [
	'date' => $Date,    // Array containing the data
	'time' => $Time,
	'nodeID' => $nodeID,
	'status' => $Status,
	'currentFloor' => $CurrentFloor,
	'requestedFloor' => $RequestedFloor,
	'otherInfo' => $OtherInfo
];

$result = $statement->execute($params); // execute is the method for inserting the formatted array into the database
var_dump($result); // true of sucessfully added to database
echo "<br />";

$rows = $db->query('SELECT * FROM elevatorNetwork ORDER BY nodeID');
foreach ($rows as $row) {
	var_dump($row);
	echo"<br />";
	echo"<br />";
}

?>
