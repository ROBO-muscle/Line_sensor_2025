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
//    CN_setup();
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
    TRISGbits.TRISG13 = 0;
    RPOR14bits.RP125R = 0b000001;
    TRISGbits.TRISG12 = 1;
    RPINR18bits.U1RXR = 124;
    
//  Debug | UART2
    TRISEbits.TRISE4  = 0;
    RPOR5bits.RP84R   = 0b000011;
    TRISEbits.TRISE3  = 1;
    RPINR19bits.U2RXR = 183;    

// Buzzer | OC1
    TRISFbits.TRISF8  = 0;
    RPOR11bits.RP104R = 0b010000;
    
// LED
    TRISFbits.TRISF0 = 0; // LED1
    TRISFbits.TRISF1 = 0; // LED2
    TRISGbits.TRISG1 = 0; // LED3
    
// LINE
    /* Right */
    TRISDbits.TRISD7  = 1; // 1 front
    TRISDbits.TRISD6  = 1; // 2
    TRISDbits.TRISD5  = 1; // 3
    TRISDbits.TRISD4  = 1; // 4
    TRISDbits.TRISD13 = 1; // 5 back
    
    /* Back */
    TRISDbits.TRISD0  = 1; // 1 Right
    TRISDbits.TRISD11 = 1; // 2
    TRISDbits.TRISD10 = 1; // 3
    TRISDbits.TRISD9  = 1; // 4
    TRISDbits.TRISD8  = 1; // 5 Left
    
    /* Left */
    TRISBbits.TRISB15 = 1; // 1 back
    TRISBbits.TRISB14 = 1; // 2
    TRISBbits.TRISB13 = 1; // 3
    TRISBbits.TRISB12 = 1; // 4
    TRISFbits.TRISF12 = 1; // 5 front
    
    /* Angel Ring */
    TRISDbits.TRISD12 = 1; //  1-1
    TRISDbits.TRISD3  = 1; //  1-2
    TRISDbits.TRISD2  = 1; //  2-1
    TRISDbits.TRISD1  = 1; //  2-2
    TRISAbits.TRISA15 = 1; //  3-1
    TRISAbits.TRISA14 = 1; //  3-2
    TRISAbits.TRISA5  = 1; //  4-1
    TRISAbits.TRISA4  = 1; //  4-2
    TRISAbits.TRISA3  = 1; //  5-1
    TRISAbits.TRISA2  = 1; //  5-2
    TRISFbits.TRISF2  = 1; //  6-1
    TRISFbits.TRISF3  = 1; //  6-2
    TRISFbits.TRISF5  = 1; //  7-1
    TRISFbits.TRISF4  = 1; //  7-2
    TRISDbits.TRISD15 = 1; //  8-1
    TRISDbits.TRISD14 = 1; //  8-2
    TRISFbits.TRISF13 = 1; //  9-1
    TRISAbits.TRISA1  = 1; //  9-2
    TRISBbits.TRISB10 = 1; // 10-1
    TRISBbits.TRISB9  = 1; // 10-2
    TRISBbits.TRISB3  = 1; // 11-1
    TRISBbits.TRISB4  = 1; // 11-2
    TRISBbits.TRISB5  = 1; // 12-1
    TRISEbits.TRISE9  = 1; // 12-2
    TRISCbits.TRISC3  = 1; // 13-1
    TRISCbits.TRISC2  = 1; // 13-2
    TRISCbits.TRISC1  = 1; // 14-1
    TRISEbits.TRISE7  = 1; // 14-2
    
}

void CN_setup(){
    CNENDbits.CNIED7  = 1;
    CNENDbits.CNIED6  = 1;
    CNENDbits.CNIED5  = 1;
    CNENDbits.CNIED4  = 1;
    CNENDbits.CNIED13 = 1;
    CNENDbits.CNIED0  = 1;
    CNENDbits.CNIED11 = 1;
    CNENDbits.CNIED10 = 1;
    CNENDbits.CNIED9  = 1;
    CNENDbits.CNIED8  = 1;
    CNENBbits.CNIEB15 = 1;
    CNENBbits.CNIEB14 = 1;
    CNENBbits.CNIEB13 = 1;
    CNENBbits.CNIEB12 = 1;
    CNENFbits.CNIEF12 = 1;
    CNENDbits.CNIED12 = 1;
    CNENDbits.CNIED3  = 1;
    CNENDbits.CNIED2  = 1;
    CNENDbits.CNIED1  = 1;
    CNENAbits.CNIEA15 = 1;
    CNENAbits.CNIEA14 = 1;
    CNENAbits.CNIEA5  = 1;
    CNENAbits.CNIEA4  = 1;
    CNENAbits.CNIEA3  = 1;
    CNENAbits.CNIEA2  = 1;
    CNENFbits.CNIEF2  = 1;
    CNENFbits.CNIEF3  = 1;
    CNENFbits.CNIEF5  = 1;
    CNENFbits.CNIEF4  = 1;
    CNENDbits.CNIED15 = 1;
    CNENDbits.CNIED14 = 1;
    CNENFbits.CNIEF13 = 1;
    CNENAbits.CNIEA1  = 1;
    CNENBbits.CNIEB10 = 1;
    CNENBbits.CNIEB9  = 1;
    CNENBbits.CNIEB3  = 1;
    CNENBbits.CNIEB4  = 1;
    CNENBbits.CNIEB5  = 1;
    CNENEbits.CNIEE9  = 1;
    CNENCbits.CNIEC3  = 1;
    CNENCbits.CNIEC2  = 1;
    CNENCbits.CNIEC1  = 1;
    CNENEbits.CNIEE7  = 1;
    
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