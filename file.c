#include <stdio.h>
#define COLONNA 25
#define RIGA 25
#define VITA 1
#define MORTE 0


/*


// Si tratta de il Gioco della vita di J. Conway.

//Descrizione:

//Si tratta in realtà di un gioco senza giocatori, intendendo che la sua evoluzione è determinata dal suo stato iniziale, senza necessità di alcun input da parte di gio//catori umani. Si svolge su una griglia di caselle quadrate (celle) che si estende all'infinito in tutte le direzioni; questa griglia è detta mondo. Ogni cella ha 8 vi//cini, che sono le celle ad essa adiacenti, includendo quelle in senso diagonale. Ogni cella può trovarsi in due stati: viva o morta (o accesa e spenta, on e off). Lo //stato della griglia evolve in intervalli di tempo discreti, cioè scanditi in maniera netta. Gli stati di tutte le celle in un dato istante sono usati per calcolare 
//lo stato delle celle all'istante successivo. Tutte le celle del mondo vengono quindi aggiornate simultaneamente nel passaggio da un istante a quello successivo: passa// così una generazione.
//
//Le transizioni dipendono unicamente dallo stato delle celle vicine in quella generazione:
//
//    Qualsiasi cella viva con meno di due celle vive adiacenti muore, come per effetto d'isolamento;
//    Qualsiasi cella viva con due o tre celle vive adiacenti sopravvive alla generazione successiva;
//    Qualsiasi cella viva con più di tre celle vive adiacenti muore, come per effetto di sovrappopolazione;
//    Qualsiasi cella morta con esattamente tre celle vive adiacenti diventa una cella viva, come per effetto di riproduzione.  

//    Breve escrizione tratta da: Wikipedia.it



//giorgio1985.


*/

typedef int costruisciTabella[COLONNA][RIGA];



//qui scriverò i prototipi... e ci sara in futuro una funzione che stampa su file void stampaSuFile()...





void stampaTabella(costruisciTabella tabella) {
int colonna,riga;
for (colonna = 0; colonna < COLONNA; colonna++) {
for (riga = 0; riga < RIGA; riga++) {
if (tabella[colonna][riga] == VITA) {
printf("X"); //indico cn X le celle vive, - altrimenti
} else {
printf("-");
}
}
printf("\n");
}
printf("\n");
}





void pulisciTabella(costruisciTabella tabella) {
int colonna, riga;
for (colonna = 0; colonna < COLONNA; colonna++) {
for (riga = 0; riga < RIGA; riga++) {
tabella[colonna][riga] = MORTE;
}
}
}









void opzioneTabella(costruisciTabella miaTabella) {
int i,n;
int colonna, riga;
printf("Scegli il numero di organismi/celle vive con cui vuoi iniziare\n ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
printf("Dimensioni x y di organismi viventi pari a : %d\n", i + 1);
scanf("%d %d", &colonna, &riga);
miaTabella[colonna][riga] = VITA;
}
stampaTabella(miaTabella);
printf("Generation 0");
}







int celleVicine(costruisciTabella tabella, int row, int cols) { // questa funzione mi servirà x dopo
if (( row < 0 || row >= COLONNA) || (cols < 0 || cols >= RIGA) || (tabella[row][cols] != VITA )){
return 0;
} 
else {return 1;
}
}







int conteggioCelleVicine(costruisciTabella tabella, int row, int cols) {
int vicini = 0;
vicini += celleVicine(tabella, row - 1, cols - 1);
//richiama la funzione celleVicine
vicini += celleVicine(tabella, row - 1, cols);
vicini += celleVicine(tabella, row - 1, cols + 1);
vicini += celleVicine(tabella, row, cols - 1);
vicini += celleVicine(tabella, row, cols + 1);
vicini += celleVicine(tabella, row + 1, cols - 1);
vicini += celleVicine(tabella, row + 1, cols);
vicini += celleVicine(tabella, row + 1, cols + 1);
return vicini;
}








void calcola(costruisciTabella miaTabella) { //miaTabella di tipo costruisciTabella
costruisciTabella miaTabella2;
int vicini, colonna, righe;
for (colonna = 0; colonna < COLONNA; colonna++) {
for (righe = 0; righe < RIGA; righe++) {vicini = conteggioCelleVicine(miaTabella, colonna, righe);
if (vicini==3) {
miaTabella2[colonna][righe] = VITA;
} else if (vicini == 2 && miaTabella[colonna][righe] == VITA) {
miaTabella2[colonna][righe] = VITA;
} else {
miaTabella2[colonna][righe] = MORTE;
}
}
}
for (colonna = 0; colonna < COLONNA; colonna++) {
for (righe = 0; righe < RIGA; righe++) {
miaTabella[colonna][righe] = miaTabella2[colonna][righe];
}}
}








void configurazioneIniziale(costruisciTabella tabella) {
// configurazione di prova
tabella[3][4] = VITA;
tabella[3][5] = VITA;
tabella[3][6] = VITA;
tabella[4][4] = VITA;
tabella[5][4] = VITA;
// prova
tabella[10][4] = VITA;
tabella[10][5] = VITA;
tabella[10][6] = VITA;
}








int main(void) {
costruisciTabella tabella;
char fine;
// da rivedereint generazioneFutura = 0;
pulisciTabella(tabella);
opzioneTabella(tabella); // funzione da sistemare...
configurazioneIniziale(tabella);
stampaTabella(tabella);
//stampaSufile();
do {
//prima calcolo e stampo ...poi fino a quando non si preme il tasto q vva avanti
calcola(tabella);
stampaTabella(tabella) ;
// stampaSufile();
printf("Generazione %d\n", ++generazioneFutura);
printf("premi il tasto q = quit per uscire, tasto 1 per continuare\n ");
scanf(" %c", &fine);
} while (fine != 'q') ;
return 0;
}
