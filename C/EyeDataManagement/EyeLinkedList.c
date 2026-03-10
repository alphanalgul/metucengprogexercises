/*
 * Eye Data Management System
 * 
 * This program reads and manages eye-tracking data (Pupil/Iris coordinates and radii)
 * from a file, grouped by user. Data is stored using linked lists:
 * 
 * - Each user has a linked list of their eye measurements
 * - Users are managed in a separate linked list
 * 
 * Features:
 * - Loading data from a file
 * - Automatically checks and handles invalid (zero) values
 * - Allows users to delete or correct problematic records
 * - Displays statistics: count of eye records and estimated age group
 * - Case-insensitive username handling
 * 
 * Age groups are estimated based on the average dilation ratio (IrisR / PupilR):
 *   - < 1.6   → Young
 *   - 1.6–4.6 → Adult
 *   - > 4.6   → Elderly
 * 
 * Usage:
 *   - Compile and run the program
 *   - Provide the input filename when prompted
 *   - Follow the menu to view statistics or exit
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//Required to use tolower(turns chars into lower case)
struct EyeData {//Definition for EyeData Linked List
    //Variables for Eye Data
    int PupilX;
    int PupilY;
    int IrisX;
    int IrisY;
    int IrisR;
    int PupilR;
    struct EyeData *next; // Pointer to the next eye data in the linked list
};
struct User {//definition for User Linked List
    char UserName[50];
    struct EyeData *eyeList; // Head pointer for the linked list of eye data
    struct User *next; // Pointer to the next user in the linked list of User
};

// Function to create a new eye data node
struct EyeData* createEyeDataNode(int PupilX, int PupilY, int IrisX, int IrisY, int IrisR, int PupilR) {
    struct EyeData *newNode = (struct EyeData*)malloc(sizeof(struct EyeData));//allocating memory for the linked list
    if (newNode == NULL) {//checking if the memory allocation was successful
        printf("Memory allocation failed\n");
        exit(1);
    }
    //Storing Eye Datas into the linked list
    newNode->PupilX = PupilX;
    newNode->PupilY = PupilY;
    newNode->IrisX = IrisX;
    newNode->IrisY = IrisY;
    newNode->IrisR = IrisR;
    newNode->PupilR = PupilR;
    newNode->next = NULL;
    return newNode;
}
//Function to check if a given user is in the Linked List
struct User* findUser(struct User *head, const char *username) {
    struct User *current_user = head;
    while (current_user != NULL) {
        if (strcmp(current_user->UserName, username) == 0) {//Comparing the current_user to UserName in the User Linked Lists
            return current_user;//Return a pointer to the User Linked list  if current_user is in the Linked List
        }
        current_user = current_user->next;
    }
    return NULL; // User not found
}
//Function to create a new user node
struct User* createUserNode(char *UserName) {
    struct User *newUser = (struct User*)malloc(sizeof(struct User));//allocating memory for the linked list
    if (newUser == NULL) {//checking if the memory allocation was successful
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newUser->UserName, UserName);//Storing the Usernames into the linked list
    newUser->eyeList = NULL; // Initialize eye list to NULL
    newUser->next = NULL;
    return newUser;
}
// Function to insert eye data for a user
void insertEyeData(struct User *user, int PupilX, int PupilY, int IrisX, int IrisY, int IrisR, int PupilR) {
    struct EyeData *newEyeData = createEyeDataNode(PupilX, PupilY, IrisX, IrisY, IrisR, PupilR);
    if (user->eyeList == NULL) {//If the list is empty newEyeData becomes the first node in the list
        user->eyeList = newEyeData;
    } else {
        struct EyeData *temp = user->eyeList;
        while (temp->next != NULL) {//Traversing the list until its empty
            temp = temp->next;
        }
        temp->next = newEyeData;
    }
}

// Function to free memory allocated for eye data
void freeEyeData(struct User *user) {
   struct EyeData *temp = user->eyeList;
    while (temp != NULL) {
        struct EyeData *current = temp;
        temp = temp->next;
        free(current);
    }
}

// Function to free memory allocated for users
void freeUsers(struct User *head) {
    struct User *temp = head;
    while (temp != NULL) {
        struct User *current = temp;
        temp = temp->next;
        freeEyeData(current);
        free(current);
    }
}
//Function to load data from a given file and inserting those data to the linked list
struct User* load_data(const char *filename) {
    FILE *file = fopen(filename, "r");//Opening a file for reading
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    struct User *head = NULL;
    struct User *current_user = NULL;
    char UserName[50]; // Assuming the maximum length of the username is 50 characters
    int PupilX, PupilY, IrisX, IrisY, IrisR, PupilR;
    //The Imported eye data has 7 variables: UserName,PupilX,PupilY,IrisX,IrisY,IrisR,PupilR
    while (fscanf(file, "%49[^,],%d,%d,%d,%d,%d,%d\n", UserName, &PupilX, &PupilY, &IrisX, &IrisY, &IrisR, &PupilR) == 7) {
        // Checking if the user already exists
        struct User *existing_user = findUser(head, UserName);
        if (existing_user == NULL) {
            // User does not exist, create a new user node
            if (head == NULL) {
                head = createUserNode(UserName);
                current_user = head;
            } else {
                current_user->next = createUserNode(UserName);
                current_user = current_user->next;
            }
        } else {
            // User already exists, use the existing user node
            current_user = existing_user;
        }

        // Insert the eye data for the user
        insertEyeData(current_user, PupilX, PupilY, IrisX, IrisY, IrisR, PupilR);
    }

    fclose(file);
    return head;
}
// Function to count the number of eye data nodes for a particular user
int count_eyes(struct EyeData *eyeList) {
    int count = 0;
    struct EyeData *current_eye = eyeList;
    while (current_eye != NULL) {
        count++;//Counting the number of eyes
        current_eye = current_eye->next;
    }
    return count;
}
// Function to calculate and display age group based on average dilation ratio
void age_groups(struct User *user) {
    int eye_count = count_eyes(user->eyeList);
    double sum_ratio = 0.0;
    double avg_ratio;
    struct EyeData *current_eye = user->eyeList;

    printf("The age group for the eye data is:");

    while (current_eye != NULL) {
        double dilation_ratio = (double)current_eye->IrisR / current_eye->PupilR;
        sum_ratio += dilation_ratio;
        avg_ratio=sum_ratio/eye_count;//Calculating the average dilation ratio
        current_eye = current_eye->next;
    }
    // Determine age group based on the average dilation ratio
    if (avg_ratio < 1.6) {
        printf("Young");
    } else if (avg_ratio <= 4.6) {
        printf("Adult");
    } else {
        printf("Elderly");
    }
}
// Function to check eye data for each user and perform delete/add operations
void check_eyedata(struct User *head) {
    struct User *current_user = head;
    struct User *prev = NULL;

    while (current_user != NULL) {//Loop for the User Linked List
        struct EyeData *current_eye = current_user->eyeList;
        struct EyeData *prev_eye = NULL;

        while (current_eye != NULL) {//Loop for the EyeData Linked List
            //Checking If there is a 0 value(s) in the eye data
            if (current_eye->PupilX == 0 || current_eye->PupilY == 0 || current_eye->IrisX == 0 ||
                current_eye->IrisY == 0 || current_eye->IrisR == 0 || current_eye->PupilR == 0) {
                char choice;
                printf("%s has eye data with zero value(s). Would you like to delete (d) or add new value (a)?\n", current_user->UserName);
                scanf(" %c", &choice);

                if (choice == 'd') {
                    // Delete the eye data node
                    if (prev_eye == NULL) {
                        current_user->eyeList = current_eye->next;
                    } else {
                        prev_eye->next = current_eye->next;
                    }
                    struct EyeData *temp = current_eye;
                    current_eye = current_eye->next;
                    free(temp);
                    printf("Eye data deleted.\n");
                } else if (choice == 'a') {
                    // Enter new values for eye data
                    printf("Enter new values for eye data (PupilX PupilY IrisX IrisY IrisR PupilR): ");
                    scanf("%d %d %d %d %d %d", &current_eye->PupilX, &current_eye->PupilY, &current_eye->IrisX,
                          &current_eye->IrisY, &current_eye->IrisR, &current_eye->PupilR);
                    printf("New eye data added.\n");
                    current_eye = current_eye->next;
                } else {
                    printf("Invalid choice. Please enter 'd' to delete or 'a' to add new values.\n");
                }
            } else {
                prev_eye = current_eye;
                current_eye = current_eye->next;
            }
        }

        // Move to the next user
        prev = current_user;
        current_user = current_user->next;

        // Delete the user if all eye data nodes were deleted
        if (prev->eyeList == NULL) {
            if (prev == head) {
                head = head->next;
                free(prev); // Free the memory allocated for the deleted user
                prev = head; // Update prev pointer
            } else {
                prev->next = current_user;
                free(prev); // Free the memory allocated for the deleted user
                prev = prev->next; // Update prev pointer
            }
            printf("%s deleted.\n",prev->UserName);
        }
    }
}
// Function to display statistics for a particular user
void display_statistics(struct User *head) {
    char username[50];
    printf("Enter a user name: ");
    scanf("%s", username);

    // Convert the username to lowercase for case-insensitive search
    for (int i = 0; username[i]; i++) {
        username[i] = tolower(username[i]);
    }

    struct User *current_user = head;
    struct User *prev = NULL; // To keep track of the previous user
    while (current_user != NULL) {
        // Convert the current user's name to lowercase for comparison
        char lowercase_username[50];
        strcpy(lowercase_username, current_user->UserName);
        for (int i = 0; lowercase_username[i]; i++) {
            lowercase_username[i] = tolower(lowercase_username[i]);
        }

        if (strcmp(lowercase_username, username) == 0) {
            // Found the user, display statistics
            int eye_count = count_eyes(current_user->eyeList);
            printf("%s has %d eye data and ", current_user->UserName, eye_count);
            age_groups(current_user);
            return;
        }
        prev = current_user; // Update prev pointer
        current_user = current_user->next;
    }

    // If the loop completes without finding the user, check if the previous user was deleted
    if (prev != NULL && prev->eyeList == NULL) {
        printf("%s deleted.\n", prev->UserName);
        free(prev); // Free memory allocated for the deleted user
    } else {//If the user is not found and it is also not deleted
        printf("%s does not exist.\n", username);
    }
}
int main() {
    // Load eye data from file
    char filename[50];
    printf("\nEnter file name:");
    scanf("%s",&filename);
    struct User *head= load_data(filename);
    printf("The eye data is successfully loaded.\n");

    // Check and update eye data
    check_eyedata(head);

    int choice;
    //Main function to control and coordinate the commands
    do {
        printf("\n----------------------------------------------\n");
        printf("(1) Display the statistics\n");
        printf("(0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                display_statistics(head);
                break;
            }
            case 0: {
                printf("Exiting the program.\n");
                return 0;//Exiting the program when the choice is 0
            }
            default: {
                printf("Invalid choice. Please enter 0 or 1.\n");
                break;
            }
        }
    } while (choice != 0);

    // Remember to free memory when done
    display_statistics(head);
    freeUsers(head);
    return 0;
}
