#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define pass_giusta "galilei"  //password corretta

//dichiarazione variabili
char pass_ins[50]; //password inserita
int chiave;
int c = 0;  //contatore tentativi password
char testo1[100];  //testo da crittografare
char testo2[100]; //testo crittografato
char ch, t; //switch case

//procedura crittografia
void crittografia() {
    int i;
    for (i = 0; testo1[i] != '\0'; i++) {
        if (testo1[i] >= 'A' && testo1[i] <= 'Z') {
            testo2[i] = (testo1[i] - 'A' + chiave) % 26 + 'A';
        }
        else if (testo1[i] >= 'a' && testo1[i] <= 'z') {
            testo2[i] = (testo1[i] - 'a' + chiave) % 26 + 'a';
        }
        else {
            testo2[i] = testo1[i];  // Copia spazi e altri caratteri
        }
    }
    testo2[i] = '\0'; // Terminatore della stringa
}

//decrittografia
void decrittografia() {
    int i;
    for (i = 0; testo1[i] != '\0'; i++) {
        if (testo1[i] >= 'A' && testo1[i] <= 'Z') {
            testo2[i] = (testo1[i] - 'A' - chiave + 26) % 26 + 'A';
        }
        else if (testo1[i] >= 'a' && testo1[i] <= 'z') {
            testo2[i] = (testo1[i] - 'a' - chiave + 26) % 26 + 'a';
        }
        else {
            testo2[i] = testo1[i];  // Copia spazi e altri caratteri
        }
    }
    testo2[i] = '\0'; // Termina la stringa
}

int main() {
    // Verifica della password
    printf("Buongiorno.\n");
Acquisizione_password:
        printf("Inserisca la password per entrare. \n");
        scanf("%s", pass_ins);

        if (strcmp(pass_ins, pass_giusta) == 0) {
            printf("La password è corretta.\n\n");}
        else {
            printf("La password è errata. Ritenti.\n\n");
            c++;
            if (c==3) {
                printf("Ha fatto troppi tentativi. Arrivederci.\n");
                exit(0);}
            else{goto Acquisizione_password;}
        }

Inizio:
//critt o decritt?
switchcase1:
printf("Vuole fare una crittografia (c) o una decrittografia (d)?\n");
scanf(" %c", &ch);
if (ch != 'c' && ch != 'd'){goto switchcase1;}

// Acquisizione della chiave
Acquisizione_chiave:
printf("Inserisca la chiave da 1 a 25 per la crittografia o decrittografia.\n");
scanf("%d", &chiave);
   
if (chiave < 1 || chiave > 25) {
    printf("Chiave non nell'intervallo richiesto. Ritenti.\n\n");
    goto Acquisizione_chiave;}

switch(ch){

//crittografia
case 'c':
printf("Inserisca il testo da crittografare.\n");
getchar(); // per consumare il newline lasciato da scanf precedente
fgets(testo1, sizeof(testo1), stdin);
testo1[strcspn(testo1, "\n")] = '\0'; // rimuove il newline finale
crittografia();
printf("Testo crittografato: %s\n\n", testo2);
break;
    
//decrittografia
case 'd':
printf("Inserisca il testo da decrittografare.\n");
getchar(); // per consumare il newline lasciato da scanf precedente
fgets(testo1, sizeof(testo1), stdin);
testo1[strcspn(testo1, "\n")] = '\0'; // rimuove il newline finale
decrittografia();
printf("Testo decrittografato: %s\n\n", testo2);
break;}

switchcase2:
printf("Vuole fare un'altra crittografia o decrittografia? (s/n)\n");
scanf(" %c", &t);
switch(t){
case 's':
goto Inizio;
case 'n':
printf("Arrivederci.");
exit(0);
default:
goto switchcase2;}
}
