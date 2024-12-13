#include <stdio.h>
#include <stdlib.h>

int main() {
    int numEmployees, numPeriods;
 printf("Enter the number of employees:|n");
    scanf("%d",&numEmployees);
    printf("Enter the number of evaluation periods:\n");
    scanf("%d",&numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    for (int i=0; i<numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }

    printf("Enter ratings (1-10) for each employee and period:\n");
    for (int i=0; i<numEmployees; i++) {
        printf("Employee %d:\n", i + 1);
        for (int j=0; j<numPeriods; j++) {
            do {
                printf("  Period %d: ",j+1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j]<1 || ratings[i][j]>10) {
                    printf("Invalid input! Please enter a rating between 1 and 10.\n");
                }
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
    printf("\nPerformance Ratings:\n");
    for (int i=0; i<numEmployees; i++){
        printf("Employee %d: ", i+1);
        for (int j=0; j<numPeriods; j++) {
            printf("%d ",ratings[i][j]);
        }
        printf("\n");
    }
    int bestEmployeeIndex=0;
    double highestAvg=0;
    for (int i=0; i<numEmployees; i++) {
        int total=0;
        for (int j=0; j<numPeriods; j++) {
            total+=ratings[i][j];
        }
        double avg=(double)total/numPeriods;
        if (avg>highestAvg) {
            highestAvg=avg;
            bestEmployeeIndex=i;
        }
    }
    printf("\nEmployee of the Year: Employee %d with an average rating of %.2f\n", bestEmployeeIndex + 1, highestAvg);

    int bestPeriodIndex=0;
    double highestPeriodAvg=0;
    for (int j=0; j<numPeriods; j++) {
        int total=0;
        for (int i=0; i<numEmployees; i++) {
            total+=ratings[i][j];
        }
        double avg=(double)total/numEmployees;
        if (avg>highestPeriodAvg){
            highestPeriodAvg=avg;
            bestPeriodIndex=j;
        }
    }
    printf("Highest Rated Period: Period %d with an average rating of %.2f\n", bestPeriodIndex + 1, highestPeriodAvg);

    int worstEmployeeIndex=0;
    double lowestAvg=11.0;
    for (int i=0; i<numEmployees; i++) {
        int total=0;
        for (int j=0; j<numPeriods; j++) {
            total+=ratings[i][j];
        }
        double avg=(double)total/numPeriods;
        if (avg<lowestAvg) {
            lowestAvg=avg;
            worstEmployeeIndex=i;
        }
    }
    printf("Worst Performing Employee: Employee %d with an average rating of %.2f\n", worstEmployeeIndex + 1, lowestAvg);

    for (int i=0;i<numEmployees;i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}