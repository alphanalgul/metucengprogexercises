/*
 * This program reads patient records from a file (data.txt),
 * stores them in dynamically allocated memory using a struct,
 * displays all patient information, calculates basic statistics
 * (such as gender and cancer status), and writes two separate
 * files: one for patients with lung cancer (cancer.txt) and
 * one for those without (noncancer.txt).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char *name;
    char *surname;
    char *gender;
    int smoking;
    char *Lung_Cancer;

}Hospital;

void populateData(Hospital *PersonTable,char *line);
void displayData(Hospital *PersonTable,int count);
void statData(Hospital *PersonTable,int count);
void splitData(Hospital *PersonTable,int count);
int main() {

    FILE *file = fopen("data.txt","r");
    Hospital *PersonTable = NULL;
    char line[256];
    int count = 0;
    while(fgets(line,sizeof(Hospital),file)){
        if(line[strlen(line)-1] == '\n'){
            line[strlen(line)-1] = '\0';
        }
        PersonTable = realloc(PersonTable,sizeof(Hospital)*(count+1));
        populateData(&PersonTable[count],line);
        count++;
    }
    fclose(file);
    displayData(PersonTable,count);
    statData(PersonTable,count);
    splitData(PersonTable,count);
    for (int i = 0; i < count; ++i) {
        free(PersonTable[i].name);
        free(PersonTable[i].surname);
        free(PersonTable[i].gender);
        free(PersonTable[i].Lung_Cancer);
    }
    free(PersonTable);

}

void populateData(Hospital *PersonTable,char *line){

    char *token = strtok(line," ");
    PersonTable->id = atoi(token);
    token = strtok(NULL," ");
    PersonTable->name = malloc(strlen(token)+1);
    strcpy(PersonTable->name,token);
    token = strtok(NULL," ");
    PersonTable->surname = malloc(strlen(token)+1);
    strcpy(PersonTable->surname,token);
    token = strtok(NULL," ");
    PersonTable->gender = malloc(strlen(token)+1);
    strcpy(PersonTable->gender,token);
    token = strtok(NULL," ");
    PersonTable->smoking = atoi(token);
    token = strtok(NULL," ");
    PersonTable->Lung_Cancer = malloc(strlen(token)+1);
    strcpy(PersonTable->Lung_Cancer,token);

}

void displayData(Hospital *PersonTable,int count){

    printf("Patients:\n");
    printf("ID \tName \tSurname \tGender \tSmoking \tLung_Cancer\n");
    for (int i = 0; i < count; ++i) {

        printf("%d %10s %10s %10s %10d %15s\n",
               PersonTable[i].id,
               PersonTable[i].name,
               PersonTable[i].surname,
               PersonTable[i].gender,
               PersonTable[i].smoking,
               PersonTable[i].Lung_Cancer);
    }

}

void statData(Hospital *PersonTable,int count){
    int cancer = 0,withoutCancer = 0;
    int male =0,female = 0;
    for (int i = 0; i < count; ++i) {

        if(PersonTable[i].Lung_Cancer[0] == 'Y') {
            cancer++;
        }

        if(PersonTable[i].Lung_Cancer[0] == 'N'){
            withoutCancer++;
        }

        if(PersonTable[i].gender[0] == 'M') {
            male++;
        }

        if(PersonTable[i].gender[0] == 'F'){
            female++;
        }


    }
    printf("\nStatistics:\n");
    printf("%d patient with cancer and %d patient without cancer\n",cancer,withoutCancer);
    printf("%d Male and %d Female Patients \n",male,female);
}

void splitData(Hospital *PersonTable,int count){

    FILE *file2 = fopen("cancer.txt","w+");
    FILE *file3 = fopen("noncancer.txt","w+");

    for (int i = 0; i <count ; ++i) {
        if(PersonTable[i].Lung_Cancer[0] == 'Y') {
            fprintf(file2, "%d %s %s %s %d %s\n",
                    PersonTable[i].id,
                    PersonTable[i].name,
                    PersonTable[i].surname,
                    PersonTable[i].gender,
                    PersonTable[i].smoking,
                    PersonTable[i].Lung_Cancer);
        }
    }

    for (int i = 0; i <count ; ++i) {
        if(PersonTable[i].Lung_Cancer[0] == 'N') {
            fprintf(file3, "%d %s %s %s %d %s\n",
                    PersonTable[i].id,
                    PersonTable[i].name,
                    PersonTable[i].surname,
                    PersonTable[i].gender,
                    PersonTable[i].smoking,
                    PersonTable[i].Lung_Cancer);
        }
    }

    printf("Two files are created for you: cancer.txt and noncancer.txt!\n");

}
