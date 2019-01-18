#include <cairo/cairo.h>
#include <cairo/cairo-svg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../json/include/cJSON.h"
#include "../json/include/extraction_json.h"
#include "generation_svg.h"
#define LARGEUR 120
#define LONGUEUR 100
#define RADIUS 50


void generer_svg(char* json_file, char* svg_file, int count_t)
{

    /*Tableau pour stocker les entites*/
    s_entite** tab_entites = NULL;
    /*Tableau pour stocker les associations*/
    s_association** tab_associations = NULL;
    int nb_entites = 0, nb_associations = 0;
    cJSON* json = NULL;
    json = cJSON_Parse(chaine_json(json_file));
    get_nombre_entites_associations(json, &nb_entites, &nb_associations);
    tab_entites = malloc(nb_entites*sizeof(s_entite*));
    tab_associations = malloc(nb_associations*sizeof(s_association*));
    test(json, tab_entites, tab_associations);
    if (count_t) {
        printf("\n\nNombres d'entites: %d, nombres d'associations: %d\n\n", nb_entites, nb_associations);
        for(int i = 0; i < nb_entites; i++)
        {
            afficher_entite(tab_entites[i]);
        }
        printf("\n");
        for(int i = 0; i < nb_associations; i++)
        {
            afficher_association(tab_associations[i]);
        }
        
    }
    
    cairo_surface_t *surface;
    cairo_t *cr;
    char* attributs[] = {"id", "nom", "prenom"};
    double x = 20.0, y = 20.0, xc = 450, yc = 100;
    double x_swap = 0.0, y_swap = 0.0;
    int left_right = 0;
    surface = cairo_svg_surface_create(svg_file, 2560, 1707);
    cr = cairo_create(surface);

    cairo_set_source_rgba(cr, 0, 0, 0, 1);
    cairo_set_line_width(cr, 1);
    cairo_select_font_face(cr, "Purisa", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    for(int j = 0; j < nb_associations; j++)
    {
        dessiner_association(cr, xc, yc, RADIUS, tab_associations[j]->nom);
        cairo_move_to(cr, xc, yc+RADIUS*3);
        x_swap = xc; y_swap = yc;
        int pos_test = 0;
        cairo_get_current_point(cr, &xc, &yc);
        for(int i = 0; i < nb_entites; i++)
        {
            if(chercher_chaine(tab_entites[i]->associations, tab_associations[j]->nom, tab_entites[i]->n_associations) == 0){
                if((pos_test % 2) == 0){
                    left_right = 0;
                    dessiner_entite(cr, x, y, LARGEUR, LONGUEUR, tab_entites[i]->nom, tab_entites[i]->attributs, tab_entites[i]->n_attributs, left_right);
                    cairo_line_to(cr, x_swap - RADIUS, y_swap);
                    cairo_move_to(cr, x + 700, y);
                    cairo_get_current_point(cr, &x, &y);
                    pos_test++;
                }
                else{
                    left_right = 1;
                    dessiner_entite(cr, x, y, LARGEUR, LONGUEUR, tab_entites[i]->nom, tab_entites[i]->attributs, tab_entites[i]->n_attributs, left_right);
                    cairo_line_to(cr, x_swap + RADIUS, y_swap);
                    cairo_move_to(cr, x - 700, y + 150);
                    cairo_get_current_point(cr, &x, &y);
                    pos_test++;
                }
            }

        }
    }
    
    cairo_stroke(cr);
    // cairo_fill(cr);


    cairo_surface_destroy(surface);
    cairo_destroy(cr);

}

void dessiner_entite(cairo_t* cr, double x, double y, double width, double height, char* nom_entite, char* attributs[], int n_attributs, int left_right){
    int i = 0;
    double pos;
    double y2 = percentage(height, 30);
    pos = y2;
    cairo_rectangle(cr, x, y, width, height);
    cairo_rectangle(cr, x, y, width, y2);
    cairo_set_font_size(cr, 12);
    cairo_move_to(cr, x + 5, percentage(y+y2, 98));
    cairo_show_text(cr, nom_entite);
    cairo_set_font_size(cr,8);
    for(i = 0; i < n_attributs; i++)
    {
        cairo_move_to(cr, x + 5, y + pos + 10);
        cairo_show_text(cr, attributs[i]);
        pos += 10;
    }
    if(left_right == 0)
        cairo_move_to(cr, x + width, (2*y + height)/2.0);
    if(left_right == 1)
        cairo_move_to(cr, x, (2*y + height)/2.0);
    // cairo_rel_line_to(cr, 34, 67);
}

void dessiner_association(cairo_t* cr, double xc, double yc, double radius, char* nom){
    cairo_move_to(cr, xc + 50, yc);
    cairo_arc(cr, xc, yc, radius, 0, 2*M_PI);
    cairo_move_to(cr, xc - 10, yc);
    cairo_show_text(cr, nom);
    cairo_move_to(cr, xc, yc);
}

double percentage(double x, double per_cent){
    return (x * per_cent) / 100;
}

int chercher_chaine(char** associations, char* chaine, int n_associations){
    int j = 1;
    
    for(int i = 0; i < n_associations; i++)
    {
        j = strcmp(chaine, associations[i]);
        if(j == 0)
            break;
    }

    return j;
}