#include <stdio.h>
#include <libxml/xmlreader.h>
#include "../include/xmlValidFile.h"

/**
 * xmlIsValid:
 * *filename: le nom du fichier à valider
 * 
 * La fonction analyse, valide et affiche des informations 
 */
 void xmlIsValid(char *filename) {
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
	/*
	 * Une fois l'analyse du fichier, on affiche les résultats de la validation
	 */
    if (ret == 0) { 
        fprintf(stderr, "Erreur lors de la lecture du fichier %s\n", filename);
        // fflush(stderr);
    }else{
        if (xmlTextReaderIsValid(reader) != 1) {
            fprintf(stderr, "Le document %s n'est pas valide\n", filename);
            // fflush(stderr);
         }else{
            fprintf(stderr, "Le document %s est valide\n", filename);
            // fflush(stderr);
            }
            xmlFreeTextReader(reader);
        }
    } else {
        fprintf(stderr, "Erreur d'ouverture %s\n", filename);
    }
}
