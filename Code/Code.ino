#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>
Servo myservo;
#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int MoisturePin = A1;
int Waterpin = A0; 

int waterlevel = 0;
int val = 0;
int Moisture = 0;

int PH_Value = 10;

float Celsius = 0;
float Fahrenheit = 0;

int pos = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
}

void loop() {
 
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
  Moisture = analogRead(MoisturePin);
  waterlevel = analogRead(Waterpin);
//  Serial.println((String)"temp: " + Celsius + " degree");
//  Serial.println((String)"moisture: " + Moisture);
//  Serial.println((String)"water level: " + waterlevel);
//  Serial.println("----------------------------------------------------");

    if ( (Celsius > 24 && Celsius < 30) && (Moisture < 370) && (waterlevel > 330) && (PH_Value > 2) ){ 
      MoveServo(45);
      Serial.println("45 degree");

  }
  else if ((Celsius > 30 && Celsius < 36) && (Moisture > 370 && Moisture < 600) && (waterlevel > 300 && waterlevel<= 330) && (PH_Value > 4)){ 
      MoveServo(90);
      Serial.println("90 degree");
  }

  else if ((Celsius > 36 && Celsius < 40) && (Moisture > 600 && Moisture < 1000) && (waterlevel > 300 && waterlevel<= 330) && (PH_Value > 6)){ 
      MoveServo(120);
      Serial.println("120 degree");
  }

  else if ((Celsius > 40) && (waterlevel <= 100) && (PH_Value > 8)){ 
      MoveServo(180);
      Serial.println("180 degree");
  }
//  delay(500); 
}

void MoveServo(int degree){
  for (pos = 0; pos <= degree; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  
  for (pos = degree; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
}
