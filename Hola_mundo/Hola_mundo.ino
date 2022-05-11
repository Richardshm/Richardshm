void setup() {
  
  Serial.begin(9600);//Iniciamos la comunicacion serial a 9600 baudios 

}

void loop() {

  Serial.print("¡Hola Mundo!.\n");//Mostramos el mensaje "¡Hola mundo!"
  delay(1000);//Pausamos la ejecución durante 1 segundo

}
