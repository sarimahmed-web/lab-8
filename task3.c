#include <stdio.h>

int main() {
    int stock[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &stock[i][j]);
        }
    }

    printf("Original stock:\n");
    int aisleTotals[3] = {0};
    for (int i = 0; i < 3; i++) {
        printf("Aisle %d:", i + 1);
        for (int j = 0; j < 4; j++) {
            printf(" %d", stock[i][j]);
            aisleTotals[i] += stock[i][j];
        }
        printf("\n");
    }

    int bestAisle = 0;
    for (int i = 1; i < 3; i++) {
        if (aisleTotals[i] > aisleTotals[bestAisle]) {
            bestAisle = i;
        }
    }

    printf("Aisle with most stock: Aisle %d (%d units)\n", bestAisle + 1, aisleTotals[bestAisle]);

    printf("Low stock alerts:\n");
    int emptyCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (stock[i][j] == 0) {
                emptyCount++;
            }
            if (stock[i][j] < 5) {
                printf("Aisle %d, Position %d -> %d units\n", i + 1, j + 1, stock[i][j]);
            }
        }
    }

    printf("Empty shelves: %d\n", emptyCount);

    int grandTotal = 0;
    printf("Stock after restocking:\n");
    for (int i = 0; i < 3; i++) {
        printf("Aisle %d:", i + 1);
        for (int j = 0; j < 4; j++) {
            if (stock[i][j] < 5) {
                stock[i][j] += 10;
            }
            printf(" %d", stock[i][j]);
            grandTotal += stock[i][j];
        }
        printf("\n");
    }

    printf("New grand total: %d units\n", grandTotal);

    return 0;
}