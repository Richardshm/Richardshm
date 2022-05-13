//Libreria del sensor 
#include "DHT.h"

//Pin digital que usaremos en el arduino
#define DHTPIN 2  

//Se define el tipo de DHT11 que se usara, existe dht22
#define DHTTYPE DHT11   

//Se instancia el pin y tipo de dht
DHT dht(DHTPIN, DHTTYPE);

//Librerias pantallla i2c lcd 16x2
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd en 0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,20,4);  //

void setup() {

  //Se inicia la comunicacion serial a 9600 baudios
  Serial.begin(9600);
  
  //Se imprime el inicio de la medicion del dht
  Serial.println(F("DHTxx test!"));

  //Se inicia el sensor
  dht.begin();

  //Se inicializa el LCD
  lcd.init();

  //Encendemos la luz de fondo.
  lcd.backlight();
  
}

void loop() {

  //Variable donde almacenar medicion del sensor de humeda del suelo
  int val;

  //Se lee el sensor de humedad del suelo el cual esta conectado en A0
  val = analogRead(0);
  
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

 if(val > 430){
    lcd.setCursor(0, 0);
    lcd.print("HA:");
    lcd.setCursor(3,0);
    lcd.print(int(h));
    delay(100);}

  if(val > 350 && val <= 430){
    Serial.print("Humedo:  ");
    Serial.print(val);
    Serial.print(F("  Humeda aire: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.println(t);
    delay(100);}

  if(val>260 && val <= 350){
    Serial.print("Agua:  ");
    Serial.print(val);
    Serial.print(F("  Humeda aire: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.println(t);
    delay(100);}


}
