/*
 * This program processes internship data from a file.
 * It loads records into memory and allows the user to:
 * - Display all student internship data
 * - Search by name or full name
 * - Sort by score or letter grade
 * - Display department-wise statistics of pass/fail students
 *
 * Letter grades are automatically calculated as 'S' (>= 70) or 'U'.
 * The file is passed as a command-line argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define SURNAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    char surname[SURNAME_LEN];
    int departmentCode;
    int semester;
    float score;
    char letterGrade;
} InternshipRecord;

//Loading the data from the file
void Load_InternshipDataTable(const char *filename, InternshipRecord **records, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("This file does not exist. Please enter again: ");
        return;
    }

    char buffer[256];
    char **lines = NULL;
    int lineCount = 0;

    // Skip header line
    fgets(buffer, sizeof(buffer), file);

    // Read the file line by line and store lines in memory
    while (fgets(buffer, sizeof(buffer), file)) {
        lines = realloc(lines, (lineCount + 1) * sizeof(char *));
        lines[lineCount] = strdup(buffer);
        lineCount++;
    }
    fclose(file);

    // Allocate memory for the records
    *records = (InternshipRecord *)malloc(lineCount * sizeof(InternshipRecord));
    if (!*records) {
        printf("Memory allocation failed\n");
        for (int i = 0; i < lineCount; i++) {
            free(lines[i]);
        }
        free(lines);
        return;
    }

    *size = lineCount;

    // Parse the lines into records
    for (int i = 0; i < lineCount; i++) {
        sscanf(lines[i], "%s %s %d %d %f", (*records)[i].name, (*records)[i].surname,
               &(*records)[i].departmentCode, &(*records)[i].semester, &(*records)[i].score);
        (*records)[i].letterGrade = ((*records)[i].score >= 70) ? 'S' : 'U';
        free(lines[i]);
    }
    free(lines);
}
//Displaying the data
void Display_InternshipDataTable(InternshipRecord *records, int size) {
    if (size == 0) {
        printf("No records loaded.\n");
        return;
    }

    printf("name surname departmentCode semester score letterGrade\n");
    for (int i = 0; i < size; i++) {
        printf("%s  %s  %d  %d  %.1f  %c\n", records[i].name, records[i].surname, records[i].departmentCode,
               records[i].semester, records[i].score, records[i].letterGrade);
    }
}

//Searching for just name or both name and surname
int Search(InternshipRecord *records, int size, const char *fullname) {

    // Allocate space for a copy of the fullname
    char fullnameCopy[NAME_LEN + SURNAME_LEN + 1];  // Add 1 for null terminator

    // Copy the fullname into fullnameCopy
    strcpy(fullnameCopy, fullname);

    // Ensure null-termination
    fullnameCopy[strlen(fullname)] = '\0';

    // Tokenize the fullnameCopy to extract name and surname
    char *name = strtok(fullnameCopy, " ");
    char *surname = strtok(NULL, " ");

    // Iterate through the records to find a match
    for (int i = 0; i < size; i++) {
        if (surname != NULL) {  // Full name search
            if (strcmp(records[i].name, name) == 0 && strcmp(records[i].surname, surname) == 0) {
                return i; // Found, return the index
            }
        } else {  // Single name search
            if (strcmp(records[i].name, name) == 0) {
                return i; // Found, return the index
            }
        }
    }

    return -1; // Not Found, return -1
}
//Sorting the elements
void Sort(InternshipRecord *records, int size, int option) {
    for (int i = 1; i < size; i++) {
        InternshipRecord current = records[i];
        int j = i - 1;

        if (option == 1) {
            // Sort by score
            while (j >= 0 && records[j].score > current.score) {
                records[j + 1] = records[j];
                j--;
            }
        } else if (option == 2) {
            // Sort by letter grade
            while (j >= 0 && records[j].letterGrade > current.letterGrade) {
                records[j + 1] = records[j];
                j--;
            }
        }

        records[j + 1] = current;
    }
}

//Displaying the number of students that passed or failed
void Statistics(InternshipRecord *records, int size) {
    //Total passes and fails
    int pass = 0, fail = 0;
    //Passes and fails for  355: Computer Engineering
    int pass355 = 0, fail355 = 0;
    //Passes and fails for 356: Electrical and Electronics Engineering
    int pass356 = 0, fail356 = 0;
    //Passes and fails for 365: Mechanical Engineering
    int pass365 = 0, fail365 = 0;
    //Passes and fails for 384: Aerospace Engineering
    int pass384 = 0, fail384 = 0;

    for (int i = 0; i < size; i++) {
        if (records[i].letterGrade == 'S') {
            pass++;
            switch (records[i].departmentCode) {
                case 355:
                    pass355++;
                    break;
                case 356:
                    pass356++;
                    break;
                case 365:
                    pass365++;
                    break;
                case 384:
                    pass384++;
                    break;
            }
        } else {
            fail++;
            switch (records[i].departmentCode) {
                case 355:
                    fail355++;
                    break;
                case 356:
                    fail356++;
                    break;
                case 365:
                    fail365++;
                    break;
                case 384:
                    fail384++;
                    break;
            }
        }
    }

    printf("Overall: %d student(s) passed and %d student(s) failed!\n", pass, fail);
    printf("Department: 355, %d student(s) passed and %d student(s) failed!\n", pass355, fail355);
    printf("Department: 356, %d student(s) passed and %d student(s) failed!\n", pass356, fail356);
    printf("Department: 365, %d student(s) passed and %d student(s) failed!\n", pass365, fail365);
    printf("Department: 384, %d student(s) passed and %d student(s) failed!\n", pass384, fail384);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    InternshipRecord *records = NULL;
    int size = 0;
    char filename[256];

    strcpy(filename, argv[1]);

    while (1) {
        Load_InternshipDataTable(filename, &records, &size);
        if (records) break;
        scanf("%s", filename);
    }

    printf("The student records file (%s) has been successfully loaded!\n", filename);
    Display_InternshipDataTable(records, size);

    int choice;
    while (1) {
        printf("What would you like to do?\n1 - search\n2 - sort\n3 - statistics\n4 - exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char fullname[NAME_LEN + SURNAME_LEN];
            printf("Please enter the name of the student: ");
            getchar();  // consume newline character
            fgets(fullname, sizeof(fullname), stdin);
            fullname[strcspn(fullname, "\n")] = 0;  // remove newline character

            int index = Search(records, size, fullname);
            if (index != -1) {
                printf("name: %s\nsurname: %s\ndepartment code: %d\nsemester: %d\nscore: %.1f\ngrade: %c\n",
                       records[index].name, records[index].surname, records[index].departmentCode,
                       records[index].semester, records[index].score, records[index].letterGrade);
            } else {
                printf("This student is not in our records!\n");
            }
        } else if (choice == 2) {
            int column;
            printf("Which column (1: score, 2: letter grade)?: ");
            scanf("%d", &column);
            if (column == 1 || column == 2) {
                Sort(records, size, column);
                Display_InternshipDataTable(records, size);
            } else {
                printf("Invalid choice!\n");
            }
        } else if (choice == 3) {
            Statistics(records, size);
        } else if (choice == 4) {
            printf("Byee\n");
            break;
        } else {
            printf("Wrong input!\n");
        }
    }

    free(records);
    return 0;
}
