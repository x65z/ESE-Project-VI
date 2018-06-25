<?php
  //member.php
	session_start(); //starts a session and creates a session variable

if (isset($_SESSION['username']){
  echo "Welcome, " . $_SESSION['username'] . "!</br>";
  //Members only content
  echo "<p>members only content - for your eyes only.</p>"

  echo "Click to <a href='logout.php'>Logout</a>";
}

else{
  echo "<p>You must be logged in!</p>";
}

?>
