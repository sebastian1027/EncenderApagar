/*
 * File:   EncenderApagar.c
 * Author: Sebastianl
 * 
 * Created on 28 de agosto de 2017, 10:28 AM
 */

#include <xc.h>
#include <stdio.h>
#include "config.h"
#include <pic16f887.h>

int estado_boton = 0;
int pulso = 0;
int bandera = 0;

void main(void) {    
    iniciar_uart();    
    TRISB = 0b00000000;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;    
    
    
    
 while (1){
    
     if (PORTCbits.RC0 == 1 && bandera == 0){         
         bandera = 1;
         while(PORTCbits.RC0 == 1){}
         }
     if (PORTCbits.RC0 == 1 && bandera == 1){         
         bandera = 0;
         while(PORTCbits.RC0 == 1){}
         }
     
     if ( bandera == 1){
         PORTB = 0b11111111;
     }
     else{
         PORTB = 0b00000000;
     }
         
    }
}
