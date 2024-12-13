#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather{
    float temperature;
    float rainfall;
    float windSpeed;
};

struct Crop{
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    struct Weather* weatherForecasts; 
    int numberOfForecasts;
};

struct Equipment{
    char equipmentName[50];
    char operationalStatus[20];
    float fuelLevel;
    char activitySchedule[100];
};

struct Sensor{
    float soilNutrients;
    float pHLevel;
    float pestActivity;
};

struct Field{
    float latitude;
    float longitude;
    float soilHealth;
    float moistureLevel;
    struct Crop* crops;           
    struct Equipment* equipment;  
    struct Sensor* sensors;  
    int numberOfCrops;
    int numberOfEquipment;
    int numberOfSensors;
};

struct RegionalHub{
    char regionName[50];
    struct Field* fields;         
    int numberOfFields;
    float yieldPrediction;
    float resourceDistribution;
    char emergencyPlan[200];
};

int main(){
    struct RegionalHub hub;

    strcpy(hub.regionName, "Western Region");
    hub.numberOfFields = 2;
    hub.fields = (struct Field*)malloc(hub.numberOfFields * sizeof(struct Field));
    hub.yieldPrediction = 0.0;
    hub.resourceDistribution = 0.0;
    strcpy(hub.emergencyPlan, "No emergency plan defined.");

    for (int i=0; i<hub.numberOfFields;++i) {
        hub.fields[i].latitude = 0.0;
        hub.fields[i].longitude = 0.0;
        hub.fields[i].soilHealth = 0.0;
        hub.fields[i].moistureLevel = 0.0;
        hub.fields[i].numberOfCrops = 2;
        hub.fields[i].numberOfEquipment = 2;
        hub.fields[i].numberOfSensors = 2;
        hub.fields[i].crops = (struct Crop*)malloc(hub.fields[i].numberOfCrops * sizeof(struct Crop));
        hub.fields[i].equipment = (struct Equipment*)malloc(hub.fields[i].numberOfEquipment * sizeof(struct Equipment));
        hub.fields[i].sensors = (struct Sensor*)malloc(hub.fields[i].numberOfSensors * sizeof(struct Sensor));

        for (int j=0; j<hub.fields[i].numberOfCrops;++j) {
            strcpy(hub.fields[i].crops[j].cropType, j == 0 ? "Wheat" : "Barley");
            strcpy(hub.fields[i].crops[j].growthStage, j == 0 ? "Flowering" : "Mature");
            hub.fields[i].crops[j].expectedYield = j == 0 ? 1200.5 : 900.8;
            hub.fields[i].crops[j].numberOfForecasts = j + 1;
            hub.fields[i].crops[j].weatherForecasts = (struct Weather*)malloc(hub.fields[i].crops[j].numberOfForecasts * sizeof(struct Weather));
        }
        for (int j=0;j<hub.fields[i].numberOfEquipment;++j) {
            strcpy(hub.fields[i].equipment[j].equipmentName, j == 0 ? "Autonomous Tractor" : "Irrigation System");
            strcpy(hub.fields[i].equipment[j].operationalStatus, j == 0 ? "Active" : "Inactive");
            hub.fields[i].equipment[j].fuelLevel = j == 0 ? 80.0 : 0.0;
            strcpy(hub.fields[i].equipment[j].activitySchedule, j == 0 ? "Daily tilling" : "Under maintenance");
        }

        for (int j=0; j<hub.fields[i].numberOfSensors;++j) {
            hub.fields[i].sensors[j].soilNutrients = j == 0 ? 6.5 : 7.8;
            hub.fields[i].sensors[j].pHLevel = j == 0 ? 7.0 : 6.2;
            hub.fields[i].sensors[j].pestActivity = j == 0 ? 0.3 : 0.1;
        }
    }

    printf("Regional Hub: %s\n", hub.regionName);
    printf("Yield Prediction: %.2f\n", hub.yieldPrediction);
    printf("Resource Distribution: %.2f\n", hub.resourceDistribution);
    printf("Emergency Plan: %s\n\n", hub.emergencyPlan);

    for (int i=0; i<hub.numberOfFields;++i){
        printf("Field %d:\n", i + 1);
        printf("Location: (%.2f, %.2f)\n", hub.fields[i].latitude, hub.fields[i].longitude);
        printf("Soil Health: %.2f, Moisture: %.2f\n", hub.fields[i].soilHealth, hub.fields[i].moistureLevel);
        printf("Crops:\n");

        for (int j=0; j<hub.fields[i].numberOfCrops;++j) {
            printf("%s (%s), Yield: %.2f\n", hub.fields[i].crops[j].cropType, hub.fields[i].crops[j].growthStage, hub.fields[i].crops[j].expectedYield);
        }

        printf("Equipment:\n");
        for (int j=0; j<hub.fields[i].numberOfEquipment;++j) {
            printf("%s (%s), Fuel: %.2f\n", hub.fields[i].equipment[j].equipmentName, hub.fields[i].equipment[j].operationalStatus, hub.fields[i].equipment[j].fuelLevel);
        }

        printf("Sensors:\n");
        for (int j=0; j<hub.fields[i].numberOfSensors;++j) {
            printf(" Nutrients: %.2f, pH: %.2f, Pests: %.2f\n", hub.fields[i].sensors[j].soilNutrients, hub.fields[i].sensors[j].pHLevel, hub.fields[i].sensors[j].pestActivity);
        }
        printf("\n");
    }

    for (int i=0; i<hub.numberOfFields;++i) {
        for (int j=0; j<hub.fields[i].numberOfCrops;++j) {
            free(hub.fields[i].crops[j].weatherForecasts);
        }
        free(hub.fields[i].crops);
        free(hub.fields[i].equipment);
        free(hub.fields[i].sensors);
    }

    free(hub.fields);
    return 0;
}
