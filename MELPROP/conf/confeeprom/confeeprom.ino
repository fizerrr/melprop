#include <EEPROM.h>
int addr = 0;
int val = 0;

void setup()
{
   
	EEPROM.write(addr, val);
}

void loop()
{
	//blank
}
