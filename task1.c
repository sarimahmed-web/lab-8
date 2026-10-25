#include <stdio.h>

int main() {
    int seats[5][6] = {0};
    int r, c;

    while (1) {
        if (scanf("%d", &r) != 1) break;
        if (r == -1) break;
        int col;
        if (scanf("%d", &col) != 1) break;

        if (r < 1 || r > 5 || col < 1 || col > 6) {
            printf("Error: Invalid row or column!\n");
        } else if (seats[r - 1][col - 1] == 1) {
            printf("Error: Seat already booked!\n");
        } else {
            seats[r - 1][col - 1] = 1;
            printf("Seat booked successfully.\n");
        }
    }

    int bookedCount = 0;
    int rowBookings[5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (seats[i][j] == 1) {
                bookedCount++;
                rowBookings[i]++;
            }
        }
    }
    int emptyCount = 30 - bookedCount;

    int maxRow = 0;
    for (int i = 1; i < 5; i++) {
        if (rowBookings[i] > rowBookings[maxRow]) {
            maxRow = i;
        }
    }

    printf("Seating Chart:\n");
    printf("  1 2 3 4 5 6\n");
    for (int i = 0; i < 5; i++) {
        printf("Row %d", i + 1);
        for (int j = 0; j < 6; j++) {
            printf(" %c", seats[i][j] == 1 ? 'X' : 'O');
        }
        printf("\n");
    }

    printf("Total booked seats: %d\n", bookedCount);
    printf("Total empty seats: %d\n", emptyCount);
    printf("Row with most bookings: Row %d\n", maxRow + 1);

    return 0;
}