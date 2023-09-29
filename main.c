#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)

#define LED_PIN 6

void checkAndHandleInput(){
    //Kolla o trtckt på knapp eller whatever
    // om tryckt
    // dutyCycle += 10;
    // if(dutyCycle > 100)
    // dutyCycle = 5;


}
// 1 - PWM frekvsn
// 25 % av tiden PÅ
// 75% av tiden AV
// dutyCycle 25%

volatile double dutyCycle = 95;
ISR(TIMER0_OVF_vect){
}

//I dont clear it - CTC
int main(){

    BIT_SET(DDRD, LED_PIN); //Sätt led_pin till output mode
 
    TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TIMSK0 = (1 << TOIE0);
    OCR0A = (dutyCycle/100)*255;
    sei();

    TCCR0B = (1 << CS00);

    while(1){
        
        //Check input
        checkAndHandleInput();
        _delay_ms(100);
    }

    return 0;
}

