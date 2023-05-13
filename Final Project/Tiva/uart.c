#include "tm4c123gh6pm.h"

void UART_Init (void) {
		int z;
	SYSCTL_RCGCUART_R |= 0x0020;                  
	for (z=0; z<1000; z++){};

	SYSCTL_RCGCGPIO_R |= 0x0010;
	while((SYSCTL_PRGPIO_R&0x0010) == 0){};

	UART5_CTL_R &= ~0x0001;
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11;
	UART5_LCRH_R = 0x0070;
	UART5_CTL_R = 0x0301;
	GPIO_PORTE_AFSEL_R |= 0x30;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
	GPIO_PORTE_DEN_R |= 0x30;
	GPIO_PORTE_AMSEL_R &= ~0x30;
	
}

char UART5_Read (void) {
while ((UART5_FR_R & 0x0010) != 0) {};
return (char) (UART5_DR_R & 0xFF); 
}
