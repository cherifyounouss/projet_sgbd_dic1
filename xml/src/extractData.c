#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
// #include <libxml/tree1.h>
#include "../include/libxml/tree1.h"

int main(int argc, char **argv)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    if (argc != 2){
        fprintf(stderr,"Veuiller renseigner le fichier xml\n");
        return(1);
    }
    
    /*parse the file and get the DOM */
    doc = xmlReadFile(argv[1], NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", argv[1]);
    }else{
        /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    print_element_names(root_element);

    /*free the document */
    xmlFreeDoc(doc);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();
    }

    return 0;
}