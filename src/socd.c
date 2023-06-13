#include<avr/io.h>
#include "attiny84.h"
#include "button_handlers.h"

/*
IN:
UP = PA0
DOWN = PA1
LEFT = PA2
RIGHT = PA3


OUT:
UP = PA4
DOWN = PA5
LEFT = PA6
RIGHT = PA7


TOGGLE:
LR = PB0
UD = PB1
*/

int main(){
    SET_PA0_INPUT;
    SET_PA1_INPUT;
    SET_PA2_INPUT;
    SET_PA3_INPUT;
    SET_PB0_INPUT;
    SET_PB1_INPUT;
    SET_PA0_PULLUP;
    SET_PA1_PULLUP;
    SET_PA2_PULLUP;
    SET_PA3_PULLUP;
    SET_PB0_PULLUP;
    SET_PB1_PULLUP;


    SET_PA4_OUTPUT;
    SET_PA5_OUTPUT;
    SET_PA6_OUTPUT;
    SET_PA7_OUTPUT;

    while(1){
        while(READ_PB0_IN && READ_PB1_IN){
            PORTA ^= (handle_up_priority() << PA4);
            PORTA ^= (handle_down() << PA5);
            PORTA ^= (handle_left_major() << PA6);
            PORTA ^= (handle_right_major() << PA7);
            handle_both_lr();
        }
        while(!READ_PB0_IN && READ_PB1_IN){
            PORTA ^= (handle_up_priority() << PA4);
            PORTA ^= (handle_down() << PA5);
            PORTA ^= (handle_left_neutral() << PA6);
            PORTA ^= (handle_right_neutral() << PA7);
    
        }
        while(READ_PB0_IN && !READ_PB1_IN){
            PORTA ^= (handle_up_neutral() << PA4);
            PORTA ^= (handle_down() << PA5);
            PORTA ^= (handle_left_major() << PA6);
            PORTA ^= (handle_right_major() << PA7);
            handle_both_lr();
        }
        while(!READ_PB0_IN && !READ_PB1_IN){
            PORTA ^= (handle_up_neutral() << PA4);
            PORTA ^= (handle_down() << PA5);
            PORTA ^= (handle_left_neutral() << PA6);
            PORTA ^= (handle_right_neutral() << PA7);
        }
    }
}