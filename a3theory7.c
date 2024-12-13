#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

struct ContentMetadata{
    char title[100];
    float rating;
    int runtime;
    char encodingFormats[50];
};

struct DevicePreferences{
    float resolutionPreference;
    int playbackHistory[10];
    float bandwidthUsage;
};

struct UserProfile{
    double* engagementRow;
    struct DevicePreferences** devices;
    int numberOfDevices;
};

int main(){
    int numberOfUsers = 3, numberOfCategories = 5, maxDevices = 2, numberOfContents = 4;
    double** engagementMatrix = (double**)malloc(numberOfUsers * sizeof(double*));
    for (int i = 0; i < numberOfUsers; i++){
     engagementMatrix[i] = (double*)calloc(numberOfCategories, sizeof(double));
    }

    struct DevicePreferences*** deviceMatrix = (struct DevicePreferences***)malloc(numberOfUsers * sizeof(struct DevicePreferences**));
    for (int i = 0; i < numberOfUsers; i++){
        deviceMatrix[i] = (struct DevicePreferences**)malloc(maxDevices * sizeof(struct DevicePreferences*));
        for (int j = 0; j < maxDevices; j++){
            deviceMatrix[i][j] = (struct DevicePreferences*)malloc(sizeof(struct DevicePreferences));
            deviceMatrix[i][j]->resolutionPreference=720;
            deviceMatrix[i][j]->bandwidthUsage=0;
            memset(deviceMatrix[i][j]->playbackHistory, 0, 10 * sizeof(int));
        }
    }

    struct ContentMetadata** contentMatrix = (struct ContentMetadata**)malloc(numberOfCategories * sizeof(struct ContentMetadata*));
    for (int i = 0; i < numberOfCategories; i++) {
        contentMatrix[i] = (struct ContentMetadata*)malloc(numberOfContents * sizeof(struct ContentMetadata));
        for (int j = 0; j < numberOfContents; j++) {
            snprintf(contentMatrix[i][j].title, 100, "Content_%d_%d", i + 1, j + 1);
            contentMatrix[i][j].rating = (rand() % 50) / 10.0 + 10.0;
            contentMatrix[i][j].runtime = (rand() % 60) + 70;
            snprintf(contentMatrix[i][j].encodingFormats, 50, "HD, 4K");
        }
    }

    engagementMatrix[0][1] += 6.0;
    engagementMatrix[1][3] += 2.5;

    for (int i = 0; i < numberOfUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numberOfCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i<numberOfUsers; i++) {
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);

    for (int i = 0; i < numberOfUsers; i++) {
        for (int j = 0; j < maxDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);

    for (int i = 0; i < numberOfCategories; i++) {
        free(contentMatrix[i]);
    }
    free(contentMatrix);

    return 0;
}
