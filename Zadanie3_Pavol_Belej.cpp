#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

//makro ktore reprezentuje nekonecno
//N - neprekonatelna prekazka
//C - cesta, cas prechodu/cena = 1
//H - husty les, cas prechodu/cena = 2
//D - drak
//P - princezna/e, max 5
#define INFINITY INT_MAX


//funkcie pre binarnu haldu

//pomocna klasicka swap funkcia
void prehod_hodnoty(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

typedef struct policko {
	int x_suradnica;
	int y_suradnica;
	int vzdialenost;
	struct policko* predosle;
	char navstiveny;

} POLICKO;

struct heap {
	POLICKO** heap_array;
	int* vzdialenosti;
};	
//funkcie
POLICKO* vloz_policko(int x_ova, int y_ova, int vzdialenost);
struct heap* initialize_heap(int m, int n);
int generuj_susedov(int x_ova, int y_ova);


int rodic(int p) {
	return ((p - 1) / 2);
}
int pravy_potomok(int p) {
	return (p * 2) + 1;
}
int lavy_potomok(int p) {
	return (p * 2) + 2;
}

struct heap* initialize_heap(int m, int n) {

	struct heap* halda = (struct heap*)malloc(sizeof(struct heap));
	halda->heap_array = (POLICKO**)malloc(m * n * sizeof(POLICKO));
	halda->vzdialenosti = (int*)malloc(m * n * sizeof(int));
	for (int i = 1;i < m * n;i++)
		halda->vzdialenosti[i] = INFINITY;
	halda->vzdialenosti[0] = 0;
	return halda;
}

void zmensi_kluc(int kluc, int novy_kluc) {

}

POLICKO* vloz_policko(int x_ova, int y_ova, int vzdialenost) {

	POLICKO* p = (POLICKO*) malloc(sizeof(POLICKO));
	p->x_suradnica = x_ova;
	p->y_suradnica = y_ova;
	p->vzdialenost = vzdialenost;
	p->predosle = NULL;
	return p;
};
//vracia hodnoty posunu pri navstevovani susedov
int generuj_susedov(int x_ova, int y_ova) {
	int smer[4][2];
	//pravy sused
	smer[0][0] = 1;
	smer[0][1] = 0;
	//lavy sused
	smer[1][0] = -1;
	smer[1][1] = 0;
	//dolny sused
	smer[2][0] = 0;
	smer[2][1] = 1;
	//horny sused
	smer[3][0] = 0;
	smer[3][1] = -1;
	return smer[x_ova][y_ova];
}

//n - sirka, m - vyska, t - za kolko casovych jednotiek sa drak prebudi
/*int**/void zachran_princezne(char** mapa, int n, int m,int t, int* dlzka_cesty) {
	//nacitaj mapu
	//nejaky for loop
		//zaciatok na 0,0
	int x = 0;
	int y = 0;
		for (int j = 0; j < 4;j++) {
			int newx = x + generuj_susedov(j, 0);
			int newy = y + generuj_susedov(j, 1);
			if ((newx >= 0 && newx < n) && (newy >= 0 && newy < m) && mapa[newx][newy] != 'N') {


			}
		}
		//navstiv susedov
		//ked sused je 

}
int main() {
	struct heap* halda = initialize_heap(5, 5);
	for (int i = 0;i < 5 * 5;i++)
		printf("%d: %d\t", i, halda->vzdialenosti[i]);
	char** mapa = (char**)malloc(5 * 5 * sizeof(char));
	int dlzka = 0;
	zachran_princezne(mapa, 5, 5, 10, &dlzka);
	int x = generuj_susedov(1, 0);
	int y = generuj_susedov(1, 1);
	printf("x: %d y: %d", x, y);
	return 0;
	printf("toto je zmena\n");
}