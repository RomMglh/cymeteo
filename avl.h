#include <stdio.h>
#include <stdlib.h>

typedef struct AVL{
    float val1;
    float val2;
    int num_station;
    float lon;
    float lat;
    struct AVL* fg;
    struct AVL* fd;
    int equilibre;
}AVL;

int max(int a,int b,int c);
int min(int a, int b);
float max_float(float a, float b);
pAVL creerArbre(float val1, float val2, int num_station, float lon, float lat);
pAVL insertionAVL_h_m(pAVL a, float val1, float val2, int num_station, float lon, float lat, int* h);
pAVL insertionAVL_w(pAVL a, float val1, float val2, int num_station, float lon, float lat, int* h);
pAVL rotationDroite(pAVL a);
pAVL rotationGauche(pAVL a);
pAVL rotationDoubleDroite(pAVL a);
pAVL rotationDoubleGauche(pAVL a);
int existeFilsGauche(pAVL a);
int existeFilsDroit(pAVL a);
pAVL equilibrerAVL(pAVL a);
void return_fichier_C(pAVL a, FILE* fichier);
void return_fichier_DC(pAVL a, FILE* fichier);
