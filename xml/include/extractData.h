/*
 * fonctions d'extraction des données du fichier xml
 */
#include <libxml/tree.h>
void extractionData(char *filename);
void printData(xmlNode * a_node);

/*
 * Fonction d'enregistrement des données extraites dans un fichier
 */
void save_data(const xmlChar *data,FILE *fic);

/*
 * Fonction de génération du fichier svg
 */

void creerEntite(xmlChar *name);

/*
 * Une structure entite 
 */
typedef struct s_entite{
    /* data */
    char *nom;
    char **attribut;
    char **associations;
    int nb_assoc;
    int nb_attributs;

}s_entite;

/*
 * Une structure association
 */
typedef struct s_assoc{
    /* data */
    char *nom;
    char **attribut;
    int nb_attributs;

}s_assoc;
/*
 * Fonction qui retourne le nombre d'entités d'un fichier
 */
int nombre_entite(xmlNode *root);