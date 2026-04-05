#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#define F_CPU 16000000
#define BAUD 9600
#BRC (F_CPU/16/BAUD) - 1

#ESP_CMD_BASE "AT+"
#ESP_CMD_SEPARATOR "\r\n"


void USART_Init(unsigned int ubrr)
{
/*Set baud rate */
  UBRR0H = ubrr>>8;
  UBRR0L = ubrr;
 
/* Enable receiver and transmitter */
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
/* Set frame format: 8data, 1stop bit */
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

// Helper for transmitting the data
void USART_Transmit(char* data) {
   /* Wait for empty transmit buffer */
   while (!(UCSRnA & (1<<UDREn)))) {
     /* Put data into buffer, sends the data */
     UDRn = data;
}

// Helper for building/formatting commands to the ESP8266 (AT commands)
char* get_esp_cmd(char* cmd) {

  // get size of the command
  uint_8 size = sizeof(ESP_CMD_BASE) + sizeof(cmd) + sizeof(ESP_CMD_SEPARATOR) + 1;

  // Allocate the command string
  char* command_buff = malloc(size*sizeof(*char));

  
}


int main(void) {

  // UART setup atttemp:
  USAR_Init(BRC);

  while(1) {
    char* command = "AT\r\n";

    UDR0 = command;
    _delay_ms(1000);
    
  }
  
}
