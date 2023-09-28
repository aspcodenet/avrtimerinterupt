#include <avr/io.h>
#include <util/delay.h>

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

// int main(){

//     BIT_SET(DDRB, LED_PIN); //Sätt led_pin till output mode
//     //TCCR0A – Timer/Counter Control Register A
//     TCCR0B |=  (1 << CS02)|(1 << CS00); //Prescaler 1024
//     TCNT0 = 0;
//     int overflows = 0;

//     while(1){
        
//         //Check input
//         checkAndHandleInput();
//         //
//         if(TCNT0 == 255){
//             overflows++;
//             TCNT0 = 0; 
//         }
//         if (overflows == 61)
//         {
//             BIT_FLIP(PORTB,LED_PIN);
//             overflows = 0;
//             TCNT0 = 0;            // reset counter
//         }        
 
//     }

//     return 0;
// }



//I dont clear it - CTC
int main(){

    BIT_SET(DDRB, LED_PIN); //Sätt led_pin till output mode
    //TCCR0A – Timer/Counter Control Register A
    TCCR0B |=  (1 << CS02)|(1 << CS00); //Prescaler 1024
    TCNT0 = 0;
    int overflows = 0;

    while(1){
        
        //Check input
        checkAndHandleInput();
        //
        if(TCNT0 == 255){
            overflows++;
            TCNT0 = 0; 
        }
        if (overflows == 61)
        {
            BIT_FLIP(PORTB,LED_PIN);
            overflows = 0;
            TCNT0 = 0;            // reset counter
        }        
 
    }

    return 0;
}

