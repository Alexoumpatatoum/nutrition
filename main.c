#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aliment {
    char nom[20];
    float proteine;
    float lipide;
    float glucide;
    float kcal;
    float quantite;
    float prix;
};

void ajouter_aliment(struct Aliment **aliments, int *taille, struct Aliment new_aliment) {
    *aliments = realloc(*aliments, (*taille + 1) * sizeof(struct Aliment));
    if (*aliments == NULL) {
        perror("Erreur de réallocation de mémoire");
        exit(EXIT_FAILURE);
    }
    (*aliments)[*taille] = new_aliment;
    (*taille)++;
}

int main() {
    int taille = 0;
    struct Aliment *aliments = NULL;

    struct Aliment aliments_initiaux[] = {
        {"poulet", 24, 3, 0, 165, 100, 2.5},
        {"boeuf", 21, 3.1, 0, 250, 100, 3.0},
        {"oeuf", 13, 11, 1.1, 155, 100, 0.2},
        {"fromage", 25, 33, 1.3, 400, 100, 2.0},
        {"lentille", 9, 0.4, 20, 116, 100, 1.5},
        {"tofu", 8, 5, 2.3, 76, 100, 2.0},
        {"quinoa", 14, 6, 64, 368, 100, 3.0},
        {"amande", 21, 50, 22, 575, 100, 4.0},
        {"noix", 15, 65, 14, 654, 100, 5.0},
        {"avocat", 2, 15, 9, 160, 100, 1.5},
        {"riz", 7, 1, 80, 130, 100, 0.5},
        {"pates", 5, 1.4, 75, 131, 100, 0.8},
        {"pain", 8, 1, 50, 265, 100, 1.0},
        {"pomme", 0.3, 0.4, 14, 52, 100, 0.3},
        {"banane", 1.3, 0.3, 22, 89, 100, 0.2},
        {"poire", 0.4, 0.3, 15, 57, 100, 0.3},
        {"orange", 1, 0.2, 12, 47, 100, 0.4},
        {"fraise", 0.8, 0.4, 7, 32, 100, 0.5},
        {"framboise", 1.3, 0.7, 5, 52, 100, 0.6},
        {"myrtille", 0.7, 0.4, 9, 57, 100, 0.7},
        {"cerise", 1, 0.3, 12, 50, 100, 0.8},
        {"porc", 21, 6, 0, 242, 100, 2.5},
        {"sanglier", 30, 6, 0, 300, 100, 3.5},
        {"canard", 19, 11, 0, 337, 100, 3.0},
        {"pintade", 24, 4, 0, 158, 100, 2.8},
        {"lapin", 21, 6, 0, 173, 100, 2.2},
        {"chevre", 20, 27, 0, 452, 100, 4.0},
        {"agneau", 20, 15, 0, 294, 100, 3.5},
        {"mouton", 20, 15, 0, 294, 100, 3.5},
        {"saumon", 20, 13, 0, 208, 100, 3.0},
        {"truite", 20, 5, 0, 148, 100, 2.5},
        {"thon", 24, 6, 0, 144, 100, 3.0},
        {"sardine", 24, 6, 0, 208, 100, 2.0},
        {"hareng", 18, 13, 0, 217, 100, 2.5},
        {"maquereau", 20, 13, 0, 205, 100, 2.5},
        {"anchois", 24, 6, 0, 131, 100, 3.0},
        {"crevette", 24, 6, 0, 99, 100, 2.5},
        {"crabe", 24, 6, 0, 87, 100, 3.0},
        {"langouste", 24, 6, 0, 112, 100, 4.0},
        {"homard", 24, 6, 0, 89, 100, 4.5},
        {"moule", 24, 6, 0, 86, 100, 2.0},
        {"calamar", 24, 6, 0, 92, 100, 2.5},
        {"poulpe", 24, 6, 0, 82, 100, 2.5},
        {"boeuf seche", 40, 5, 0, 410, 100, 5.0},
        {"jambon", 20, 5, 0, 145, 100, 2.0},
        {"saucisson", 20, 20, 0, 350, 100, 3.0},
        {"saucisse", 20, 20, 0, 300, 100, 2.5},
        {"chorizo", 20, 20, 0, 455, 100, 3.5},
        {"boudin", 20, 20, 0, 379, 100, 2.5},
        {"foie", 20, 5, 0, 133, 100, 2.0},
        {"rognon", 20, 5, 0, 103, 100, 2.0},
        {"cervelle", 20, 5, 0, 143, 100, 2.0},
        {"coeur", 20, 5, 0, 112, 100, 2.0},
        {"poumon", 20, 5, 0, 89, 100, 2.0},
        {"langue", 20, 5, 0, 224, 100, 2.0},
        {"tripes", 20, 5, 0, 85, 100, 2.0},
        {"pied", 20, 5, 0, 250, 100, 2.0}


    };

    int taille_initiaux = sizeof(aliments_initiaux) / sizeof(aliments_initiaux[0]);
    aliments = malloc(taille_initiaux * sizeof(struct Aliment));
    if (aliments == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    memcpy(aliments, aliments_initiaux, taille_initiaux * sizeof(struct Aliment));
    taille = taille_initiaux;

    char jours[7][10] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    char repas[3][10] = {"matin", "midi", "soir"};
    char choix[100];
    int i, j, k;

    float total_proteine_semaine = 0, total_lipide_semaine = 0, total_glucide_semaine = 0;

    for (i = 0; i < 7; i++) {
        float total_proteine_jour = 0, total_lipide_jour = 0, total_glucide_jour = 0;

        for (k = 0; k < 3; k++) {
            printf("Quels aliments voulez-vous manger pour %s (%s)? (séparez les aliments par des virgules, tapez 'stop' pour arrêter)\n", jours[i], repas[k]);
            scanf(" %[^\n]", choix);

            if (strcmp(choix, "stop") == 0) {
                printf("Arrêt du programme.\n");
                free(aliments);
                return 0;
            }

            char *token = strtok(choix, ",");
            while (token != NULL) {
                int found = 0;
                for (j = 0; j < taille; j++) {
                    if (strcmp(aliments[j].nom, token) == 0) {
                        total_proteine_jour += aliments[j].proteine;
                        total_lipide_jour += aliments[j].lipide;
                        total_glucide_jour += aliments[j].glucide;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Aliment non trouvé: %s\n", token);

                    char new_nom[20];
                    float new_proteine, new_lipide, new_glucide;

                    printf("Entrez le nom de l'aliment: ");
                    scanf("%s", new_nom);
                    if (strcmp(new_nom, "stop") == 0) {
                        printf("Arrêt du programme.\n");
                        free(aliments);
                        return 0;
                    }
                    printf("Entrez la quantité de protéines: ");
                    scanf("%f", &new_proteine);
                    printf("Entrez la quantité de lipides: ");
                    scanf("%f", &new_lipide);
                    printf("Entrez la quantité de glucides: ");
                    scanf("%f", &new_glucide);

                    struct Aliment new_aliment;
                    strcpy(new_aliment.nom, new_nom);
                    new_aliment.proteine = new_proteine;
                    new_aliment.lipide = new_lipide;
                    new_aliment.glucide = new_glucide;

                    ajouter_aliment(&aliments, &taille, new_aliment);
                    printf("Aliment ajouté: %s (Proteines: %.1f, Lipides: %.1f, Glucides: %.1f)\n", new_aliment.nom, new_aliment.proteine, new_aliment.lipide, new_aliment.glucide);
                }

                token = strtok(NULL, ",");
            }
        }

        printf("Total pour %s: Proteines: %.1f, Lipides: %.1f, Glucides: %.1f\n", jours[i], total_proteine_jour, total_lipide_jour, total_glucide_jour);
        total_proteine_semaine += total_proteine_jour;
        total_lipide_semaine += total_lipide_jour;
        total_glucide_semaine += total_glucide_jour;
    }

    printf("Total de la semaine: Proteines: %.1f, Lipides: %.1f, Glucides: %.1f\n", total_proteine_semaine, total_lipide_semaine, total_glucide_semaine);
    printf("Résumé de la semaine:\n");
    for (i = 0; i < 7; i++) {
        printf("%s: Proteines: %.1f, Lipides: %.1f, Glucides: %.1f\n", jours[i], total_proteine_semaine / 7, total_lipide_semaine / 7, total_glucide_semaine / 7);
    }

    free(aliments);
    
    printf("\nTableau récapitulatif de la semaine:\n");
    printf("Jour\t\tMatin\t\t\tMidi\t\t\tSoir\t\t\tTotal\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for (i = 0; i < 7; i++) {
        printf("%s\t", jours[i]);
        for (k = 0; k < 3; k++) {
            printf("Proteines: %.1f, Lipides: %.1f, Glucides: %.1f\t", total_proteine_semaine / 21, total_lipide_semaine / 21, total_glucide_semaine / 21);
        }
        printf("Proteines: %.1f, Lipides: %.1f, Glucides: %.1f\n", total_proteine_semaine / 7, total_lipide_semaine / 7, total_glucide_semaine / 7);
    }
    return 0;
}