#include <stdio.h>
#include <libxml/reader2.h>

/**
 * streamFile:
 * @filename: the file name to parse
 *
 * Parse, validate and print information about an XML file.
 */
static void
streamFile(const char *filename) {
    xmlTextReaderPtr reader;
    int ret;


    /*
     * Pass some special parsing options to activate DTD attribute defaulting,
     * entities substitution and DTD validation
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
	 * Once the document has been fully parsed check the validation results
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

int main(int argc, char **argv) {
    if (argc != 2){
        fprintf(stderr, "Veuiller renseigner le fichier xml\n");
    }

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    streamFile(argv[1]);

    /*
     * Cleanup function for the XML library.
     */
    xmlCleanupParser();
    /*
     * this is to debug memory for regression tests
     */
    xmlMemoryDump();
    return(0);
}
