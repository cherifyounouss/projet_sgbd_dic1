/*
*               Entite
*Definition de la structure entite avec les champs suivants : 
* nom : Nom de l'entite
* attributs :  Tableau devant contenir les attributs de l'entite
* n_attributs : Nombre d'attributs
* associations : Tableau devant contenir le nom des associations dans lesquelles participe l'entite
* n_associations : Nombre d'associations
*/
struct entite
{
    char* nom;
    char** attributs;
    int n_attributs;
    char** associations;
    int n_associations;
};

/*
*                  Association
*Definition de la structure associaton avec les champs suivants : 
* nom : Nom de l'association
* attributs :  Tableau devant contenir les attributs de l'association
* n_attributs : Nombre d'attributs
* nom : Nom de l'entite
*/
struct association
{
    char* nom;
    char** attributs;
    int n_attributs;
};

typedef struct entite s_entite;
typedef struct association s_association;

/* Fonction permettant de parcourir un fichier et de retourner le contenu sous format chaine de caracteres*/
char* chaine_json(char *filename);

/* Fonction permettant de recuperer le nombre d'entites et le nombre d'associations */
void get_nombre_entites_associations(cJSON* json, int* nb_entites, int* nb_associations);

/* Fonction permettant de recuperer les attributs d'une entite */
char** get_attributs_entite(cJSON* json, char** attributs, int* n_attributs);

/* Fonction permettant de recuperer les attributs d'une association*/
char** get_attributs_association(cJSON* json, char** attributs, int* n_attributs);

/* Fonction permettant de parcourir le premier niveau du fichier json */
void test(cJSON* json, s_entite** tab_entites, s_association** tab_associations);

/* Fonction permettant de recuperer les associations auxquelles participe une entite */
char** get_associations(cJSON* json, cJSON* parent, char** associations, int* n_associations);

/* Fonction permettant d'afficher une entite */
void afficher_entite(s_entite* entite);

/* Fonction permettant d'afficher une association */
void afficher_association(s_association* association);

/* Fonction qui cree et retourne une entite */
s_entite* creer_entite(s_entite* e, char* nom, char** attributs, char** associations, int n_attributs, int n_associations);

/* Fonction qui cree et retourne une association */
s_association* creer_association(s_association* a, char* nom, char** attributs, int n_attributs);

/* Fonction pour realiser l'extraction d'entites et d'associations et leur stockage au niveau d'un tableau */
void extraction(char* arg_json, s_entite** tab_entites, s_association** tab_associations, int* nb_entites, int* nb_associations);

/* Fonction pour realiser le parcours recursive de l'arborescence du fichier json */
void test2(cJSON* json, s_entite** tab_entites, s_association** tab_associations);