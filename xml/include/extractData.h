/*
 * fonction d'extraction des données du fichier xml
 */
void printData(xmlNode * a_node);

/*
 * Fonction d'enregistrement des données extraites dans un fichier
 */
void save_data(const xmlChar *data,FILE *fic);

/*
 * Fonction de récupération des nombres d'entites et d'associations décrites dans le fichier xml
 */
void generer_nb_entites_association(int *nb_entites,int *nb_assos);

/*
 * nombre d'entites
 */
typedef int nb_entites;

/*
 * nombre d'associations
 */
typedef int nb_assos;

/*
 * Une structure entite 
 */
typedef struct s_entite{
    /* data */
    char *nom;
    char **attribut;
    char **associations;
    int nb_assoc;
    int nb_attributs;

}s_entite;

/*
 * Une structure association
 */
typedef struct s_assoc{
    /* data */
    char *nom;
    char **attribut;
    int nb_attributs;

}s_assoc;
