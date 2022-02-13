#include <Arduino.h>
#include <EEPROM.h>

#define angle 360.00
#define stepRev 180.00
#define circle 360.00
#define motorPulsePin 8
#define motorDirectionPin 4
short int numberOfSteps=100;
short int direction = 1;
int czujnik = A5;
int eepromPin = 0;


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

    //przypisanie pamięci 
   // numberOfSteps = EEPROM.read(eepromPin);
    Serial.println("jol");
    // CALIBRATION
    

       
      while (numberOfSteps != 0)
        {
                     step();
          numberOfSteps--;

        }

                direction = !direction;
        digitalWrite(motorDirectionPin,direction);
 
}

void loop()   
{      
   

          if (numberOfSteps != (angle/(circle/stepRev)) )
        {
          step();
          numberOfSteps++;
        }

if(numberOfSteps == (angle/(circle/stepRev)))
{
//EEPROM.write(eepromPin,numberOfSteps);
Serial.println(numberOfSteps);

numberOfSteps++;
}    


}
