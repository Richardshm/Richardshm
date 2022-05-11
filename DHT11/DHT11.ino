//Libreria del sensor 
#include "DHT.h"

//Pin digital que usaremos en el arduino
#define DHTPIN 10  

//Se define el tipo de DHT11 que se usara, existe dht22
#define DHTTYPE DHT11   

//Se instancia el pin y tipo de dht
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  //Se inicia la comunicacion serial a 9600 baudios
  Serial.begin(9600);
  
  //Se imprime el inicio de la medicion del dht
  Serial.println(F("DHTxx test!"));

  //Se inicia el sensor
  dht.begin();
  
}

void loop() {
  
  //Espera dos segundos para la primera toma de datos.
  delay(2000);

   //Se lee la humedad
  float h = dht.readHumidity();
  
  //Se lee la temperatura
  float t = dht.readTemperature();

  //Comprobacion de que los bits de lectura sean correctos
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Fallo al leer el sensor DHT11!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));


}
