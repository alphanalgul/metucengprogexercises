/*
 * This program reads patient data from a file specified by the user via command-line arguments,
 * stores it in an array of structures, and performs the following:
 * - Displays all patient records
 * - Calculates and prints statistics (gender and lung cancer status)
 * - Separates and saves patients with and without lung cancer into separate files 
 * (cancer.txt and non_cancer.txt)
 * Usage: ./program_name <filename> <max_records>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Data{
    int id;
    char name[50];
    char surname[50];
    char gender[50];
    int smoking;
    char cancer[50];
}Data;
int populateData(char *filename,Data *records,int maxSize)
{
    FILE *file= fopen(filename,"r");
    if(file==NULL)
    {
        printf("\nError opening the file! Please try again!");
        return 0;
    }
    int size=0;
    //Temporary variables
    int id;
    char name[50];
    char surname[50];
    char gender[50];
    int smoking;
    char cancer[50];
    if(size<maxSize)
    {
        while (fscanf(file, "%d %s %s %s %d %s", &id, name, surname, gender, &smoking, cancer) != EOF) {

            records[size].id = id;
            strcpy(records[size].name, name);
            strcpy(records[size].surname, surname);
            strcpy(records[size].gender, gender);
            records[size].smoking = smoking;
            strcpy(records[size].cancer, cancer);
            size++;
        }
    }
    fclose(file);
    return size;
}
void displayData(Data  *records,int numRecords)
{
    int i;
    printf("\nID  Name  Surname  Gender  Smoking  Lung_Cancer\n");
    for(i=0;i<numRecords;i++)
    {
        printf("%d   %s   %s   %s   %d   %s",records[i].id,records[i].name,records[i].surname,records[i].gender,records[i].smoking
        ,records[i].cancer);
        printf("\n");
    }
}
void statData(Data *records, int numRecords)
{
    int cancer = 0, no_cancer = 0, male = 0, female = 0;

    for (int i = 0; i < numRecords; i++) {
        if (records[i].gender[0] == 'M') male++;
        if (records[i].gender[0] == 'F') female++;
        if (records[i].cancer[0] == 'Y') cancer++;
        if (records[i].cancer[0] == 'N') no_cancer++;
    }

    printf("\n%d patients with cancer and %d patients without cancer", cancer, no_cancer);
    printf("\n%d Male patients and %d Female patients", male, female);
}
void splitData(Data *records, int numPatients)
{
    FILE *cancer = fopen("cancer.txt", "w");
    FILE *non_cancer = fopen("non_cancer.txt", "w");

    if (!cancer || !non_cancer) {
        printf("Error opening output files.\n");
        return;
    }

    for (int i = 0; i < numPatients; i++) {
        if (records[i].cancer[0] == 'Y') {
            fprintf(cancer, "%d %s %s %s %d %s\n",
                    records[i].id,
                    records[i].name,
                    records[i].surname,
                    records[i].gender,
                    records[i].smoking,
                    records[i].cancer);
        } else if (records[i].cancer[0] == 'N') {
            fprintf(non_cancer, "%d %s %s %s %d %s\n",
                    records[i].id,
                    records[i].name,
                    records[i].surname,
                    records[i].gender,
                    records[i].smoking,
                    records[i].cancer);
        }
    }

    fclose(cancer);
    fclose(non_cancer);

    printf("Two files are created for you: cancer.txt and non_cancer.txt!\n");
}

int main(int argc,char *argv[]) {
    if(argc!=3)
    {
        printf("\nYou need to have at least two parameters,bye.....");
        return 0;
    }
    char *filename=argv[1];
    char *size=argv[2];
    int N;
    N= atoi(size);

    int numPatients;
    Data *records=(Data *) malloc(N*sizeof(Data));
    numPatients= populateData(filename,records,N);
    displayData(records,numPatients);
    statData(records,numPatients);
    splitData(records,numPatients);
}
