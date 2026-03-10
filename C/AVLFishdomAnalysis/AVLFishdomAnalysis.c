/*
 * Fishdom AVL Tree Analysis
 *
 * This program reads fish records from a CSV file and stores them
 * in an AVL tree ordered by weight. It supports:
 *
 * - Reading and parsing data: name, weight, length, date, city
 * - Inserting fish records into a balanced AVL tree
 * - Handling multiple fish with the same weight in a node
 * - Displaying all fish in ascending order of weight
 * - Finding and printing the heaviest and longest fish entries
 *
 * Usage:
 *   ./program_name <input_filename>
 *
 * Notes:
 * - AVL tree maintains balance for efficient insertions and lookups
 * - Dynamic memory is used with safety checks
 * - A cleanup function is recommended for memory deallocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"  // Include the AVL tree header file
//Function definition for InsertFish()
AVLTREENODE * insertFish(AVLTREENODE *root, char name[], int weight, float length, char date[], char city[]);
//Function definition for readData()
AVLTREENODE * readData(const char *filename);
//Function definition for displayIndex()
void displayIndex(AVLTREENODE *root);
//Function definition for heaviestFish()
int heaviestFish(AVLTREENODE *root);
//Function definition for longestFish()
float longestFish(AVLTREENODE *root);

AVLTREENODE * createNode(char name[], int weight, float length, char date[], char city[]);
// Function to insert a New Node into an existing AVLNode
AVLTREENODE * insertFishNode(AVLTREENODE *node, char name[], int weight, float length, char date[], char city[]);


// Function to read data from the external file and construct an AVL tree
// Function to read data from the external file and construct an AVL tree
AVLTREENODE * readData(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    AVLTREENODE *root = NULL;

    char line[100];  // Assuming each line in the file is less than 100 characters
    while (fgets(line, sizeof(line), file) != NULL) {
        char name[30];
        int weight;
        float length;
        char date[20];
        char city[30];

        // Updated format specifier to handle possible semicolon in the date field
        if (sscanf(line, "%29[^,],%d,%f,%19[^,],%29[^\n]", name, &weight, &length, date, city) == 5) {
            // Insert the fish into the AVL tree
            root = insertFish(root, name, weight, length, date, city);
        } else {
            fprintf(stderr, "Failed to parse line: %s", line);
        }
    }

    fclose(file);
    return root;
}

// Function to create an AVL Tree with a single node
AVLTREENODE * createNode(char name[], int weight, float length, char date[], char city[]) {
    AVLTREENODE *newNode = (AVLTREENODE *)malloc(sizeof(AVLTREENODE ));//dynamically allocating memory for the new node
    if (newNode == NULL) {//checking if the allocation failed
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    //
    newNode->fishData = (Fishdom *)malloc(sizeof(Fishdom));
    if (newNode->fishData == NULL) {//checking if the allocation failed
        fprintf(stderr, "Memory allocation error.\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }

    //Copying the input name to the name value of the new node(strncpy is used for copying strings)
    // we put fishData after newNode so like "newNode->fishData" because fishData is the pointer that allows us to access the values in the Fishdom structure
    strncpy(newNode->fishData->name, name, sizeof(newNode->fishData->name) - 1);
    newNode->fishData->name[sizeof(newNode->fishData->name) - 1] = '\0';//Making sure that the memory allocation stops
    newNode->fishData->weight = weight;//setting the weight value in newNode to the weight value taken as input
    newNode->fishData->length = length;
    //Copying the input date to the date value of the new node
    strncpy(newNode->fishData->date, date, sizeof(newNode->fishData->date) - 1);
    newNode->fishData->date[sizeof(newNode->fishData->date) - 1] = '\0';//Making sure that the memory allocation stops
    //Copying the input city name to the city name value of the new node
    strncpy(newNode->fishData->city, city, sizeof(newNode->fishData->city) - 1);
    newNode->fishData->city[sizeof(newNode->fishData->city) - 1] = '\0';//Making sure that the memory allocation stops

    newNode->num_fish = 1;// setting the num_fish to 1 as there is now one node storing the properties of a fish
    newNode->left = newNode->right = NULL;//as there is only one node both its left and right is NULL
    newNode->height = 1;//setting height to 1 as now there is a node in the tree

    return newNode;
}

// Function to insert a New Node into an existing AVLNode
AVLTREENODE * insertFishNode(AVLTREENODE *node, char name[], int weight, float length, char date[], char city[]) {
    if (node == NULL) {
        return createNode(name, weight, length, date, city);
    }
       // AVL is a variation of BST so the smaller weights will be on the left, larger weights will be on the right
       //fish with less weight, add it to the left of the tree
    if (weight < node->fishData[0].weight) {
        node->left = insertFishNode(node->left, name, weight, length, date, city);
        //fish with more weight, add it to the right of the tree
    } else if (weight > node->fishData[0].weight) {
        node->right = insertFishNode(node->right, name, weight, length, date, city);
    } else {
        // Fish with the same weight, add to the array
        node->fishData = realloc(node->fishData, (node->num_fish + 1) * sizeof(Fishdom ));
        if (node->fishData == NULL) {//check if the memory allocation was successful
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }

        node->fishData[node->num_fish].weight = weight;
        // Copying other details(name,date,city etc.)
        strncpy(node->fishData[node->num_fish].name, name, sizeof(node->fishData[node->num_fish].name) - 1);
        node->fishData[node->num_fish].name[sizeof(node->fishData[node->num_fish].name) - 1] = '\0';//Making sure that the memory allocation stops
        node->fishData[node->num_fish].length = length;
        strncpy(node->fishData[node->num_fish].date, date, sizeof(node->fishData[node->num_fish].date) - 1);
        node->fishData[node->num_fish].date[sizeof(node->fishData[node->num_fish].date) - 1] = '\0';//Making sure that the memory allocation stops
        strncpy(node->fishData[node->num_fish].city, city, sizeof(node->fishData[node->num_fish].city) - 1);
        node->fishData[node->num_fish].city[sizeof(node->fishData[node->num_fish].city) - 1] = '\0';//Making sure that the memory allocation stops

        node->num_fish++;
    }

    // Update height and balance factor
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Perform R Single Rotation
    if (balance > 1 && weight < node->left->fishData[0].weight)
        return rotateRight(node);
    // Perform L Single Rotation
    if (balance < -1 && weight > node->right->fishData[0].weight)
        return rotateLeft(node);
    // Perform LR Double Rotation
    if (balance > 1 && weight > node->left->fishData[0].weight) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Perform RL Double Rotation
    if (balance < -1 && weight < node->right->fishData[0].weight) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Function to insert a new fish into the AVL tree
AVLTREENODE * insertFish(AVLTREENODE *root, char name[], int weight, float length, char date[], char city[]) {
    return insertFishNode(root, name, weight, length, date, city);
}
// Function to display the fish data in ascending order based on weight
void displayIndex(AVLTREENODE *node) {
    if (node != NULL) {
        // Displaying data from the left subtree
        displayIndex(node->left);

        // Displaying data for each fish in the node
        for (int i = 0; i < node->num_fish; i++) {
            printf("%s,%d,%.2f,%s,%s\n", node->fishData[i].name, node->fishData[i].weight,
                   node->fishData[i].length, node->fishData[i].date, node->fishData[i].city);
        }

        // Displaying data from the right subtree
        displayIndex(node->right);
    }
}
// Function to find and display the details of the heaviest fish(es)
int heaviestFish(AVLTREENODE *node) {
    int maxWeight = 0;  // Initialize maxWeight to 0

    if (node != NULL) {
        // Finding the heaviest fish in the right subtree first
        int rightMax = heaviestFish(node->right);
        maxWeight = (rightMax > maxWeight) ? rightMax : maxWeight;

        // Checking each fish in the node
        for (int i = 0; i < node->num_fish; i++) {
            if (node->fishData[i].weight == maxWeight) {
                // Display details of the heaviest fish
                printf("%s,%d,%.2f,%s,%s\n", node->fishData[i].name, node->fishData[i].weight,
                       node->fishData[i].length, node->fishData[i].date, node->fishData[i].city);
            }
        }

        // Update the maxWeight if a heavier fish is found
        if (node->fishData[0].weight > maxWeight) {
            maxWeight = node->fishData[0].weight;
        }

        // Find the heaviest fish in the left subtree
        int leftMax = heaviestFish(node->left);
        maxWeight = (leftMax > maxWeight) ? leftMax : maxWeight;
    }

    return maxWeight;
}

// Function to find and display the details of the fish with the maximum length
float longestFish(AVLTREENODE *node) {
    float maxLength = 0.0;  // Initialize maxLength to 0.0

    if (node != NULL) {
        // Find the longest fish in the right subtree first
        float rightMax = longestFish(node->right);
        maxLength = (rightMax > maxLength) ? rightMax : maxLength;

        // Check each fish in the node
        for (int i = 0; i < node->num_fish; i++) {
            if (node->fishData[i].length == maxLength) {
                // Display details of the longest fish
                printf("%s,%d,%.2f,%s,%s\n", node->fishData[i].name, node->fishData[i].weight,
                       node->fishData[i].length, node->fishData[i].date, node->fishData[i].city);
            }
        }

        // Update the maxLength if a longer fish is found
        if (node->fishData[0].length > maxLength) {
            maxLength = node->fishData[0].length;
        }

        // Find the longest fish in the left subtree
        float leftMax = longestFish(node->left);
        maxLength = (leftMax > maxLength) ? leftMax : maxLength;
    }

    return maxLength;
}
int main(int argc, char *argv[]) {
    // Checking if the filename is provided as a command line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Reading the data from the file and building the AVL tree
    AVLTREENODE *root = readData(argv[1]);
    // Displaying the menu and process user options
    int option=0;
    printf("********Welcome to Fishdom Analysis********\n");
    printf("*******************************************\n");
    while(option!=4)
    {
        printf("Menu\n");
        printf("1. Display the full index of Fishdom\n");
        printf("2. Display the heaviest fishes\n");
        printf("3. Display the longest fishes\n");
        printf("4. Exit\n");
        printf("*******************************************\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("*******************************************\n");
                displayIndex(root);
                printf("*******************************************\n");
                break;
            case 2:
                printf("*******************************************\n");
                // You can optionally print the maxWeight value here if needed
                printf("Max Weight: %d\n", heaviestFish(root));
                printf("*******************************************\n");
                break;
            case 3:
                printf("*******************************************\n");
                // You can optionally print the maxLength value here if needed
                printf("Max Length: %.2f\n", longestFish(root));
                printf("*******************************************\n");
                break;
            case 4:
                printf("Bye\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
