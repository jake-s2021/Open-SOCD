#define RIGHT READ_PA3_IN
#define LEFT READ_PA2_IN


unsigned char last_pressed = 2;
//unsigned char both = 0;
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


unsigned char handle_up_priority(){
    unsigned char A = (READ_PA0_IN);
    unsigned char C = (PORTA & (1<<PA4));

    return A != C;

}
unsigned char handle_up_neutral(){
    unsigned char A = (READ_PA0_IN);
    unsigned char B = (PORTA & (1<<PA4));
    unsigned char C = (READ_PA1_IN);
    unsigned char D =  (PORTA & (1<<PA5));

    return (!A && B && !C || !A && B && !C || A && !B && !C || B && C && A || B && C && D);
}
unsigned char handle_down(){
    unsigned char A = (READ_PA0_IN);
    unsigned char B = (PORTA & (1<<PA4));
    unsigned char C = (READ_PA1_IN);
    unsigned char D =  (PORTA & (1<<PA5));

    return (!A && C && !D || !C && D && !B || !C && D && !A || A && D && B || A && D && C);

}
unsigned char handle_left_neutral(){
    unsigned char A = (READ_PA2_IN);
    unsigned char B = (PORTA & (1<<PA6));
    unsigned char C = (READ_PA3_IN);
    unsigned char D =  (PORTA & (1<<PA7));

    return (!A && B && !C || !A && B && !C || A && !B && !C || B && C && A || B && C && D);

}
unsigned char handle_right_neutral(){
    unsigned char A = (READ_PA2_IN);
    unsigned char B = (PORTA & (1<<PA6));
    unsigned char C = (READ_PA3_IN);
    unsigned char D =  (PORTA & (1<<PA7));

    return (!A && C && !D || !C && D && !B || !C && D && !A || A && D && B || A && D && C);

}
unsigned char handle_left_major(){

    return (!(PORTA & (1<<PA6)) && (LEFT && !RIGHT || LEFT && last_pressed == 1) ) 
    || ((PORTA & (1<<PA6)) && RIGHT) || ((PORTA & (1<<PA6) && !LEFT)); 
    
    /*
            
        if(!both && !(PORTA & (1<<PA6)) && LEFT && (PORTA & (1<<PA7)){
              PORTA ^= (1 << PA7);
              both = 1;
              return 1;
          }
        return (!(PORTA & (1<<PA6)) && (LEFT && !RIGHT) || ((PORTA & (1<<PA6) && !LEFT));  
    
    */
    

}
unsigned char handle_right_major(){

    return (!(PORTA & (1<<PA7)) && (RIGHT && !LEFT || RIGHT && last_pressed == 0) )
    || (PORTA & (1<<PA7) && LEFT) || ((PORTA & (1<<PA7) && !RIGHT));
    
    /*
        if(!both && !(PORTA & (1<<PA7)) && RIGHT && (PORTA & (1<<PA6))){
            PORTA ^= (1 << PA6);
            both = 1;
            return 1;
          }
         return (!(PORTA & (1<<PA7)) && (RIGHT && !LEFT) || ((PORTA & (1<<PA7) && !RIGHT));
          
    */
    

}
void handle_last_pressed(){

    if(LEFT && !RIGHT){
        last_pressed = 0;
    }
    else if(RIGHT && !LEFT){
        last_pressed = 1;
    }
    
    /*if(!(LEFT &&  RIGHT){
            both = 0;
      }
     */

    

}
