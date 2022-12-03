# Smart-Shipping
## Chilaquiles4K
### José Emiliano Riosmena Castañón - A01704245
### Jorge Martínez López - A01704518
### Grant Nathaniel Keegan - A01700753
### Iván Ricardo Paredes Avilez - A01705083

Nuestro proyecto consiste en la creación de contenedores de transporte de alimentos, en los que se implementará un sistema de refrigeración el cual va regulando constantemente la temperatura de este, de modo que los alimentos transportados lleguen a su destino en buenas condiciones y tengan tiempo de madurar al llegar a los mercados, y reducir el enorme desperdicio de estos.

Para ello, hemos desarrollado un pequeño prototipo que consiste en tres secciones:

Sistemas digitales: Aqui hacemos uso de un Node MCU (ESP8266), un sensor de temperatura y humedad (DHT11), y un ventilador de 5V. Los cuales, a través de la programación del Node MCU en Arduino, hemos hecho que cada minuto, el sensor de DHT11 registre la temperatura y humedad en ese momento. También hemos definido un límite máximo y mínimo de temperatura, en donde si la temperatura rebasa esos límites, el Node MCU activa el ventilador para regular la temperatura hasta que la temperatura baje hasta el límite establecido. Por último, el Node MCU lleva registro de la temperatura y humedad de cada hora y estos registrons son enviados a una base de datos a través de un PHP.

Base de datos: Aqui hacemos uso de phpMyAdmin, en el cual a través de un script de SQL, se ha creado una base de datos en el cual se lleva registro de los contenidos de un contendor, el historial de registros de cada hora, y los instantes en los que se registra la temperatura y la humedad, esto se logra gracias a un PHP que toma los datos creados de los sitemas digitales y añade registros a la base de datos. En el PHP se hace uso de querys de SQL, los cuales nos permiten introducir los registros a la base de datos. La base de datos esta conectada a una Página Web, por medio de otro PHP, en cual se despliegan los datos de la tabla del historial de temperaturas y humedades de cada hora del día por medio de gráficas.

Página Web: Para la creación, diseño y programación de la página web, hemos utilizado HTML, CSS y JavaScript. La página contiene una portada en el cual se muestra el título del proyecto y el nombre del equipo, en el encabezado. El menú principal esta dividido en tres secciones:

Contexto: Aquí se muestra una explicación breve de lo que se busca lograr con la página web, su misión y su visión.

Gráficas: Esta es la parte más importante de la página web, su razón de ser. Aquí se muestran las gráficas de las temperaturas y humedades registradas en cada hora de un día. Esto fue logrado gracias a dos PHP que toman los registros de la temperatura y humedad de la base de datos, en ellos también se usan query se SQL, que permiten acceder a la base de datos y guardarlos en arreglos. Posteriormente estos datos son leidos por dos scripts, los cuales toman estos dos archivos PHP, leen sus datos y despliegan el contenido de ellos en dos gráficas. 

Autores: Por último y no menos importante, como su nombre menciona, aqui se muestra los nombres de los integrantes del equipo y en que se especializó cada uno.

#### Notas:
Para el correcto funcionamiento de la página web, es necesario que la carpeta de nombre "graficas" de este repositorio, sea guardada en la carpeta de htdocs de XAMPP. Del mismo modo, para la correcta visualización de las gráficas, es necesario que este inicializado el XAMPP con los módulos de Apache y MySQL.

También, las gráficas toman como base de datos, una prueba en los que se tienen registros similares a los de la base de datos real, esto es porque los trabajos fueron realizados en computadoras separadas. Y tuvimos el imprevisto de que el sitema operativo de una de ellas no es capaz de correr el programa de Arduino, por lo tanto no puede ejectutar los scripts de este ni enviar los registros a su correspondiente base de datos. Ambos códigos de las bases de datos, se encuentran en este repositorio.

### Instrucciones para el funcionamiento correcto de la página Web

1. Incializar XAMPP con los módulos de Apache y MySQL.

2. En localhost, ejectutar el script de SQL, el archivo llamado "Prueba Base de datos.sql".

3. Descargar los archivos de la carpeta "Página Web" o "ProyectoFinal.zip".

4. Guardar la carpeta "graficas" en la carpeta de htdocs de XAMPP.

5. Ejecutar el primer archivo "index.html".

6. Permitir el acceso desde "configuracion avanzada".
