#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>    
#include "../include/extractData.h"

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
// s_entite *entite;
/*
* assoc est un tableau contenant l'ensemble des associations extraites
*/
// s_assoc *assoc;
// nb_entites n_entite;
// nb_assos n;

void printData(xmlNode * a_node)
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
                // printf("Element: %s\n",cur_node->name);
                // if(strcmp(cur_node->name,"entite") == 0){
                //     strcpy(entite->nom,cur_node->name);
                //     entite->nb_assoc++;
                //     n_entite++;
                // }
                // if(strcmp(cur_node->name,"association") == 0){
                //     strcpy(assoc->nom,cur_node->name);
                //     n++;
                // }
            }
        /*
        * On recupére la valeur de l'élément
        */
        if (cur_node->type == XML_TEXT_NODE) {
                save_data(cur_node->content,f);
                // printf("valeur: %s\n",cur_node->content);      
        }
            /*
            * Appel récursif
            */
            printData(cur_node->children);
            // generer_nb_entites_association(n_entite,n);
    }
}

