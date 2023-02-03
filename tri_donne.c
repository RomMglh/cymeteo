#include <avl.h>
#include <avl.c>

int main(int argc, char *argv[]) {
    int ret_code = 0;

    char *input_file = argv[1];
    char *output_file = argv[2];
    int nb_lignes = atoi(argv[3]);
    char *type_donne = argv[4];
    
    char tab[nb_lignes];
    pAVL AVL;
    float val1=0.0;
    float val2=0.0;
    int num_station;
    float lon;
    float lat;
    int i=0;
    int h=0;
    
    
    // Vérification des options activées
    if (argc != 3) {
    	ret_code = 1;
    	goto fin;
    }

    // Ouvrir les fichiers en lecture et en écriture
    FILE *fp_in = fopen(input_file, "r");
    FILE *fp_out = fopen(output_file, "a");

    if (fp_in == NULL) {
    	ret_code = 2;
    	goto fin;
    }
    
    if (fp_out == NULL) {
    	ret_code = 3;
    	goto fin;
    }
    
    if (type_donne == "-w"){
        for (i = 0; i < nb_lignes; i++){
           if(fgets(tab, nb_lignes, fp_in) != NULL){
           	fscanf(fp_in, "%ls,%f,%f,%f,%f" ,&num_station, &val1, &val2, &lon, &lat);
           	AVL = insertionAVL_w(AVL, val1, val2, num_station, lon, lat, &h);
           	equilibrerAVL(AVL);
           }
        }
        return_fichier_C(AVL, fp_out);
    }
    
    if (type_donne == "-m"){
        for (i = 0; i < nb_lignes; i++){
           if(fgets(tab, nb_lignes, fp_in) != NULL){
           	fscanf(fp_in, "%ls,%f,%f,%f" ,&num_station, &val1, &lon, &lat);
           	AVL = insertionAVL_h_m(AVL, val1, val2, num_station, lon, lat, &h);
           	equilibrerAVL(AVL);
           }
        }
        return_fichier_DC(AVL, fp_out);
    }
    if (type_donne == "-h"){
    	for (i = 0; i < nb_lignes; i++){
           if(fgets(tab, nb_lignes, fp_in) != NULL){
           	fscanf(fp_in, "%ls,%f,%f,%f" ,&num_station, &val1, &lon, &lat);
           	AVL = insertionAVL_h_m(AVL, val1, val2, num_station, lon, lat, &h);
           	equilibrerAVL(AVL);
           }
        }
        return_fichier_DC(AVL, fp_out);
    }


fin:
    // Fermeture des fichiers
    if (fp_in != NULL) {
    	fclose(fp_in);
    }
    if (fp_out != NULL) {
    	fclose(fp_out);
    }

    // Retour du code d'erreur
    return ret_code;
}
