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
 * Fonction qui retourne le nombre d'entités d'un fichier
 */
int nombre_entite(xmlNode *root);