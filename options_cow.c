#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "options_cow.h"
#include "debug.h"

void affiche_vache(char *yeux, char *langue, int etat) {
    //Change les yeux et la langue en fonction de l'état
    if (etat == 0) {
        sscanf("xx\0", "%s", yeux);
        sscanf("U", "%s", langue);
        langue[1] = ' ';
        langue[2] = '\0';
    }
    if (etat == 1) {
        sscanf("--\0", "%s", yeux);
        sscanf("u", "%s", langue);
        langue[1] = ' ';
        langue[2] = '\0';
    } else if (etat == 2) {
        sscanf("oo\0", "%s", yeux);
        langue[0] = ' ';
        langue[1] = ' ';
        langue[2] = '\0';
    }
    printf("        \\   ^__^\n         \\  (%s)\\_______ \n            (__)\\       )\\/\\\n             %s ||----w |\n                ||     ||\n", yeux, langue);
}

void update() { printf("\033[H\033[J");}

void gotoxy(int x, int y) { printf ("\033[%d;%dH",x,y);}

void affiche_infos_vache(char *yeux, char *langue, int jour, int stock, int etat) {
        update();
        printf("Jour %d |\n_______/\n", jour);
        affiche_vache(yeux, langue, etat);

        printf("Stock: %d\n", stock);
}