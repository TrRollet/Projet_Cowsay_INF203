#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "options_cow.h"
#include "debug.h"

#define BYEBYELIFE 0
#define LIFESUCKS 1
#define LIFEROCKS 2

int stock = 5;
int fitness = 5;

// Variables pour les statistiques
int totalEtats = 0;
int totalNouriture = 0;
int totalFitness = 0;
int totalStock = 0;

int stock_update(int lunchfood) {
    int a = rand() % 4;
    int b = rand() % 4;
    int crop = a - b;

    if (crop > 3) {
        crop = 3;
    }
    
    int new_stock = (stock - lunchfood) + crop;
    if (new_stock < 0) {
        new_stock = 0;
    } else if (new_stock > 10) {
        new_stock = 10;
    }

    return new_stock;
}

int fitness_update(int lunchfood) {
    int digestion = rand() % 4;
    int new_fitness = (fitness+lunchfood)-digestion;

    return new_fitness;
}

int main() {
    time_t t ;
    srand((unsigned) time(&t));

    int etat = LIFEROCKS;
    int duree_de_vie = 1;
    int lunchfood = 0;
    char yeux[3] = "oo\0";
    char langue[3] = "  \0";
    
    while (etat != BYEBYELIFE) {
        
        update();
        affiche_infos_vache(yeux, langue, duree_de_vie, stock, etat);
        debug("DEBUG: État: %d, Fitness: %d\n", etat, fitness);

        printf("Entrez une quantité de nouriture (<= stock et >=0):\n");
        scanf("%d", &lunchfood);
        while (lunchfood < 0 || lunchfood > stock) {
            scanf("%d", &lunchfood);
        }
        
        stock = stock_update(lunchfood);
        fitness = fitness_update(lunchfood);
        totalFitness += fitness;
        totalStock += stock;
        totalNouriture += lunchfood;
        
        if (fitness <= 0 || fitness >= 10) {
            etat = BYEBYELIFE;
            totalEtats++;
        } else if ((fitness >= 1 && fitness <= 3) || (fitness >= 7 && fitness <= 9)) {
            etat = LIFESUCKS;
            totalEtats++;
        } else if (fitness >= 4 && fitness <= 6) {
            etat = LIFEROCKS;
            totalEtats++;
        }
        
        duree_de_vie++;
    }
    
    char raison[20] = "faim\0";
    if (fitness >= 10) {
        sscanf("suralimentation\0", "%s", raison);
    }

    update();
    affiche_vache(yeux, langue, etat);
    printf("Votre vache est morte de %s, vous avez réussi à la garder en vie pendant %d jours.\n", raison, duree_de_vie);
    printf("\nStatistiques:\n- Vous avez mangé %d de nourritures, ce qui fait une moyenne de %.3f nourriture par jour.\n- Nombre de changements d'état: %d\n- Niveau de fitness accumulé: %d\n- Total du stock que vous avez accumulé: %d\n", totalNouriture, (float)totalNouriture / (float)duree_de_vie, totalEtats, totalFitness, totalStock);
    return 0;
}