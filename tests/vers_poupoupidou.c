#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header_extraction.h"
#include "fonctions_generiques.h"
#include "variable_length_decoding.h"
#include "creation_arbre_Huffman.h"
#include "macros.h"
#include "ecriture_ppm.h"




/* 
    Programme principal : prend en entrée un fichier jpeg, appelle tous les modules
    et renvoie le fichier PPM correspondant
*/
int main(int argc, char **argv)
{
     if (argc != 2) {
        printf("Utilisation: %s file.jpeg\n", argv[0]);
        return -1;
    }

    struct extended_FILE* stream = open_file(argv[1], "r");  /* ouverture fichier jpeg en mode lecture */
    if (stream == NULL) {
        print_error(stderr, "Erreur d'initialisation du fichier étendu de mémoire tampon\n");
        return -1;
    }

    FILE *fichier_ppm = fopen("poupou.ppm", "wb");           /* ouverture du fichier ppm en mode écriture */
    struct header *header = extract_header(stream);          /* Extraction de l'en-tête */
    if (header == NULL) {
        print_error(stderr, "Problème d'extration de l'en-tête\n");
        return -1;
    }

    ecrit_entete_ppm(header, fichier_ppm);
    ecrit_corps_ppm(header, stream, fichier_ppm);

    free_header(header);   /* libération en-tête */
    fclose(fichier_ppm);   /* femeture fichier ppm */
    close_file(stream);    /* lecture du marqueur de finde flux et fermeture du fichier jpeg */

    return 0;
}
