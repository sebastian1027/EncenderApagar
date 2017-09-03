/*
 * File:   EncenderApagar.c
 * Author: Sebastian Lopez, Danny Martinez
 * 
 * Created on 28 de agosto de 2017, 10:28 AM
 */

#include <xc.h>
#include <stdio.h>
#include "config.h"
#include <pic16f887.h>

//*********** declaramos la variables a usar
int estado_boton = 0;
int pulso = 0;
int bandera = 0;  //variable a usar para hacer posible que el algoritmo funciones
//******************************************

void main(void) {    
    iniciar_uart();    //iniciamos uart para poder guiarnos en la simulacion
    TRISB = 0b00000000; //declaramos el puerto B como salidas
    PORTB = 0; // limpiamos el puerto B
    TRISC = 1; //declaramos el puerto C como entrada
    PORTC = 0;  // Limpiamos el puerto C
    
    
    
 while (1){ //empieza el ciclo infinito
    
     if (PORTCbits.RC0 == 1 && bandera == 0){         //pregunta si se presiono el boton del pin 0 del puerto C y que bandera = 0
         bandera = 1;  //le da el valor de 1 a bandera 
         while(PORTCbits.RC0 == 1){}
         } //va a mantenerse en ese estado hasta que se presino nuevamete el boton
     if (PORTCbits.RC0 == 1 && bandera == 1){         //pregunta si se presiono el boton, de ser asi, pregunta si la bandera esta en 1, al ser las 2 condiciones  verdaderas apaga los leds
         bandera = 0;  //pone la bandera en 0
         while(PORTCbits.RC0 == 1){}
         } //se queda es ese estado hasta volver a presionar el boton
     
     if ( bandera == 1){
         PORTB = 0b11111111; // si bandera es 1, prende los leds
         printf("Leds encendidos.\n");
     }
     else{
         PORTB = 0b00000000; //en caso de que la bandera sea 0, apaga los leds
         printf("Leds apagados.\n");
     }
         
    } //termina el ciclo inifito
} //termina el codigo
