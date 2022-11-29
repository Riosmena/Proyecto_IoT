<?php
$host = 'localhost';
$db = 'iot';
$usuario = 'root';
$password = '';

$link = mysqli_connect($host, $usuario, $password, $db);

$query = 'SELECT * FROM datos';
$result = mysqli_query($link, $query);

$horas = array();
$humedades = array();

while ($fila = mysqli_fetch_array($result)) {
    $hora = $fila['hora'];
    $hum = $fila['humedad'];
    $horas[] = $hora;
    $humedades[] = $hum;
}

$respuesta = [
    "horas" => $horas,
    "humedades" => $humedades
];

echo json_encode($respuesta);
?>
