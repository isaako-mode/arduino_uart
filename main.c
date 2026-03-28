#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

int main(void) {

  DDRB |= (1 << DDB0);
  
  while(1) {
    
    PORTB ^= (1 << PB0);

    _delay_ms(500);
  }
}
