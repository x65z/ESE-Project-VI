<?php

$query = $db->query('SELECT currentFloor FROM status WHERE id = 1');

$floor = $query->fetch(PDO::FETCH_ASSOC);

echo '<h2>The car is now on floor: '.$floor['currentFloor'].'</h2>';

?>
