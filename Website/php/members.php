<?php
  //member.php
	session_start(); //starts a session and creates a session variable

if (isset($_SESSION['logged_in'])){
  echo "Welcome, " . $_SESSION['sUser'] . "!</br>";
  //Members only content
  echo "<p>Wrapper for Elevator status wip</p>";
  echo "Click to <a href='logout.php'>Logout</a>";
  echo "Click here to look at the debugg/log page <a href='debugger.php'>Debuger</a>";
  
  
	//require '../html/Elevator.html';
	require 'ElevatorContainer.php';
  
  
}

else{
  echo "<p>You must be logged in!</p>";
}

?>
