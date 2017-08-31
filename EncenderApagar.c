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
int cont = 0;

void main(void) {    
    //iniciar_uart();    
    TRISB = 0b00000000;
    PORTB = 0;
    TRISC = 1;
    PORTC = 0;
    
    
    while (1){
        
        if (estado_boton == 0){      
        PORTB = 0b00000000;
        while (PORTCbits.RC0 == 1){
            estado_boton = 1;            
        //    estado_boton--;
        }     
    }   
       if (estado_boton == 1){
      
         PORTB = 0b11111111;
        while (PORTCbits.RC0 == 1){
            estado_boton = 0;
            
        //    estado_boton--;
        }     
    }      
        
    }
    
 /*   while (1){
        
    if(estado_boton == 1) {  
        PORTB = 0b00000000; 
        if (PORTCbits.RC0 == 1){
            estado_boton = 0;
            PORTB = 0b00000000;                        
            printf("Los leds estan encendidos\n");
          //  estado_boton++;           
        }
     }
     if(estado_boton == 0)
    {
         PORTB = 0b11111111;
        if (PORTCbits.RC0 == 0){
            estado_boton = 1;
            PORTB = 0b11111111;
            
        //    estado_boton--;
        }
        
    }      
    }
        
        /*
      if (estado_boton == 2){
            PORTB = 0B00000000;
           estado_boton = 0;
            if (PORTCbits.RC0 == 0){                        
            PORTB = 0B00000000;
            printf("Los leds estan apagados\n");
        }
        }
        else {
            PORTB = 0B00000000;
        }
    }  */     

}
