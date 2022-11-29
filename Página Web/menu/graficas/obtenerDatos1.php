<?php
$host = 'localhost';
$db = 'iot';
$usuario = 'root';
$password = '';

$link = mysqli_connect($host, $usuario, $password, $db);

$query = 'SELECT * FROM datos';
$result = mysqli_query($link, $query);

$horas = array();
$temperaturas = array();

while ($fila = mysqli_fetch_array($result)) {
    $hora = $fila['hora'];
    $temp = $fila['temperatura'];
    $horas[] = $hora;
    $temperaturas[] = $temp;
}

$respuesta = [
    "horas" => $horas,
    "temperaturas" => $temperaturas,
];

echo json_encode($respuesta);
?>
