#include <Arduino.h>

#define angle 360.00
#define stepRev 400.00
#define circle 360.00
#define motorPulsePin 8
#define motorDirectionPin 4
short int numberOfSteps = 1000;
short int direction = 1;
int czujnik = A5;

void step()
{
    digitalWrite(motorPulsePin,HIGH);
      delay(1);
    digitalWrite(motorPulsePin,LOW);
      delay(1);
}


void setup()
{
  
  Serial.begin(9600);
  pinMode(motorPulsePin,OUTPUT);
    pinMode(motorDirectionPin,OUTPUT);
    digitalWrite(motorDirectionPin,HIGH);

    // CALIBRATION
    

        direction = !direction;
        digitalWrite(motorDirectionPin,direction);
      while (numberOfSteps != 0)
        {
           
float odczyt = analogRead(czujnik);




          step();
          numberOfSteps--;
          Serial.println("1:");
Serial.println(odczyt);

        }

                direction = !direction;
        digitalWrite(motorDirectionPin,direction);
 
}

void loop()   
{      
    Serial.println();
    float odczyt = analogRead(czujnik);
    delay(2);
Serial.println("2:");
Serial.println(odczyt);
          if ( 1 )
        {
          if(odczyt>522)
          {
            while(1){}
            }
          else
          {
          step();
          numberOfSteps++;
          }

        }


     
}
