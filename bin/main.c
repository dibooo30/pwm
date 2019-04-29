#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define brightness
// initialize PWM
void pwm_init()
{
    // initialize timer0 in PWM mode
	TCCR2 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00);

    // make sure to make OC2 pin (pin PB3 for atmega32) as output pin
    DDRD = 0b11111111;
}

int main(void){
	DDRD = 0xFF;
	DDRA = 0xFF;
	PORTD = 0xFF;
	PORTA = 0x00;
    pwm_init();
    int i = 0;
    OCR2 = i;
    while(1){

    	if(!bit_is_clear(PINA, 0)){
    		i++;
    		_delay_ms(20);
    	    OCR2 = i;
    	    }
    	if(!bit_is_clear(PINA, 0) && i < 90 ){
    		i = 127;
    		_delay_ms(20);
    	    OCR2 = i;
    	    }
    	if(i > 255){
    		i = 255;
    	    OCR2 = i;
    	    }
    	if(!bit_is_clear(PINA, 1)){
    		i--;
    		_delay_ms(20);
    	    OCR2 = i;
    	    }
    	if(i <= 127 && bit_is_clear(PINA, 0)){
				i = 0;
				OCR2 = i;
    	    }
    	}
    }


//while(1) {
//    // increasing brightness
//    for (brightness = 0; brightness < 255; ++brightness){
//        // set the brightness as duty cycle
//        OCR2 = brightness;
//        // delay so as to make the user "see" the change in brightness
//        _delay_ms(10);
//    }
//    // decreasing brightness
//    for (brightness = 255; brightness > 0; --brightness){
//        // set the brightness as duty cycle
//        OCR2 = brightness;
//        // delay so as to make the user "see" the change in brightness
//        _delay_ms(10);
//    }
//
//// repeat this forever
//}
