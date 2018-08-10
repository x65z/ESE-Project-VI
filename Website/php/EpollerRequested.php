<?php

$query = $db->query('SELECT requestedFloor FROM status WHERE id = 1');

$floor = $query->fetch(PDO::FETCH_ASSOC);

echo .$floor['requestedFloor'].
//echo '<h2>The car is going to floor: '.$floor['requestedFloor'].'</h2>';

?>
