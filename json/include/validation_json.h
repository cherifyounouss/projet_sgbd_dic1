/*  Fonction pour tester la validite du fichier json
*   Valeur de retour: 0 si la validation reussi
*/
int est_valide(char* filename);

/* Cette fonction permet de creer un fichier dont le nom est fichier_flux et d'y stocker le resultat
* de la requete http
*/
void flux_vers_fichier(char* flux_http);