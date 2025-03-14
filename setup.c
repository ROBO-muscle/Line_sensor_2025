/* 
 * File:   setup.c
 * Author: takum
 *
 * Created on March 13, 2025, 1:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <p33EP512MU810.h>
#include "xc.h"
#include "function.h"
#include "libpic30.h"
#include "user.h"
#include "common.h"
#define FCY 64000000

void setup(){
    OSC_set();
    pin_set();
//    UART1_setup(115200);
//    UART2_setup(115200);
//    TMR1_setup();
//    OC1_setup();
}

void OSC_set(){
    OSCCON   = 0x0100;
    OSCTUN   = 0x0017;
    PLLFBD   = 0x003E;
    CLKDIV   = 0x0000;
    ACLKCON3 = 0xA2E1;
    ACLKDIV3 = 0x0007;
}

/* TODO : Check pin-assign */
void pin_set(){
    ANSELA = 0x0000;
    ANSELB = 0x0000;
    ANSELC = 0x0000;
    ANSELD = 0x0000;
    ANSELE = 0x0000;
    ANSELG = 0x0000;
    
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    
    TRISA = 0xffff;
    TRISB = 0xffff;
    TRISC = 0xffff;
    TRISD = 0xffff;
    TRISE = 0xffff;
    TRISF = 0xffff;
    TRISG = 0xffff;
    
//  Main Board | UART1
//    TRIS  = 0;
//    RPOR = 0b000001;
//    TRIS  = 1;
//    RPINR18bits.U1RXR = ;
    
//  Debug | UART2
//    TRIS  = 0;
//    RPOR = 0b000011;
//    TRIS  = 1;
//    RPINR19bits.U2RXR = ;
    

// Buzzer | OC1
//    TRIS
//    RPOR = 0b010000;
    
// LINE
    
//    TRIS  = 1; 
    
//    CNEN  = 1;
    
    IEC1bits.CNIE = 1;
    IPC4bits.CNIP = 2;
    IFS1bits.CNIF = 0;
}

void UART1_setup(long baudrate){    
    U1MODE = 0x0000;
    U1STA  = 0x0000;
    
    U1MODEbits.BRGH = 1;
    U1BRG = FCY / (4 * baudrate) - 1;
    U1STAbits.URXISEL = 0b00;
    U1STAbits.UTXINV = 0;
    
    IEC0bits.U1RXIE = 1;
    IPC2bits.U1RXIP = 0b001;
    IFS0bits.U1RXIF = 0;
    U1STAbits.URXISEL = 00;
    
    U1MODEbits.UARTEN = 1;
    
    U1STAbits.UTXEN = 1;
}

void UART2_setup(long baudrate){    
    U2MODE = 0x0000;
    U2STA  = 0x0000;
    
    U2MODEbits.BRGH = 1;
    U2BRG = FCY / (4 * baudrate) - 1;
    U2STAbits.URXISEL = 0b00;
    U2STAbits.UTXINV = 0;
    
    IEC1bits.U2RXIE = 1;
    IPC7bits.U2RXIP = 0b001;
    IFS1bits.U2RXIF = 0;
    U2STAbits.URXISEL = 00;
    
    U2MODEbits.UARTEN = 1;
    
    U2STAbits.UTXEN = 1;
}

// FIXME: Replace motor control -> music control

void TMR1_setup (void){
    PR1   =   0x00;
    TMR1  =   0x00;
    T1CON = 0x8000;
}

void OC1_setup(){
    OC1R  = 0x0000;
    OC1RS = 0x1000;
    OC1CON1 = 0x0000;
    OC1CON2 = 0x0000;
    OC1CON1bits.OCM     =   0b110; // Edge-Aligned PWM mode
    OC1CON1bits.OCTSEL  =   0b111; // Peripheral clock(FOSC/2)
    OC1CON2bits.SYNCSEL = 0b01011; // Timer1 synchronizes or triggers OC1
    OC1CON2bits.OCTRIG  =     0b1; // OC1 Start
}