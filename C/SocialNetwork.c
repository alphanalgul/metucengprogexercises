#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graphArc {
    struct graphVertex *destination;
    struct graphArc *next;
};

struct graphVertex {
    struct graphVertex *next;
    char userName[50];
    int inDegree;
    int outDegree;
    int processed;
    struct graphArc *firstArc;
};

struct graphHead {
    int count;
    struct graphVertex *first;
};

struct graphHead *createGraph();
void addUser(struct graphHead *head, char *userName);
void addFriendship(struct graphHead *head, char *userName1, char *userName2);

void printAllFriendsfUsers(struct graphVertex *graphVertexName);
void printAllUsers(struct graphHead *graphName);
void printAllFriendships(struct graphHead *graphName);

void findMostFollowedUser(struct graphHead *head);
void findMostFollowingUser(struct graphHead *head);
void resetProcessedFlags(struct graphHead *head);
void dfsFindPath(struct graphHead *head, char *startUser, char *endUser);
int dfsRecursive(struct graphVertex *current, struct graphVertex *end);

void Menu();
int getUserChoice();
void handleUserChoice(int choice, struct graphHead *socialNetworkGraph);

int main() {
    struct graphHead *socialNetworkGraph = createGraph();

    addUser(socialNetworkGraph, "John");
    addUser(socialNetworkGraph, "Alice");
    addUser(socialNetworkGraph, "Bob");
    addUser(socialNetworkGraph, "David");
    addUser(socialNetworkGraph, "Eve");
    addUser(socialNetworkGraph, "Frank");

    addFriendship(socialNetworkGraph, "John", "Alice");
    addFriendship(socialNetworkGraph, "John", "Bob");
    addFriendship(socialNetworkGraph, "John", "Eve");
    addFriendship(socialNetworkGraph, "Alice", "John");
    addFriendship(socialNetworkGraph, "Alice", "David");
    addFriendship(socialNetworkGraph, "Bob", "John");
    addFriendship(socialNetworkGraph, "Bob", "Eve");
    addFriendship(socialNetworkGraph, "David", "Alice");
    addFriendship(socialNetworkGraph, "Eve", "Bob");
    addFriendship(socialNetworkGraph, "Eve", "Frank");
    addFriendship(socialNetworkGraph, "Frank", "Eve");
    addFriendship(socialNetworkGraph, "Frank", "Bob");

    printf("Welcome to METU NCC Social Network!\n");

    printf("\nUsers in the network:\n");
    printAllUsers(socialNetworkGraph);

    printf("\nFriendship Bonds:\n");
    printAllFriendships(socialNetworkGraph);

    while (1) {
        Menu();
        int choice = getUserChoice();
        if (choice == 4) {
            printf("BYE!!!\n");
            break;
        }
        handleUserChoice(choice, socialNetworkGraph);
    }

    return 0;
}

void Menu() {
    printf("\n========== MENU ==========\n");
    printf("1. Depth-First search for friendship\n");
    printf("2. Find the user who has the most followers\n");
    printf("3. Find the user who follows the most users\n");
    printf("4. Exit\n");
    printf("=========================\n");
}

int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid input. Please enter a valid choice (1-4): ");
        while (getchar() != '\n');
    }
    return choice;
}

void handleUserChoice(int choice, struct graphHead *socialNetworkGraph) {
    switch (choice) {
        case 1: {
            char startUser[50], endUser[50];
            printf("Enter User 1: ");
            scanf("%s", startUser);
            printf("Enter User 2: ");
            scanf("%s", endUser);
            dfsFindPath(socialNetworkGraph, startUser, endUser);
            break;
        }
        case 2:
            findMostFollowedUser(socialNetworkGraph);
            break;
        case 3:
            findMostFollowingUser(socialNetworkGraph);
            break;
        case 4:
            break;
    }
}

struct graphHead *createGraph() {
    struct graphHead * head =
            (struct graphHead *)malloc(sizeof(struct graphHead));
    head->count = 0;
    head->first = NULL;
    return head;
}

void addUser(struct graphHead *head, char *userName) {
    struct graphVertex *vertex =
            (struct graphVertex *)malloc(sizeof(struct graphVertex));
    vertex->next = NULL;
    strcpy(vertex->userName, userName);
    vertex->inDegree = 0;
    vertex->outDegree = 0;
    vertex->firstArc = NULL;
    vertex->processed = 0;
    head->count += 1;
    if (head->first == NULL) {
        head->first = vertex;
    } else {
        struct graphVertex *temp = head->first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = vertex;
    }
}

void addFriendship(struct graphHead *head, char *userName1, char *userName2)
{
    struct graphVertex *user1 = NULL, *user2 = NULL;

    struct graphVertex *temp = head->first;
    while (temp != NULL) {
        if (strcmp(temp->userName, userName1) == 0) {
            user1 = temp;
            break;
        }
        temp = temp->next;
    }

    temp = head->first;
    while (temp != NULL) {
        if (strcmp(temp->userName, userName2) == 0) {
            user2 = temp;
            break;
        }
        temp = temp->next;
    }

    if (user1 == NULL || user2 == NULL) {
        printf("One or both users not found!\n");
        return;
    }

    struct graphArc *newArc1 = (struct graphArc *)malloc(sizeof(struct graphArc));
    newArc1->destination = user2;
    newArc1->next = NULL;
    if(user1->firstArc == NULL) user1->firstArc = newArc1;
    else{
        struct graphArc *temp = user1->firstArc;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newArc1;
    }
    user1->outDegree++;
    user2->inDegree++;
}


void printAllFriendsfUsers(struct graphVertex *graphVertexName) {
    struct graphArc *arc = graphVertexName->firstArc;
    printf("%s's friends: ", graphVertexName->userName);
    while (arc != NULL) {
        printf("%s ", arc->destination->userName);
        arc = arc->next;
    }
    printf("\n");
}

void printAllUsers(struct graphHead *graphName) {
    struct graphVertex *temp = graphName->first;
    while (temp != NULL) {
        printf("%s\n", temp->userName);
        temp = temp->next;
    }
}

void printAllFriendships(struct graphHead *graphName) {
    struct graphVertex *temp = graphName->first;
    while (temp != NULL) {
        printAllFriendsfUsers(temp);
        temp = temp->next;
    }
}

void findMostFollowedUser(struct graphHead *head) {

    //WRITE YOUR CODE HERE
    struct graphVertex *temp = head->first;
    int max = 0;
    while (temp!=NULL) {
        if (temp->inDegree > max) {
            max = temp->inDegree;
        }
        temp = temp->next;
    }

    printf("\nMost followed User(s) (%d):",max);
    temp = head->first;
    while (temp!=NULL) {
        if (temp->inDegree == max) {
           printf("\n- %s",temp->userName);
        }
        temp = temp->next;
    }

}

void findMostFollowingUser(struct graphHead *head) {

    //WRITE YOUR CODE HERE
    struct graphVertex *temp = head->first;
    int max = 0;
    while (temp!=NULL) {
        if (temp->outDegree > max) {
            max = temp->outDegree;
        }
        temp = temp->next;
    }

    printf("\nMost following User(s) (%d):",max);
    temp = head->first;
    while (temp!=NULL) {
        if (temp->outDegree == max) {
            printf("\n- %s",temp->userName);
        }
        temp = temp->next;
    }

}

void resetProcessedFlags(struct graphHead *head) {
    struct graphVertex *temp = head->first;
    while (temp != NULL) {
        temp->processed = 0;
        temp = temp->next;
    }
}

void dfsFindPath(struct graphHead *head, char *startUser, char *endUser) {
    struct graphVertex *start = NULL, *end = NULL;
    resetProcessedFlags(head);
    struct graphVertex *temp = head->first;
    while (temp != NULL) {
        if (strcmp(temp->userName, startUser) == 0) {
            start = temp;
        }
        if (strcmp(temp->userName, endUser) == 0) {
            end = temp;
        }
        temp = temp->next;
    }

    if (start == NULL || end == NULL) {
        printf("One or both users not found.\n");
        return;
    }

    dfsRecursive(start, end);
}

int dfsRecursive(struct graphVertex *current, struct graphVertex *end) {

    //WRITE YOUR CODE HERE
    //It returns 1 if the paths is found, or 0 if not found
    if (current == end) {
        printf("\nPath Found! %s",current->userName);
        return 1;
    }

    current->processed = 1;
    struct graphArc *arc = current->firstArc;
    while (arc!=NULL) {
        if (arc->destination->processed == 0) {
            if (dfsRecursive(arc->destination,end)==1) {
                printf(" <- %s",current->userName);
                return 1;
            }
        }
        arc = arc->next;
    }
    return 0;
}