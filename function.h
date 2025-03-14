/* 
 * File:   function.h
 * Author: takum
 *
 * Created on March 13, 2025, 0:58 PM
 */

#ifndef FUNCTION_H
#define	FUNCTION_H

#ifdef	__cplusplus
extern "C" {
#endif

// defined in setup.c
void setup();

//  defined in peripheral.c
void U1Write(uint8_t); // Main Board
void U2Write(uint8_t); // Debug

#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTION_H */

