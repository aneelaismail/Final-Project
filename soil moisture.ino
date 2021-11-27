int WET= 3; 
int DRY= 2;  
int motor= 6;
int Sensor= A0; // Soil Sensor input at Analog PIN A0
int value= 0;

void setup() {
   Serial.begin(9600);
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);
   delay(2000);
}

void loop() {
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(Sensor);
   value= value/10;
   Serial.println(value);
   if(value<50)
   {
      digitalWrite(WET, HIGH);
      digitalWrite(motor, LOW);
   }
   else
   {
      digitalWrite(DRY,HIGH);
      digitalWrite(motor,HIGH);
   }
   delay(1000);
   digitalWrite(WET,LOW);
   digitalWrite(DRY, LOW);
   digitalWrite(motor,LOW);
}
