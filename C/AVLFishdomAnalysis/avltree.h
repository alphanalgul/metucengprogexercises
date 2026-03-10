
#ifndef ASSIGNMENT3_AVLTREE_H
#define ASSIGNMENT3_AVLTREE_H
//Structure Definition for the AVL Tree
typedef struct Fishdom
{
    char name[50];
    int weight;
    float length;
    char date[20];
    char city[50];
}
Fishdom; // To access the Fishdom data structure
typedef struct AVLTREENODE
{
        Fishdom *fishData;  // Fish data from the structure Fishdom
        int num_fish;       // Number of fish in this node
        //AVL Definition
        struct AVLTREENODE *left;
        struct AVLTREENODE *right;
        int height;
}
AVLTREENODE;// To access the AVLTREENODE data structure

//Major Functionalities of AVL TREE

// Function to return the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Function to get the height of a node
int getHeight(AVLTREENODE *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}
//Function to find balance
int getBalance(AVLTREENODE *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
// Function to perform a right rotation
AVLTREENODE * rotateRight(AVLTREENODE *x) {
    AVLTREENODE *y = x->left;
    AVLTREENODE *T2 = y->right;

    // Perform rotation
    y->right = x;
    x->left = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}
//Function to Rotate Left
AVLTREENODE * rotateLeft(AVLTREENODE *y) {
    AVLTREENODE *x = y->right;
    AVLTREENODE *T2 = x->left;

    // Perform rotation
    x->left = y;
    y->right = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}
#endif //ASSIGNMENT3_AVLTREE_H
