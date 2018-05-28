<?php
$submitted = !empty($_POST);
?>
<!DOCTYPE html>
<html>
	<head><title>Form Handler Page</title></head>
	<body>
		<p>Form submitted? <?php echo (int) $submitted; ?> </p>
		<p>Your login info is</p>
		<ul>
			<li><b>firstname</b>: <?php echo $_POST['firstname']; ?></li>
			<li><b>lastname</b>: <?php echo $_POST['lastname']; ?></li>
			<li><b>email</b>: <?php echo $_POST['email']; ?></li>
			<li><b>website</b>: <?php echo $_POST['url']; ?></li>
			<li><b>birthday</b>: <?php echo $_POST['birthday']; ?></li>
			
		</ul>
	</body>
</html>