<?php
//echo "test";
?>

<html lang="en">

<head>
  <Title>Elevator Information</title>
  <link rel="stylesheet" href="../css/elevator.css">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>

<div class="mainbox">
  <form action="../php/Elevator.php" method="post" id="Elev">
    <div class="floor1div">
      <input name="Floor1" class="button1" type="submit" value="Floor 1" />
    </div>



    <div class="floor2div">
      <input name="Floor2" class="button1" type="submit" value="Floor 2" />
    </div>




    <div class="floor3div">
      <input name="Floor3" class="button1" type="submit" value="Floor 3" />
    </div>



    <div class="haltdiv">
      <input name="Halt" class="button2" type="submit" value="Halt" />
    </div>


    <div class="floor1div">
      <img scr="Floor1notif.png" alt="something">
    </div>

    <div class="floor1div">
      <img scr="Floor1notif.png" alt="something">
    </div>

    <div class="floor1div">
      <img scr="Floor1notif.png" alt="something">
    </div>


  </form>
</div>

<body>
</body>

</html>