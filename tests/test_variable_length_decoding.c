#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "creation_arbre_Huffman.h"
#include "variable_length_decoding.h"
#include "lecture_flux_bits.h"
#include "header_extraction.h"
#include "macros.h"
#include "fonctions_generiques.h"


int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Utilisation: %s file.jpeg\n", argv[0]);
        return -1;
    }

    struct extended_FILE *stream = open_file(argv[1], "r");


    struct header *header = extract_header(stream);
    

    uint16_t* tab = decode_bloc(0, 0, 0, header, stream);
    free(tab);
    
    /*affiche_tab_uint16("    ", 8, tab, 64);*/
    

    close_file(stream);
    free_header(header);
}

    