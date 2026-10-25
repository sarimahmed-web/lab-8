#include <stdio.h>

int main() {
    int image[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    int brightness, threshold;
    scanf("%d %d", &brightness, &threshold);

    printf("Original image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %d", image[i][j]);
        }
        printf("\n");
    }

    printf("Brightness (+%d):\n", brightness);
    int brightImg[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int val = image[i][j] + brightness;
            if (val > 255) val = 255;
            if (val < 0) val = 0;
            brightImg[i][j] = val;
            printf(" %d", brightImg[i][j]);
        }
        printf("\n");
    }

    printf("Black and white (threshold %d):\n", threshold);
    int bwImg[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bwImg[i][j] = (image[i][j] >= threshold) ? 255 : 0;
            printf(" %d", bwImg[i][j]);
        }
        printf("\n");
    }

    printf("Flipped horizontally:\n");
    int flipImg[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            flipImg[i][j] = image[i][3 - j];
            printf(" %d", flipImg[i][j]);
        }
        printf("\n");
    }

    // need a separate array so modified pixels don't mess up the math for the next ones
    int result[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = image[i][j]; 
        }
    }

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    sum += image[i + di][j + dj];
                }
            }
            result[i][j] = sum / 9;
        }
    }

    printf("Smoothed image:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf(" %d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}