#include <stdio.h>
#include <libxml/xmlstring.h>
#include <string.h>
#include <libxml/tree.h>
#include "../include/extractData.h"

void save_data(const xmlChar *data,FILE *fic){

    fic=fopen("saveFile.txt","a+");

    fprintf(fic,"%s\n",data);
   
    fclose(fic);
}



