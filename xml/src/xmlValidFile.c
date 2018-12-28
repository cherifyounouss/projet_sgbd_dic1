#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void isValid(const char *filename) {
    xmlParserCtxtPtr ctxt; /* variable d'analyse du format xml*/
    xmlDocPtr doc; /* Structure du document résultant */

    /* Xréation du contexte d'analyse */
    ctxt = xmlNewParserCtxt();
    if (ctxt == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
	return;
    }
    /* Option de validation du DTD */
    doc = xmlCtxtReadFile(ctxt, filename, NULL, XML_PARSE_DTDVALID);
    /* Analyse de la structure */
    if (doc == NULL) {
        fprintf(stderr, "Erreur d'analyse du fichier %s\n", filename);
    } else {
	/* Validation */
        if (ctxt->valid == 0)
	    fprintf(stderr, "Erreur de validation%s\n", filename);
	/* Libérer la variable doc */
	xmlFreeDoc(doc);
    }
    /* fLibérer la variable ctxt */
    xmlFreeParserCtxt(ctxt);
}

