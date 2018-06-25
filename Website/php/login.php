<?php
$submitted = !empty($_POST);
$username = $_POST['username'];
$password = $_post['password'];

echo "<p>Form submitted sucessfully (1 for true): $submitted </p>"
echo "<p>Username received: $username </p>"
echo "<p>Password received: $password </p>"

?>
<!DOCTYPE html>
<html>
	<head><title>Form Handler Page</title></head>
	<body>
		<p>Form submitted? <?php echo (int) $submitted; ?> </p>
		<p>Your login info is</p>
		<ul>
			<li><b>username</b>: <?php echo $_POST['username']; ?></li>
			<li><b>password</b>: <?php echo $_POST['password']; ?></li>
		</ul>
	</body>
</html>
