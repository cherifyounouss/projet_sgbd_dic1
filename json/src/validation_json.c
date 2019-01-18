#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/JSON_checker.h"
#include "../include/validation_json.h"

int est_valide(char* filename){
    char ch;
    FILE* fic = NULL;
    int ligne = 1;
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
            fprintf(stderr, "JSON_checker_char: erreur de syntaxe dans le fichier json, ligne: %d\n", ligne);
            exit(1);
        }
        if(ch == '\n')
            ligne++;
    }
    if (!JSON_checker_done(jc)) {
        fprintf(stderr, "JSON_checker_end: erreur de syntaxe dans le fichier json\n");
        exit(1);
    }
    return 0;
}

void flux_vers_fichier(char* flux_http){
    FILE* fp = fopen("fichier_flux", "w");
    
    if (fp != NULL) {
        fputs(flux_http, fp);
        fclose(fp);
    }else{
        printf("Impossible de creer un fichier pour stocker les donnees de la requete http\n");
        exit(EXIT_FAILURE);
    }
    
}