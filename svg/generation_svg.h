void dessiner_entite(cairo_t* cr, double x, double y, double width, double height, char* nom_entite, char* attributs[], int n_attributs, int left_right);
double percentage(double x, double per_cent);
void dessiner_association(cairo_t* cr, double xc, double yc, double radius, char* nom);
int chercher_chaine(char** attributs, char* chaine, int n_attributs);
void generer_svg(char* json_file, char* svg_file, int count_t);