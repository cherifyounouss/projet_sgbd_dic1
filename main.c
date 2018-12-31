#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

void afficher_aide(char* argv[]);

int main(int argc, char *argv[])
{   
    /* Les options de la ligne de commande */
    int option;
    /* Variables nous permettant de compter le nombre de parametres renseignes par l'utilisateur */
    int count_i, count_h, count_f, count_o, count_t;
    count_i = count_h = count_f = count_o = 0, count_t = 0;
    /*Variable pour stocker le format saisi par l'utilisateur*/
    char * file_format;
    /*Variable pour stocker le nom du fichier en entree*/
    char * fichier_entree;
    /*Variable pour stocker le nom du fichier en sorti*/
    char * fichier_sortie;

    if(argc <= 1)
        afficher_aide(argv);

    /*On parcours la commande saisie en recuperant chaque fois une option 
    et en incrementant le compteur de l'option correspondant*/
    while((option = getopt(argc, argv, "i:th:f:o:")) != -1){
        switch (option)
        {
            case 'i':
                count_i++;
                file_format = optarg;
                break;
            case 't':
                count_t++;
                break;
            case 'h':
                count_h++;
                fichier_entree = optarg;
                break;
            case 'f':
                count_f++;
                fichier_entree = optarg;
                break;
            case 'o':
                count_o++;
                fichier_sortie = optarg;
		        break;
        }
    }

    /*Suivant le nombre de parametres renseignes par l'utilisateur, on effectue les traitements necessaires*/
    if (count_i == 1){
        if (strcmp(file_format, "json") == 0 || strcmp(file_format, "xml") == 0){
            if (count_h == 1 ^ count_f == 1) {
                if (count_o == 1){
			if(count_t){
			printf("Print traces\n");	
                    printf("Processing data...\n");}
                }
                else{
                    (count_o > 1) ? printf("Veuillez renseigner un seul nom pour le fichier en sorti\n") : printf("Veuillez renseigner un argument pour la sortie\n");
                    exit(EXIT_FAILURE);
                }
            }
            else{
                printf("Veuillez renseigner une entree de donnee <-h flux http | -f fichier>\n");
                exit(EXIT_FAILURE);
            }
        }
        else{
            printf("Veuillez renseigner un format du fichier en entree correct <-i json|xml>\n");
            exit(EXIT_FAILURE);
        }
    }
    else{
        (count_i > 1) ? printf("Veuillez renseigner un seul format pour le fichier en entree\n") : printf("Veuillez renseigner le format du fichier en entree <-i json|xml>\n");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}

void afficher_aide(char* argv[]){
    printf("Utilisation: %s -i <xml | json> <-t> <-h url_flux_http | -f fichier_input> -o nomfichier.svg\n", argv[0]);
    exit(EXIT_FAILURE);
}