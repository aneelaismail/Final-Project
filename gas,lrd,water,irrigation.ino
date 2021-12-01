
int val; //This variable stores the value received from Soil moisture sensor.


float d;
int low=23;
int high=5;
int WET= 3; 
int DRY= 2;  
int Sensor= 4; // Soil Sensor input at Analog PIN A0
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 620;
int value= 0;
const int ledPin = 13;
const int ldrPin = A1;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);
   delay(100);
   pinMode(10,OUTPUT); //Set pin 13 as OUTPUT pin
  pinMode(8,INPUT); //Set pin 8 as input pin, to receive data from Soil moisture sensor.
//  Initialize serial and wait for port to open:
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while (! Serial);// wait for serial port to connect. Needed for native USB
  //Serial.println("Speed 0 to 255");
 
  
   pinMode(7,INPUT);//echo pin of ultraSonic
   pinMode(6,OUTPUT);//trig pin of ultraSonic
   pinMode(10,OUTPUT);// relay
   pinMode(9,OUTPUT);// buzzer pin
   
  
//   pinMode(ledPin, OUTPUT);
  // pinMode(ldrPin, INPUT);

}

void vol() //distance calculation...
{
 digitalWrite(6,HIGH);
 delayMicroseconds(8);
 digitalWrite(6,LOW);
 delayMicroseconds(2);
 d=pulseIn(7,HIGH);
 d=d/69;
}

void loop() {  
 vol();
 while(1)
  {
   b:
   digitalWrite(10,HIGH);// Pump On...
   delay(2000);
   vol();
   if(d<high) //check high...
    {
     digitalWrite(9,HIGH);// buzzer on.....
     delay(1000);
     digitalWrite(9,LOW);
     goto a;
    }
  }
 while(1)
  {
   a:
   digitalWrite(10,LOW);// pump off...
   delay(100);
   vol();
   if(d>low) //check low
    {
     digitalWrite(9,HIGH);//Buzzer beeping......
     delay(1000);
     digitalWrite(9,LOW);
     delay(1000);
     digitalWrite(9,HIGH);
     delay(1000);
     digitalWrite(9,LOW);
     delay(1000);
     
     goto b;
    }
  }
    Serial.print("MOISTURE LEVEL : ");
   value= analogRead(Sensor);
   value= value/10;
   Serial.println(value);
   if(value<50)
   {
      digitalWrite(WET, HIGH);
   }
   else
   {
      digitalWrite(DRY,HIGH);
   }
   delay(1000);
   digitalWrite(WET,LOW);
   digitalWrite(DRY, LOW);
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
  int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 200) {

digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);

} else {

digitalWrite(ledPin, LOW);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

}
} 
 
