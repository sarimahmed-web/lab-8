#include <stdio.h>

int main() {
    int marks[4][3];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            while (1) {
                scanf("%d", &marks[i][j]);
                if (marks[i][j] >= 0 && marks[i][j] <= 100) {
                    break;
                }
                printf("Invalid mark! Enter a value between 0 and 100.\n");
            }
        }
    }

    const char* subjects[3] = {"Programming", "Calculus", "Physics"};
    int highestSub[3] = {-1, -1, -1};
    int lowestSub[3] = {101, 101, 101};
    double subSum[3] = {0, 0, 0};

    printf("%-12s%-6s%-6s%-6s%-8s%-9s%s\n", "Student", "Prog", "Calc", "Phys", "Total", "Average", "Grade");

    int topStudent = 0;
    double maxAvg = -1;

    for (int i = 0; i < 4; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += marks[i][j];
            subSum[j] += marks[i][j];
            if (marks[i][j] > highestSub[j]) highestSub[j] = marks[i][j];
            if (marks[i][j] < lowestSub[j]) lowestSub[j] = marks[i][j];
        }
        double avg = total / 3.0;
        if (avg > maxAvg) {
            maxAvg = avg;
            topStudent = i;
        }

        char grade;
        if (avg >= 80) grade = 'A';
        else if (avg >= 65) grade = 'B';
        else if (avg >= 50) grade = 'C';
        else grade = 'F';

        char studentName[20];
        sprintf(studentName, "Student %d", i + 1);

        printf("%-12s%-6d%-6d%-6d%-8d%-9.2f%c\n", studentName, marks[i][0], marks[i][1], marks[i][2], total, avg, grade);
    }

    printf("\nSubject statistics:\n");
    printf("%-15s%-9s%-9s%s\n", "Subject", "Highest", "Lowest", "Average");

    int worstSubIndex = 0;
    double minSubAvg = 101.0;

    for (int j = 0; j < 3; j++) {
        double subAvg = subSum[j] / 4.0;
        if (subAvg < minSubAvg) {
            minSubAvg = subAvg;
            worstSubIndex = j;
        }
        printf("%-15s%-9d%-9d%.2f\n", subjects[j], highestSub[j], lowestSub[j], subAvg);
    }

    printf("\nTop student: Student %d (Average %.2f)\n", topStudent + 1, maxAvg);
    printf("Worst subject: %s (Average %.2f)\n", subjects[worstSubIndex], minSubAvg);

    return 0;
}