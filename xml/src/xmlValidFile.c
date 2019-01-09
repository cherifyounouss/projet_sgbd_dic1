#include <stdio.h>
// #include <libxml/reader2.h>
#include <libxml/xmlreader.h>

/**
 * xmlIsValid:
 * *filename: le nom du fichier à valider
 * 
 * La fonction analyse, valide et affiche des informations 
 */
static void xmlIsValid(const char *filename) {
    xmlTextReaderPtr reader;
    int ret;


    /*
     * Activation des options pour valider le DTD du fichier xml
     */
    reader = xmlReaderForFile(filename, NULL,
         XML_PARSE_DTDATTR |  /* default DTD attributes */
		 XML_PARSE_NOENT |    /* substitute entities */
		 XML_PARSE_DTDVALID); /* validate with the DTD */
    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);
        // while (ret == 1) {
        //     processNode(reader);
        //     ret = xmlTextReaderRead(reader);
        // }
	/*
	 * Une fois l'analyse du fichier, on affiche les résultats de la validation
	 */
        if (xmlTextReaderIsValid(reader) != 1) {
            fprintf(stderr, "Le document %s n'est pas valide\n", filename);
        }else{
            fprintf(stderr, "Le document %s est valide\n", filename);
        }
            xmlFreeTextReader(reader);
            if (ret != 0) {
                fprintf(stderr, "Erreur lors de la lecture du fichier %s\n", filename);
            }
    } else {
        fprintf(stderr, "Erreur d'ouverture %s\n", filename);
    }
}

    /*
	 * un bloc main pour tester la fonction de validation
	 */
int main(int argc, char **argv) {
    /*
	 * On vérifie si un fichier est bien passer en argument
	 */
    if (argc != 2){
        fprintf(stderr, "Veuiller renseigner le fichier xml\n");
    }
    
    /*
	 * On valide le fichier
	 */
    xmlIsValid(argv[1]);

    /*
     * On libére les ressources libxml2 utilisées par la fonction.
     */
    xmlCleanupParser();
    /*
     * Une fonction dans libxml2 pour les tests de non-regression
     */
    xmlMemoryDump();
    return(0);
}
