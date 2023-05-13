#include "uart.h"
#include <string.h>
#include <stdlib.h>

char GPS_logName[] ="$GPRMC,";
char dummy;


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
