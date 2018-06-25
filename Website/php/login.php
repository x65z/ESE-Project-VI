<?php


	$submitted = !empty($_POST);

if ($submitted == 1){
	$username = $_POST['username'];
	$password = $_POST['password'];
	setcookie('username', $username);
	setcookie('password', $password);
}

else{ 																//after first login get, login info from $_COOKIE array
	$username = $_COOKIE ['username'];
	$password = $_COOKIE ['password'];
}

	echo "<p>Form submitted sucessfully (1 for true): $submitted </p>";
	echo "<p>Username recieved: $username </p>";
	echo "<p>Password recieved: $password </p>";

?>