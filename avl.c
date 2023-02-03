#include "avl.h"

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


typedef AVL* pAVL;


int max(int a,int b,int c){
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c)return b;
    else (c>=b && c>=a);
    return c;
}


int min(int a, int b){
    if(a<=b)return a;
    else 
    	return b;
}


float max_float(float a, float b){
    if(a<=b)return a;
    else return b;
}


pAVL creerArbre(float val1, float val2, int num_station, float lon, float lat){
    pAVL noeud =malloc(sizeof(AVL));
    noeud->val1 = val1;
    noeud->val2 = val2;
    noeud->num_station = num_station;
    noeud->lon = lon;
    noeud->lat = lat;
    noeud->fg=NULL;
    noeud->fd=NULL;
    noeud->equilibre=0;
    return noeud;
}


pAVL insertionAVL_h_m(pAVL a, float val1, float val2, int num_station, float lon, float lat, int* h){
	if(a == NULL){
		*h = 1;
		return creerArbre(val1, val2, num_station, lon, lat);
	}
	if(num_station == a->num_station){
		a->val1 = max_float(a->val1, val1);
		return a;
	}
	else if(val1 < a->val1){
		a->fg = insertionAVL_h_m(a->fg, val1, val2, num_station, lon, lat, h);
		*h = -*h;
	}
	else if(val1 > a->val1){
		a->fd = insertionAVL_h_m(a->fd, val1, val2, num_station, lon, lat, h);
	}
	else{
		*h = 0;
		return a;
	}
	if(*h != 0){
		a->equilibre = a->equilibre + *h;
		if(a->equilibre == 0){
			*h = 0;
		}
		else{
			*h = 1;
		}
	}
	return a;
}


pAVL insertionAVL_w(pAVL a, float val1, float val2, int num_station, float lon, float lat, int* h){
	if(a == NULL){
		*h = 1;
		return creerArbre(val1, val2, num_station, lon, lat);
	}
	else if(num_station < a->num_station){
		a->fg = insertionAVL_w(a->fg, val1, val2, num_station, lon, lat, h);
		*h = -*h;
	}
	else if(num_station > a->num_station){
		a->fd = insertionAVL_w(a->fd, val1, val2, num_station, lon, lat, h);
	}
	else if(num_station == a->num_station){
		a->val1 = a->val1 + val1;
		a->val1 = a->val1 / 2
		a->val2 = a->val2 + val2;
		a->val1 = a->val2 / 2
		*h = 0;
		return a;
	}
	if(*h != 0){
		a->equilibre = a->equilibre + *h;
		if(a->equilibre == 0){
			*h = 0;
		}
		else{
			*h = 1;
		}
	}
	
	return a;
}


pAVL rotationDroite(pAVL a){
    pAVL pivot;
    int eq_a,eq_p;
    pivot=a->fg;
    a->fg=pivot->fd;
    pivot->fd=a;
    eq_a=a->equilibre;
    eq_p=pivot->equilibre;
    a->equilibre=eq_a-min(eq_p,0)+1;
    pivot->equilibre=max(eq_a+2,eq_a+eq_p+2,eq_p+1);
    a=pivot;
    return a;
}


pAVL rotationGauche(pAVL a){
    pAVL pivot;
    int eq_a,eq_p;
    pivot=a->fd;
    a->fg=pivot->fg;
    pivot->fg=a;
    eq_a=a->equilibre;
    eq_p=pivot->equilibre;
    a->equilibre=eq_a-min(eq_p,0)+1;
    pivot->equilibre=max(eq_a+2,eq_a+eq_p+2,eq_p+1);
    a=pivot;
    return a;
}


pAVL rotationDoubleDroite(pAVL a){
    a->fg=rotationGauche(a->fg);
    return rotationDroite(a);
}


pAVL rotationDoubleGauche(pAVL a){
    a->fg=rotationDroite(a->fd);
    return rotationGauche(a);
}


int existeFilsGauche(pAVL a){
    if(a==NULL){
        exit(1);
        }
    if(a->fg!=NULL){
        return  1;
    }
    else{
        return 0;
    }
}


int existeFilsDroit(pAVL a){
    if(a==NULL){
        exit(1);
        }
    if(a->fd!=NULL){
        return  1;
    }
    else{
        return 0;
    }
}


pAVL equilibrerAVL(pAVL a){
	if(a->equilibre >= 2){
		if(a->fd->equilibre >= 0){
			return rotationGauche(a);
		}
		else{
			return rotationDoubleGauche(a);
		}
	}
	else if(a->equilibre <= -2){
		if(a->fg->equilibre <= 0){
			return rotationDroite(a);
		}
		else{
			return rotationDoubleDroite(a);
		}
	}
	return a;
		
}


void return_fichier_C(pAVL a, FILE* fichier){
	if(a != NULL){
		return_fichier_C(a->fg, fichier);
		fprintf(fichier, "%d\t%f\t%f\t%f\t%f\n" ,a->num_station, a->val1, a->val2, a->lon, a->lat);
		return_fichier_C(a->fd, fichier);
	}
}


void return_fichier_DC(pAVL a, FILE* fichier){
	if(a != NULL){
		return_fichier_DC(a->fd, fichier);
		fprintf(fichier, "%d\t%f\t%f\t%f\t%f\n" ,a->num_station, a->val1, a->val2, a->lon, a->lat);
		return_fichier_DC(a->fg, fichier);
	}
}
