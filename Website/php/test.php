<?php

	echo "My first PHP script!";
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

	echo "<p>Form submitted successfully (1 for true): $submitted </p>";
	echo "<p>Username received: $username </p>";
	echo "<p>Password received: $password </p>";

?>
