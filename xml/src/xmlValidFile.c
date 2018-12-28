#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void isValid(const char *filename) {
    xmlParserCtxtPtr ctxt; /* variable d'analyse du format xml*/
    xmlDocPtr doc; /* Structure du document résultant */

    /* Xréation du contexte d'analyse */
    ctxt = xmlNewParserCtxt();
    if (ctxt == NULL) {
        fprintf(stderr, "Failed to allocate parser context\n");
	return;
    }
    /* Option de validation du DTD */
    doc = xmlCtxtReadFile(ctxt, filename, NULL, XML_PARSE_DTDVALID);
    /* Analyse de la structure */
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse %s\n", filename);
    } else {
	/* Validation */
        if (ctxt->valid == 0)
	    fprintf(stderr, "Failed to validate %s\n", filename);
	/* Libérer la variable doc */
	xmlFreeDoc(doc);
    }
    /* fLibérer la variable ctxt */
    xmlFreeParserCtxt(ctxt);
}

