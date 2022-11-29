<?php
// VARIABLES DE RECOLECCIÓN
$contenedor=$_POST['contenedor'];
$temperatura=$_POST['temperatura'];
$humedad=$_POST['humedad'];

echo  "Contenedor: ".$contenedor."<br>";
echo "Temperatura: ".$temperatura."<br>";
echo "Humedad: ".$humedad."<br>";


// CREAMOS SERVIDOR
$conexion_ = new mysqli("localhost","root","","test1");

// CHECAMOS LA CONEXION
if ($conexion_ -> connect_errno) {
  echo "Failed to connect to MySQL: " . $mysqli -> connect_error;
  exit();
}
// CREAMOS QUERY
$query="INSERT INTO historial(id_fecha,id_nombre_contenedor, temperatura, humedad) VALUES (NOW(),'$contenedor','$temperatura','$humedad')";
// SE ENVIA EL QUERY
if (mysqli_query($conexion_,$query)) {
  echo "Historial"."<br>";
} else {
  echo "Error: " . $query . "<br>" . $query->error;
}
// CREAMOS QUERY POR SI AUMENTA LA TEMEPRATURA 
if($temperatura>25){
  $query1="INSERT INTO incidente(id_fecha,id_nombre_contenedor, temperatura, humedad) VALUES (NOW(),'$contenedor','$temperatura','$humedad')";
  if (mysqli_query($conexion_,$query1)) {
    echo "Incidiente"."<br>";
  } else {
    echo "Error: " . $query1 . "<br>" . $query1->error;
  }
}


?>