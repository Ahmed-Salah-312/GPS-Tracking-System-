#include "gpio.h"
#include "uart.h"
#include "gps.h"
#include "dist.h"


#define total_path_distance 100    


int main(void){
  
	float previous_longitude, previous_latitude, current_longitude, current_latitude;
	float distance_travelled, ds, current_to_end_distance;
	RGBLED_Init();
	UART_Init ();
	UART_Init2 ();
	GPS_read();
	previous_latitude = GPSlat();
	previous_longitude = GPSlong();
	distance_travelled = 0;
	
	while(1){
    GPS_read();
		current_latitude = GPSlat();
		current_longitude = GPSlong();
		ds = GPS_getDistance(previous_longitude, previous_latitude, current_longitude, current_latitude);
		distance_travelled = distance_travelled + ds;
		previous_latitude = current_latitude;
		previous_longitude = current_longitude;
		
		
	}
		
}







