#include <stdio.h>
#include <stdlib.h>
#include "../include/JSON_checker.h"

int est_valide(char* filename){
    char ch;
    FILE* fic = NULL;
    fic = fopen(filename, "r");
    if (!fic) {
        return EXIT_FAILURE;
    }
    
    JSON_checker jc = new_JSON_checker(20);

    while(1){
        ch = fgetc(fic);
        /* sortie lorsqu'on atteint la fin du fichier*/
        if(feof(fic))
            break;
        /* Verification syntaxique */
        if (!JSON_checker_char(jc, ch)) {
            fprintf(stderr, "JSON_checker_char: erreur de syntaxe dans le fichier json %c\n", ch);
            exit(1);
        }
    }
    if (!JSON_checker_done(jc)) {
        fprintf(stderr, "JSON_checker_end: erreur de syntaxe dans le fichier json\n");
        exit(1);
    }
    return 0;
}