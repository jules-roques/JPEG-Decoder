#include <stdio.h>
#include "header_extraction.h"
#include "macros.h"


int main(int argc, char **argv)
{
    if (argc != 2) {
        print_error(stderr, "Utilisation: %s file.jpeg\n", argv[0]);
        return -1;
    }

    struct extended_FILE *stream = open_file(argv[1], "r");

    struct header *en_tete = extract_header(stream);
    if (en_tete == NULL) {
        print_error(stderr, "Problème d'exraction de l'en-tête\n");
        return -1;
    }

    print_header(en_tete);

    free_header(en_tete);
    close_file(stream);

    /* On se congratule. */
    return 0;
}