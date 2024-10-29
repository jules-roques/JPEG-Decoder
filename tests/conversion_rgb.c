#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "conversion_ycbcr_rgb.h"

int main(int argc, char **argv)
{
    (void) argv;
    (void) argc;

    uint16_t val = 257;
    uint8_t reduit = (uint8_t) val;

    printf("%u -> %u\n", val, reduit);

    /* On se congratule. */
    return 0;
}