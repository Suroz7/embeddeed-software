/* this program implements seat belt reminder for driver. It uses the electronics describe in slide 6 in optima.

INPUTS
P0.0 Driver sitting sensor (Value 0 when driver is sitting )
         Value 0 when driver is sitting
p1.1 Belt sensor (Value 0 when belt is fastened)

OUTPUTS
P3.7 Alarm LED (lights when p3.7 value is 0)

*/

#include<REG52.h> // this contains HW-address eg for ports

sbit DRIVER_SENSOR_PIN    = P0^0;
sbit SEAT_BELT_SENSOR_PIN = P0^1;

sbit ALARM_LED_PIN        = P3^7;

void main(){
  //Configure P0 as input port
  P0 = 0xFF;
	
  // Make the program excute forever (as far as the devicee is  powered) 
	while (1) {
		// if driver is sitting and belt is not closed do alarm
		if (DRIVER_SENSOR_PIN == 0 && SEAT_BELT_SENSOR_PIN == 1){
		ALARM_LED_PIN= 0;
		}
			else  {
			ALARM_LED_PIN = 1;
			}
}