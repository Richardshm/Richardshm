void setup() {
  //Abrimos conexion serial a 9600 baudios
  Serial.begin(9600); 
}

void loop() {

  //Variable donde almacenar medicion
  int val;

  //Se lee el sensor el cual esta conectado en A0
  val = analogRead(0); 

  if(val > 430){
    Serial.print("Seco:  ");
    Serial.println(val);
    delay(100);}

  if(val > 350 && val <= 430){
    Serial.print("Humedo:  ");
    Serial.println(val);
    delay(100);}

  if(val>260 && val <= 350){
    Serial.print("Agua:  ");
    Serial.println(val);
    delay(100);}

}
