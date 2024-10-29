#ifndef _DECODAGEDPCM_H_
#define _DECODAGEDPCM_H_

#include "lecture_flux_bits.h"
#include <stdint.h>
#include <stdio.h>

uint16_t decodeDPCM_DC(uint16_t predicateur, uint8_t magnitude, struct extended_FILE *stream);
uint16_t decodeDPCM_AC(uint8_t magnitude, struct extended_FILE *stream);


#endif /*_DECODAGEDPCM_H_*/