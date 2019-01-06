#include <stdio.h>
#include "../include/JSON_checker.h"

int est_valide(FILE* fic){
    char ch;
    JSON_checker jc = new_JSON_checker(20);

    while(1){
        ch = fgetc(fic);
        /* sortie lorsqu'on atteint la fin du fichier*/
        if(feof(fic))
            break;
        /* Verification syntaxique */
        if (!JSON_checker_char(jc, ch)) {
            fprintf(stderr, "JSON_checker_char: erreur de syntaxe %c\n", ch);
            return 0;
        }
    }
    if (!JSON_checker_done(jc)) {
        fprintf(stderr, "JSON_checker_end: erreur de syntaxe dans le fichier json\n");
        exit(1);
    }
    return 1;
}