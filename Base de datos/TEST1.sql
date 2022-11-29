CREATE DATABASE TEST1;
USE TEST1;
CREATE TABLE producto(
    id_producto CHAR(20) PRIMARY KEY, 
    temperatura_max FLOAT NOT NULL,
    temperatura_min FLOAT NOT NULL,
    humedad_max FLOAT NOT NULL,
    humedad_min FLOAT NOT NULL
);
CREATE TABLE contenedor(
    id_nombre_contenedor CHAR(20) PRIMARY KEY,
    capacidad INT NOT NULL,
    id_producto CHAR(20) NOT NULL,
    CONSTRAINT fk_producto  FOREIGN KEY (id_producto) REFERENCES producto(id_producto)

);
/* Introducir datos */
INSERT INTO producto(id_producto,temperatura_max,temperatura_min,humedad_max,humedad_min)
VALUES 
('aguacate',24,20,55,50);

INSERT INTO contenedor(id_nombre_contenedor,capacidad,id_producto)
VALUES 
('ContenedorA',200,'aguacate');

CREATE TABLE historial(
    id_fecha DATETIME PRIMARY KEY,
    id_nombre_contenedor CHAR(20) NOT NULL,
    temperatura FLOAT NOT NULL,
    humedad FLOAT NOT NULL,
    CONSTRAINT fk_historial  FOREIGN KEY (id_nombre_contenedor) REFERENCES contenedor(id_nombre_contenedor)
);

CREATE TABLE incidente( id_fecha DATETIME NOT NULL, id_nombre_contenedor CHAR(20) NOT NULL, temperatura FLOAT NOT NULL, humedad FLOAT NOT NULL, CONSTRAINT fk_incidente1 FOREIGN KEY (id_fecha) REFERENCES historial(id_fecha), CONSTRAINT fk_incidente2 FOREIGN KEY (id_nombre_contenedor) REFERENCES contenedor(id_nombre_contenedor) );