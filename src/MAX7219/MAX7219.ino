#include "LedControl.h"
// Arduino Pin 7 to DIN, 6 to Clk, 5 to CS, no.of devices is 1

const int nDevices = 2;
LedControl lc=LedControl(7,6,5,nDevices);
void setup()
{
 // Initialize the MAX7219 device
 for(int deviceID=0; deviceID<nDevices; deviceID++) {
  lc.shutdown(deviceID,false);   // Enable display
  lc.setIntensity(deviceID,15);  // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(deviceID);   
 }

}
void loop() {
  for(int deviceID=0; deviceID<nDevices; deviceID++) {
    for(int i=0; i<9; i++) {
      lc.setDigit(deviceID,i,i+1,false);
      delay(500);
     }
   lc.clearDisplay(deviceID);  
  }    
  delay(1000);
}
