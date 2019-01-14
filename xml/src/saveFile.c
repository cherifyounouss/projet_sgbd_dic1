#include <stdio.h>
#include <libxml/xmlstring.h>
#include <string.h>
#include <libxml/tree.h>
#include "../include/extractData.h"

void save_data(const xmlChar *data,FILE *fic){

    fic=fopen("saveFile.txt","a+");

    // if (strcmp(data,"") == 0){
    //     exit(1);
    // }
    // fseek(fic,5,0);
    fprintf(fic,"%s\n",data);
    // rewind(fic);
    fclose(fic);
}

