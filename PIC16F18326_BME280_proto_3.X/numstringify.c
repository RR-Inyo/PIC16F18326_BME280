/*
 * numstringify.h - A library to convert numerical values to strings, header file
 * (c) 2025 @RR_Inyo
*/

#include "mcc_generated_files/system/system.h"
#include "numstringify.h"

void numstringify(char *buf, float num, unsigned int maxpow, unsigned int digits)
{
    float b = 1.0;
    for (int i = 0; i < maxpow; i++) {
        b *= 10.0;
    }

    int j = 0;
    int k = 0;
    char d = 0;
    int nonzero = 0;

    if (num < 0) {
        num = -num;
        buf[k] = '-';
        k++;
    }

    while (j <= digits) {
        num -= b;

        if (num > 0) {
            d++;
            nonzero = 1;
            continue;
        }
        else {
            num += b;
            if (nonzero > 0 || b < 10.0) {
                buf[k] = '0' + d;
                k++;
            }
            j++;
            b /= 10.0;
        }

        if (j == maxpow + 1) {
            buf[k] = '.';
            k++;
        }

        d = 0;
    }

    buf[k] = '\0';
}
