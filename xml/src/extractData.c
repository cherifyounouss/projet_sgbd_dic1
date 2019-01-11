#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "saveFile.c"

/**
 * printData:
 * *a_node: un noeud du fichier xml
 * 
 * La fonction récursive parcours les noeuds du fichier xml et y extrait des informations
 */

/*
*f est fichier dans lequel est sauvegardé les données extraites
*/
FILE *f;
/*
* entite est un tableau contenant l'ensemble des entités extraites
*/
s_entite *entite;
/*
* assoc est un tableau contenant l'ensemble des associations extraites
*/
s_assoc *assoc;

static void printData(xmlNode * a_node)
{
    xmlNode *cur_node = NULL;
    /*
     * On déplace le curseur de noeud à noeud pour recupérer des informations
     */

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        /*
        * On recupère le nom de l'élèment 
        */
        if (cur_node->type == XML_ELEMENT_NODE) {
            save_data(cur_node->name,f);
            // strcpy(entite->nom,cur_node->name);
                printf("Element: %s\n",cur_node->name);
            }
        /*
        * On recupére la valeur de l'élément
        */
        if (cur_node->type == XML_TEXT_NODE) {
                save_data(cur_node->content,f);
                printf("valeur: %s\n",cur_node->content);      
        }
            /*
            * Appel récursif
            */
            printData(cur_node->children);
    }
}

    /*
     * Un bloc main pour tester la fonction d'extraction
     */
int main(int argc, char **argv)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    if (argc != 2){
        fprintf(stderr,"Veuiller renseigner le fichier xml\n");
        return(1);
    }
    
    /*Analyse du fichier et recuperation de l'ensemble des noeuds */
    doc = xmlReadFile(argv[1], NULL, 0);

    if (doc == NULL) {
        printf("Erreur survenue lors de l'ouverture du fichier %s\n", argv[1]);
    }else{
        /*Recuperation du noeud racine*/
    root_element = xmlDocGetRootElement(doc);

    printData(root_element);

    /*On libére la variable doc */
    xmlFreeDoc(doc);

    /*
     * On libére les ressources libxml2 utilisées par la fonction.
     */
    xmlCleanupParser();
    }

    return 0;
}