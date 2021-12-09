int WET= 3; 
int DRY= 2;  
int Sensor= 0; // Soil Sensor input at Analog PIN A0
int value= 0;
int relay = 4;

void setup() {
   Serial.begin(9600);
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);
   pinMode(relay, OUTPUT);
   delay(100);
}

void loop() {
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
