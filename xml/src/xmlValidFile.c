#include <stdio.h>
#include "../include/libxml/reader2.c"

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
