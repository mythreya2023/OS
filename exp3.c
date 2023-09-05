#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PHILOSOPHERS 20

int tph, philname[MAX_PHILOSOPHERS], status[MAX_PHILOSOPHERS], howhung, hu[MAX_PHILOSOPHERS], cho;

void one();
void two();

int main() {
    int i;
    printf("\n\nDINING PHILOSOPHER PROBLEM");
    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &tph);

    if (tph > MAX_PHILOSOPHERS || tph <= 0) {
        printf("Invalid number of philosophers. Exiting.\n");
        return 1;
    }

    for (i = 0; i < tph; i++) {
        philname[i] = (i + 1);
        status[i] = 1;
    }

    printf("How many are hungry : ");
    scanf("%d", &howhung);

    if (howhung == tph) {
        printf("\nAll are hungry...\nDeadlock stage will occur");
        printf("\nExiting\n");
        return 0;
    } else {
        for (i = 0; i < howhung; i++) {
            printf("Enter philosopher %d position:", (i + 1));
            scanf("%d", &hu[i]);
            status[hu[i]] = 2;
        }
    }

    do {
        printf("\n1. One can eat at a time\t2. Two can eat at a time\t3. Exit\nEnter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1:
                one();
                break;

            case 2:
                two();
                break;

            case 3:
                printf("Exiting\n");
                return 0;

            default:
                printf("Invalid option.\n");
        }
    } while (1);

    return 0;
}

void one() {
    int pos = 0, x, i;
    printf("\nAllow one philosopher to eat at any time\n");
    
    for (i = 0; i < howhung; i++, pos++) {
        printf("\nP %d is granted to eat", philname[hu[pos]]);
        for (x = pos + 1; x < howhung; x++) {
            printf("\nP %d is waiting", philname[hu[x]]);
        }
    }
}

void two() {
    int i, j, s = 0, t, r, x;
    printf("\nAllow two philosophers to eat at the same time\n");
    
    for (i = 0; i < howhung; i++) {
        for (j = i + 1; j < howhung; j++) {
            if (abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != 4) {
                printf("\n\nCombination %d \n", (s + 1));
                t = hu[i];
                r = hu[j];
                s++;
                printf("\nP %d and P %d are granted to eat", philname[hu[i]], philname[hu[j]]);
                
                for (x = 0; x < howhung; x++) {
                    if ((hu[x] != t) && (hu[x] != r)) {
                        printf("\nP %d is waiting", philname[hu[x]]);
                    }
                }
            }
        }
    }
}

