int LED = 4;
int sensor = 8;
int sensorval = 0;
int text = 0;


void setup() {
  Serial.begin(9600);   
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop(){
  sensorval = digitalRead(sensor);           //tillsräcklig simpel för att direkt läggas in i "void loop" istället för att skapa en egen funktion.
  Updatesensor();
  UpdateLED();
}



void Updatesensor(void) {                     //Funktionen som säger om det känner av rörelse eller inte.
  if (sensorval == HIGH) {                    //Funktionen behövs egentligen inte eftersom att den ej mäter av sensorn
    if (text == 0){        
    Serial.println("Finns rörelse");
    text = 1; }               
  } 
  else {
    if (text == 1){
      Serial.println("Ingen rörelse");
      text = 0;
    }         
  }
}

void UpdateLED(void) {
  if (sensorval == HIGH){
    digitalWrite(LED,HIGH);
    delay(10000);                    // 10 sekunder delay
  }else{
    digitalWrite(LED,LOW);
  }
}
