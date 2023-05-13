#include "uart.h"
#include <string.h>
#include <stdlib.h>

char GPS_logName[] ="$GPRMC,";
char dummy;
char lat[15];
char longi[15];

void GPS_read(void){

char recievedChar ;
char flag ;
int i,counter1,counter2;
do{
	
	do{
		flag = 1 ;
		for(i=0 ; i<7 ;i++){
			
			if(UART5_Read() != GPS_logName[i]){
				flag = 0; 
				break ;
			 }
		 }
	}while(flag==0);

	do{
		recievedChar = UART5_Read();
		if ( (recievedChar == 'A') || (recievedChar == 'V') )
			flag=0;
	}while(flag==1);

	if (recievedChar == 'A'){
		flag=1; 
		dummy = UART5_Read(); 
	}
}while(flag==0);
for(counter1=0 ; counter1<15 ;counter1++){
	recievedChar = UART5_Read();
  if(recievedChar == ','){
		dummy = UART5_Read();
		dummy = UART5_Read();
		break ;
	}
  lat[counter1] = recievedChar;
 }

	for(counter2=0 ; counter2<15 ;counter2++){
	recievedChar = UART5_Read();
  if(recievedChar == ','){
		break;
	}
  longi[counter2] = recievedChar;
  }


}

float GPSlat(void){
	float x;
	x = atof(lat);
  return x;	
}

float GPSlong(void){
	float y;
  y = atof(longi);
  return y;	
}

