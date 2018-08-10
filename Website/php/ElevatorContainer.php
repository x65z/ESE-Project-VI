<?php
	//echo "test";
?>

<html lang="en">

<head>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script> 
	<Title>Elevator Information</title>
	<link rel="stylesheet" href="../css/elevator.css">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>

<div class="mainbox">

    <div class="floor1div">
      <input name="Floor1" id="f1" class="button1" type="submit" value="Floor 1" />
    </div>

		<div class="nfloor1">
	  	<img src="floorback.PNG.png" alt="something" width="100" height="100">

	  </div>


    <div class="floor2div">
      <input name="Floor2" id="f2" class="button1" type="submit" value="Floor 2" />
    </div>


		<div class="nfloor2">
      <img src="floorback.PNG.png" alt="something" width="100" height="100">

    </div>


    <div class="floor3div">
      <input name="Floor3" id="f3" class="button1" type="submit" value="Floor 3" />
    </div>


		<div class="nfloor3">
			<img src="floorback.PNG.png" alt="something" width="100" height="100">

		</div>


    <div class="haltdiv">
      <input name="Halt" id="ht" class="button2" type="submit" value="Halt" />
    </div>




</div>

<body>

	<script src="../js/elevatorSubmit.js"></script>
  <script src="../js/elevatorPoll.js"></script>

</body>

</html>
