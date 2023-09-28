#include <avr/io.h>
#include <avr/interrupt.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)

#define LED_PIN 2

void checkAndHandleInput(){
    //Kolla o trtckt på knapp eller whatever
}

ISR(TIMER1_OVF_vect){
    BIT_FLIP(PORTB,LED_PIN);
    TCNT1 = 65535-15625;
}

//I dont clear it - CTC
int main(){

    BIT_SET(DDRB, LED_PIN); //Sätt led_pin till output mode

    //Max value of 65535 -> overflow -> ISR
    TCNT1 = 65535-15625; // Start value every cycle ++
    //16Mhz / 1024 = 15625 Hz  - ticks per sec
    TCCR1B = (1 << CS10)| (1 << CS12); // 1024

    //TCCR0A – Timer/Counter Control Register A
    TCCR0B |=  (1 << CS02)|(1 << CS00); //Prescaler 1024
    TCCR1A = 0;
    TIMSK1 = (1 << TOIE1);

    sei();

    TCNT0 = 0;
    int overflows = 0;

    while(1){
        
        //Check input
        checkAndHandleInput();
 
    }

    return 0;
}

