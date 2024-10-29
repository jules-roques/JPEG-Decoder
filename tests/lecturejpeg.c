#include <stdio.h>
#include "lecture_flux_bits.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Utilisation: %s file.jpeg\n", argv[0]);
        return -1;
    }

    struct extended_FILE *stream = open_file(argv[1], "r");

    uint8_t bit;
    for (uint8_t i = 0; i < 64; i++) {
        print_extended_file(stream);
        bit = fget_one_bit(stream);
        printf("bit lu: %u\n", bit);
        printf("\n");
    }

    printf("\n");

    print_extended_file(stream);
    printf("3 bits extraits: 0x%x\n", fget_bits(stream, 3));
    printf("\n");

    print_extended_file(stream);
    printf("5 bits extraits: 0x%x\n", fget_bits(stream, 5));
    printf("\n");

    print_extended_file(stream);
    printf("8 bits extraits: 0x%x\n", fget_bits(stream, 8));
    printf("\n");

    print_extended_file(stream);
    printf("11 bits extraits: 0x%x\n", fget_bits(stream, 11));
    printf("\n");

    close_file(stream);

    /* On se congratule. */
    return 0;
}