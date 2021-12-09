/*******
 
 All the resources for this project:
 https://www.hackster.io/Aritro

*******/

int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = 9 ;
// Your threshold value
int sensorThres = 620;
int WET= 3; 
int DRY= 2;  
int Sensor= 0; // Soil Sensor input at Analog PIN A0
int value= 0;
int relay = 4;


void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  
  Serial.begin(9600);
     Serial.begin(9600);
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);
   pinMode(relay, OUTPUT);
   delay(100);
}
void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
  Serial.print("MOISTURE LEVEL : ");
   value= analogRead(Sensor);
   value= value/10;
   Serial.println(value);
   if(value<50)
   {
      digitalWrite(WET, HIGH);
      digitalWrite(relay, LOW);
   }
   else
   {
      digitalWrite(DRY,HIGH);
      digitalWrite(relay, HIGH);
   }
   delay(1000);
   digitalWrite(WET,LOW);
   digitalWrite(DRY, LOW);
   digitalWrite(relay, HIGH);
}
