
#include <ESP8266WiFi.h>
#include <ModbusTCPSlave.h>

ModbusTCPSlave Mb;

unsigned long timer;
unsigned long checkRSSIMillis;
void setup()
{    
 //Mb.begin("SSID", "PASSWORD", "IP", "GATEWAY", "SUBNET");
   Mb.begin("ziroom3303", "4001001111");
  delay(1000);
  
  Serial.begin(115200);
}

void loop()
{
  
 Mb.Run();
 
 //Random Value  1 - 100
 Mb.MBHoldingRegister[0] = (random(1, 100));
 //Print Serial Holding Register [0]
 Serial.println(Mb.MBHoldingRegister[0]);
 delay(100);
  
    
}

 /*****FUNZIONI*****/

byte checkRSSI() {
  byte quality;
  long rssi = WiFi.RSSI();
  if (rssi <= -100)
    quality = 0;
  else if (rssi >= -50)
    quality = 100;
  else
    rssi = rssi + 100;
  quality = byte(rssi * 2);

  return quality;
}
