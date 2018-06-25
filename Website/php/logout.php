<?php
// logout.php
session_start(); // required for every page where you call or declare a session
session_destroy();

echo "You have been logged out. Click <a href='../html/login.html'>here</a> to login again"

 ?>
