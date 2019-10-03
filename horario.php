<?php
$hoje = getdate();
echo $hoje['year'] . "-" . substr('0' . $hoje['mon'], -2) . "-" . substr('0' . $hoje['mday'], -2) . "T" . substr('0' . $hoje['hours'], -2) . ":" . substr('0' . $hoje['minutes'], -2) . ":" . substr('0' . $hoje['seconds'], -2);
?>