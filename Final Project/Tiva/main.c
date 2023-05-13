#include "gpio.h"
#include "uart.h"
#include "gps.h"
#include "dist.h"
#include <stdlib.h>
#include "stdio.h"
#include <math.h>

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
		current_to_end_distance = abs(total_path_distance - distance_travelled) ;
		//sending data to ardunio
		uart_send((char)distance_travelled);
		
		if (current_to_end_distance >= 5)
			RGB_Output (RED);                //red led
		
		else if (current_to_end_distance < 5 && current_to_end_distance >1){
			RGB_Output (YELLOW);                //yellow led
		}
		else if (current_to_end_distance < 1 )
			RGB_Output (GREEN);       					//green led
		 
		
	}
		
}

