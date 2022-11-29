
#include <WiFiClient.h>
#include <ESP8266WiFi.h>

#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>


// CONTRASEÑA Y NOMBRE DE LA RED
// Sustituir con datos de vuestra red
const char* ssid     = "kokas";
const char* password = "kokaslocas55";


const String host="192.168.137.1";
// INICIALIZAMOS EL SENSOR 
#define DHTTYPE DHT11 //Nombramos el tipo de sensor que usaremos DHT 11 
#define DHTPIN 14// El sensor estará conectado al 5
DHT dht(DHTPIN, DHTTYPE); // Inicializamos el sensor DHT11

int LED_WIFI=5;
int LED_SERVIDOR=4;
int LED_LEER=0;
int LED_ERROR=2;
// VARIABLES
String contenedor="ContenedorA";
float temperatura;
float  humedad;
WiFiClient wifiClient;

int ventilador=13;
/*
=====================================
          WIFI
=====================================
*/
void ConectarWifi(){
  // INICAR CONECCION 
  WiFi.mode(WIFI_STA); // Tipo de modo de acceso Station
  WiFi.begin(ssid, password); // Conectamos con la red 
  // Nos muestra  nombre de la red y ssid
  Serial.print("Conectando a:\t");
  Serial.println(ssid); 
  // Esperar a que nos conectemos
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
   Serial.print('.');
  }
  // CONECCION EXITOSA 
  // Mostrar mensaje de exito y dirección IP asignada
  Serial.println();
  Serial.print("Conectado a:\t");
  Serial.println(WiFi.SSID()); 
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_WIFI, HIGH);
}

/*
=====================================
          ENVIAR DATOS
=====================================
*/
void EnviosDatos(){
  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    String datos="contenedor="+contenedor+"&temperatura="+String(temperatura)+"&humedad="+String(humedad);
    http.begin(wifiClient,"http://"+host+"/SERVIDOR/prueba.php");
    http.addHeader("Content-Type","application/x-www-form-urlencoded");
    int codigo_respuesta = http.POST(datos);
    if(codigo_respuesta>0){
      Serial.println("Codigo HTTP: "+String(codigo_respuesta));
      if(codigo_respuesta==200){
        String cuerpo_respuesta = http.getString();
        Serial.println("Respondió el servidor");
        digitalWrite(LED_SERVIDOR, HIGH);
        digitalWrite(LED_ERROR, LOW);
      }
    } else {
      Serial.print("Error enviando el POST");
      Serial.println(codigo_respuesta);
      digitalWrite(LED_ERROR, HIGH);
      digitalWrite(LED_SERVIDOR, LOW);
    }
    http.end();
  }else{
    Serial.print("Error de conexion");
    digitalWrite(LED_ERROR, HIGH);
    digitalWrite(LED_SERVIDOR, LOW);
  }
}
/*
=====================================
          LED INICIALIZAR
=====================================
*/
void led(){
  pinMode(LED_WIFI, OUTPUT); 
  pinMode(LED_SERVIDOR, OUTPUT); 
  pinMode(LED_LEER, OUTPUT); 
  pinMode(LED_ERROR, OUTPUT); 

  delay(1000);  
  digitalWrite(LED_WIFI, HIGH);
  delay(1000);
  digitalWrite(LED_SERVIDOR, HIGH);
  delay(1000);
  digitalWrite(LED_LEER, HIGH);
  delay(1000);
  digitalWrite(LED_ERROR, HIGH);
  delay(1000);
  digitalWrite(LED_WIFI, LOW);
  digitalWrite(LED_SERVIDOR, LOW);
  digitalWrite(LED_LEER, LOW);
  digitalWrite(LED_ERROR, LOW);
  delay(1000);
}
/*
=====================================
          LECTURA DE DATOS
=====================================
*/
void LecturaDatos(){
     // Leemos la humedad relativa
  humedad = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  temperatura=dht.readTemperature();
  
    if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    humedad=30;
    temperatura=30;
    digitalWrite(LED_ERROR, HIGH);
    digitalWrite(LED_LEER, LOW);
    
  }else{
    Serial.print("Temperatura: ");
    Serial.println(temperatura);
    Serial.print("Humedad: ");
    Serial.println(humedad);
    digitalWrite(LED_LEER, HIGH);
    digitalWrite(LED_ERROR, LOW);
    EnviosDatos();
  }
  RegularTemperatura();
  delay(40000);
}
/*
=====================================
          COMPROBAR CONEXION
=====================================
*/
void ComprobarConexion(){
  if(WiFi.status()==WL_CONNECTED){
    digitalWrite(LED_WIFI, HIGH);
    digitalWrite(LED_ERROR, LOW);
  }else{
    digitalWrite(LED_WIFI, LOW);
    digitalWrite(LED_ERROR, HIGH);
  }
}
/*
=====================================
          VENTILADOR
=====================================
*/
void RegularTemperatura(){
  if(temperatura>=26){
    digitalWrite(ventilador,HIGH);
    Serial.println("Ventilador encendido");
  }else{
    digitalWrite(ventilador,LOW);
    Serial.println("Ventilador apagado");
  }
}
void setup()
{
  // INCIAR LOS PUERTOS
  pinMode(ventilador,OUTPUT);
  Serial.begin(115200); // Inicializamos comunicación serie
  dht.begin();// Comenzamos el sensor DHT
  // Señalizamos ventildaor
  digitalWrite(ventilador,LOW);
  led(); // Inicializamos los led 
  ConectarWifi(); // Conectamos al wifi

}

void loop() 
{
  ComprobarConexion();
  LecturaDatos();
  

}
