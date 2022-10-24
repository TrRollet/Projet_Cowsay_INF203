#ifndef __OPTIONS_COW__
#define __OPTIONS_COW__

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void affiche_vache(char *yeux, char *langue, int etat);

void update();
void gotoxy(int x, int y);

void affiche_infos_vache(char *yeux, char *langue, int jour, int stock, int etat);
#endif

