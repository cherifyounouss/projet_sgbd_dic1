#include <stdio.h>
#include <cairo/cairo.h>
#include <cairo/cairo-svg.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>    
#include "../include/extractData.h"
#include "../../svg/generation_svg.h"
#define LARGEUR 120
#define LONGUEUR 100
#define RADIUS 50
// #include "../../svg/generation_svg.h"
/*
*f est fichier dans lequel est sauvegardé les données extraites
*/
FILE *f;
/*
* entite est un tableau contenant l'ensemble des entités extraites
*/
int nb_entites=0;
// s_entite **entite;
// entite = malloc(sizeof(entite->nom)+sizeof);
/*
* assoc est un tableau contenant l'ensemble des associations extraites
*/
// s_assoc **assoc;
// int i=0;
// nb_assos n;
/*
 * extractionData:
 * *filename: un fichier xml
 * 
 * La fonction lit un fichier xml et y extrait des informations
 */
void extractionData(char *filename){
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
      printf("Erreur survenue lors de l'ouverture du fichier %s\n", filename);
    }else{
        /*Recuperation du noeud racine*/
        root_element = xmlDocGetRootElement(doc);

        /*Recupération du nombre d'entités dans le fichhier xml*/
        nb_entites= nombre_entite(root_element);

        printData(root_element);
        printf("L'extraction dans %s a été un succés\n", filename);
    }
}
/*
 * printData:
 * *a_node: un noeud du fichier xml
 * 
 * La fonction récursive parcours les noeuds du fichier xml et y extrait des informations
 */
void printData(xmlNode * a_node)
{
    xmlNode *cur_node = NULL, *childNode = NULL;
    xmlChar *entete;
    /*
     * On déplace le curseur de noeud à noeud pour recupérer des informations
     */

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        /*
        * On recupère le nom de l'élèment 
        */
        if (cur_node->type == XML_ELEMENT_NODE) {
            save_data(cur_node->name,f);
           
        }
            /*
            * Appel récursif
            */
        //    i++;
            printData(cur_node->children);
    }
}

int nombre_entite(xmlNode *root){

    int nbEntites = 0;

    while(root!= NULL){
        if(strcmp(root->name,"entite") == 0)
            nbEntites++;
        root = root->next;
    }

    return nbEntites;
}

void creerEntite(xmlChar *name){

         /********************************/
               cairo_surface_t *surface;
                cairo_t *cr;
                char* attributs[] = {"id", "nom", "prenom"};
                double x = 20.0, y = 20.0, xc = 450, yc = 100;
                double x_swap = 0.0, y_swap = 0.0;
                int left_right = 0;
                surface = cairo_svg_surface_create("FILE.svg", 2560, 1707);
                cr = cairo_create(surface);

                cairo_set_source_rgba(cr, 0, 0, 0, 1);
                cairo_set_line_width(cr, 1);
                cairo_select_font_face(cr, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
                int i = 0;
                double pos;
                double y2 = percentage(LARGEUR, 30);
                pos = y2;
                cairo_rectangle(cr, x, y, LONGUEUR, LARGEUR);
                cairo_rectangle(cr, x, y, LONGUEUR, y2);
                cairo_set_font_size(cr, 12);
                cairo_move_to(cr, x + 5, percentage(y+y2, 98));
                cairo_show_text(cr, name);
                cairo_set_font_size(cr,8);
                for(i = 0; i < 3; i++)
                {
                    cairo_move_to(cr, x + 5, y + pos + 10);
                    cairo_show_text(cr, attributs[i]);
                    pos += 10;
                }
                if(left_right == 0)
                    cairo_move_to(cr, x + LONGUEUR, (2*y + LARGEUR)/2.0);
                if(left_right == 1)
                    cairo_move_to(cr, x, (2*y + LARGEUR)/2.0);
                cairo_line_to(cr, x_swap - RADIUS, y_swap);
                cairo_move_to(cr, x + 700, y);
                cairo_get_current_point(cr, &x, &y);
                cairo_stroke(cr);
                cairo_surface_destroy(surface);
                cairo_destroy(cr);
            /********************************/

}






