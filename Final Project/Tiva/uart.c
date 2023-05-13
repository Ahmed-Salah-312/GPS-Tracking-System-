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


void UART_Init2 (void) {

    // Enable the UART7 and GPIOE peripherals
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;

    // Wait for the UART7 and GPIOE peripherals to be ready
    while((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R4) == 0);
    while((SYSCTL_PRUART_R & SYSCTL_PRUART_R7) == 0);

    // Configure the GPIO pins for UART7
    GPIO_PORTE_AFSEL_R |= (1 << 0) | (1 << 1);
    GPIO_PORTE_PCTL_R |= (1 << 0) | (1 << 4);

    // Configure the UART7
    UART7_CTL_R &= ~(UART_CTL_UARTEN);      // Disable the UART7
    UART7_IBRD_R = 104;                     // Integer baud rate divisor
    UART7_FBRD_R = 11;                      // Fractional baud rate divisor
    UART7_LCRH_R = UART_LCRH_WLEN_8;        // 8-bit data, no parity, 1 stop bit
    UART7_CC_R = UART_CC_CS_SYSCLK;         // Use system clock as UART clock source
    UART7_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN); // Enable the UART7, RX, and TX

}

void uart_send(char *str){
    while (*str) {  // Loop until end of string
        while((UART7_FR_R & UART_FR_TXFF) != 0);  // Wait if UART7 transmit FIFO is full
        UART7_DR_R = (*str++);  // Send the next character
    }
}
