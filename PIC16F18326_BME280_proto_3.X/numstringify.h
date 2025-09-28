/*
 * numstringify.h - A library to convert numerical values to strings, header file
 * (c) 2025 @RR_Inyo
*/

#ifndef NUMSTRINGIFY_H
#define	NUMSTRINGIFY_H

#ifdef	__cplusplus
extern "C" {
#endif

void numstringify(char *buf, float num, unsigned int maxpow, unsigned int digits);

#ifdef	__cplusplus
}
#endif

#endif	/* NUMSTRINGIFY_H */

