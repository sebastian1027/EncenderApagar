/*
 * File:   EncenderApagar.c
 * Author: Sebastianl
 * 
 * Created on 28 de agosto de 2017, 10:28 AM
 */

#include <xc.h>
#include <stdio.h>
#include "config.h"

int estado_boton = 0;

void main(void) {    
    iniciar_uart();    
    TRISB = 0b00000000;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;
    
    while (1){
        
        if (PORTCbits.RC0 == 0){                        
            PORTB = 0B00000000;
            printf("Los leds estan apagados\n");
        }
        
        if (PORTCbits.RC0 == 1){
            estado_boton++;
        }
        
        if (estado_boton == 1){
            PORTB = 0B11111111;                        
            printf("Los leds estan encendidos\n");
        }               
        
        /*if (estado_boton == 2){
            PORTB = 0B00000000;
            estado_boton = 0;
        }*/
    }       
}

