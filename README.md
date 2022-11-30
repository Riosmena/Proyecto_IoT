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

Página Web: 
