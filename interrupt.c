/* 
 * File:   interrupt.c
 * Author: takum
 *
 * Created on March 13, 2025, 1:30 PM
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

void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt (void){
    
    IFS0bits.U1RXIF = 0;
}

void __attribute__((interrupt,no_auto_psv)) _U2RXInterrupt (void){
    
    IFS1bits.U2RXIF = 0;
}

void __attribute__((interrupt,no_auto_psv)) _CNInterrupt (void){
    
    IFS1bits.CNIF = 0;
}