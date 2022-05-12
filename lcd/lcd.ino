#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd en 0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,20,4);  //

void setup() {

 //Se inicializa el LCD
 lcd.init();

 //Encendemos la luz de fondo.
 lcd.backlight();
  
 // Escribimos hola mundo en el LCD.
 lcd.print("Hola Mundo");

}

void loop() {

// Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
lcd.setCursor(0, 1);

// Escribimos el número de segundos trascurridos
lcd.print(millis()/1000);

lcd.print(" Segundos");
delay(100);

}
