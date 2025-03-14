/* 
 * File:   peripheral.c
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

void U1Write(uint8_t Data){
    U1TXREG = Data;
}

void U2Write(uint8_t Data){
    U2TXREG = Data;
}