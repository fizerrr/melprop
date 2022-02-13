#include <Arduino.h>
#include <EEPROM.h>

#define forceConst 36.50
#define angle 360.00
#define stepRev 400.00
#define circle 360.00
#define motorPulsePin 8
#define motorDirectionPin 4
//short int numberOfSteps = 1000;
short int numberOfSteps;
short int direction = 1;
int CurrentSensor = A5;
int eepromPin = 0;

void step()
{
    digitalWrite(motorPulsePin,HIGH);
      delay(1);
    digitalWrite(motorPulsePin,LOW);
      delay(1);
}

void currentToForce()
{
    float currentRead = analogRead(CurrentSensor);
    delay(2);
   // Serial.println(currentRead);
   
   //ALGORYTHM

  //Serial.println((currentRead/0.066)/forceConst);
 
  

}

void setup()
{
  
    Serial.begin(9600);
      pinMode(motorPulsePin,OUTPUT);
        pinMode(motorDirectionPin,OUTPUT);
         digitalWrite(motorDirectionPin,HIGH);

    //przypisanie pamięci 
    numberOfSteps = EEPROM.read(eepromPin);

    // CALIBRATION
    

      direction = !direction;
        digitalWrite(motorDirectionPin,direction);
          while (numberOfSteps != 0)
            {
              step();
                numberOfSteps--;
            }

      direction = !direction;
        digitalWrite(motorDirectionPin,direction);

        //END OF CALIBRATION
 
}


void loop()   
{      

  //SET ANGLE 

      if (numberOfSteps != (angle/(circle/stepRev)))
        {
          step();
          numberOfSteps++;
        }

  //DISPLAY INFORMATION ABOUT FORCE IN THE MOMENT

  currentToForce();

  //SAVE INFORAMTION ABOUT SET ANGLE

  if(numberOfSteps == (angle/(circle/stepRev)))
  {
    EEPROM.write(eepromPin,numberOfSteps);
    numberOfSteps++;
  }

}


                                    //BRUDNOSPIS

/* void loop()   
{      
    Serial.println();
    float currentRead = analogRead(CurrentSensor);
    delay(2);
Serial.println("2:");
Serial.println(currentRead);
          if ( 1 )
        {
          if(currentRead>521)
          {
            while(1){}
          }
          else
          {
      
          step();
          numberOfSteps++;
          }

        }

if(shouldSave)
{
//EEPROM.write(eepromPin,numberOfSteps);

}    


}

*/