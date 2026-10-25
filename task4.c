#include <stdio.h>
#include <stdbool.h>

int main() {
    int beds[2][3][2] = {0}; // floors, wards, beds
    int choice;

    while (scanf("%d", &choice) == 1) {
        if (choice == 4) break;

        if (choice == 1) { // Admit
            int floor, patientId;
            scanf("%d %d", &floor, &patientId);
            bool admitted = false;
            int f = floor - 1;
            for (int w = 0; w < 3 && !admitted; w++) {
                for (int b = 0; b < 2 && !admitted; b++) {
                    if (beds[f][w][b] == 0) {
                        beds[f][w][b] = patientId;
                        admitted = true;
                        printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n", patientId, floor, w + 1, b + 1);
                    }
                }
            }
            if (!admitted) {
                printf("Floor %d is full.\n", floor);
            }
        } 
        else if (choice == 2) { // Discharge
            int patientId;
            scanf("%d", &patientId);
            bool found = false;
            for (int f = 0; f < 2 && !found; f++) {
                for (int w = 0; w < 3 && !found; w++) {
                    for (int b = 0; b < 2 && !found; b++) {
                        if (beds[f][w][b] == patientId) {
                            beds[f][w][b] = 0;
                            found = true;
                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n", patientId, f + 1, w + 1, b + 1);
                        }
                    }
                }
            }
            if (!found) {
                printf("Patient ID %d not found.\n", patientId);
            }
        } 
        else if (choice == 3) { // Report
            printf("--- Occupancy Report ---\n");
            int maxOccupied = -1;
            int bestF = 0, bestW = 0;

            for (int f = 0; f < 2; f++) {
                printf("Floor %d\n", f + 1);
                int floorTotalOccupied = 0;
                for (int w = 0; w < 3; w++) {
                    int occ = 0, vac = 0;
                    for (int b = 0; b < 2; b++) {
                        if (beds[f][w][b] != 0) occ++;
                        else vac++;
                    }
                    floorTotalOccupied += occ;
                    printf(" Ward %d: Occupied %d, Vacant %d\n", w + 1, occ, vac);
                    
                    if (occ > maxOccupied) {
                        maxOccupied = occ;
                        bestF = f + 1;
                        bestW = w + 1;
                    }
                }
                double floorPct = (floorTotalOccupied / 6.0) * 100.0;
                printf(" Floor occupancy: %.1f%%\n", floorPct);
                if (floorPct > 80.0) {
                    printf("WARNING: Floor %d is more than 80%% full.\n", f + 1);
                }
            }
            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n", bestF, bestW, maxOccupied);
        }
    }
    return 0;
}