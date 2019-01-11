#include <stdio.h>
#include <libxml/xmlstring.h>

static void save_data(const xmlChar *data,FILE *fic){

    fic=fopen("saveFile.txt","a");

    if (strcmp(data,"") == 0){
        exit(1);
    }
    // fseek(fic,5,0);
    fprintf(fic,"%s\n",data);
    // rewind(fic);
    fclose(fic);
}

typedef struct s_entite{
    /* data */
    char *nom;
    char **attribut;
    char **associations;
    int nb_assoc;
    int nb_attributs;

}s_entite;

typedef struct s_assoc{
    /* data */
    char *nom;
    char **attribut;
    int nb_attributs;

}s_assoc;


