/*
 * This program manages instructor records using a binary search tree (BST).
 * Features:
 * - Insert instructor names and titles into a BST
 * - Display the tree in-order
 * - Search for an instructor by full name and return their title
 * - Search for all instructors whose names begin with a specific character
 *
 * Note: Instructor names are compared lexicographically for BST ordering.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

struct TreeNode
{
    int val;
    char *instructor;
    char *title;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* CreateTree(void);
struct TreeNode* Insert(int,char *,char *,struct TreeNode*);
char *searchInstructor(char instructor[],struct TreeNode *t);
void searchInstructors(char *c,struct TreeNode *t,int size);
void DisplayTree(struct TreeNode*);

int main()
{
    struct TreeNode* myTree;
    int exit;
    int val=0;
    char *instructor= (char *) malloc(sizeof(char)*100);
    char *title= (char *) malloc(sizeof(char)*100);
    char command='\n';
    char *c=(char *) malloc(sizeof(char)*100);
    int size=0;
    myTree = CreateTree();
    exit = FALSE;
    while (!exit)
    {
        fflush(stdin);
        printf("\nMenu:\n i)nitialize\n n)ew element \nt)instructor title \ns)search instructor \n e)xit\nEnter command: ");
        scanf(" %c", &command);
        switch(command)
        {
            fflush(stdin);
            case 'i':
                myTree = CreateTree();
                break;
            case 'n':
                fflush(stdin);
                //DO NOT LEAVE SPACE BETWEEN INSTRUCTORS NAME AND SURNAME
                //DO NOT LEAVE SPACE BETWEEN THE TITLES OF THE INSTRUCTOR
                printf("\nEnter instructors name:");
                scanf("%s",instructor);
                printf("\nEnter his/her title:");
                scanf("%s",title);
                myTree = Insert(val, instructor,title, myTree);
                size++;
                printf("Tree now:\n");
                DisplayTree(myTree);
                break;

            case 't':
                printf("\nEnter instructors name:");
                scanf("%s",instructor);
                char *foundTitle = searchInstructor(instructor, myTree);
 
                    if (strcmp(foundTitle, "n") == 0) {
                            printf("\nThis instructor does not exist!");
                   } 
                    else {
                            printf("%s", foundTitle);
                          }

                break;
            case 's':
                printf("\nEnter a character:");
                scanf("%s",c);
                searchInstructors(c,myTree,size);
                break;
            case 'e':
                exit = TRUE;
                break;
            default:
                printf("command not recognized\n");
                break;
        }//end switch
    }//end while

    printf("\n\n");
    system("PAUSE");
    return 0;
}//end main

struct TreeNode* CreateTree(void)
{
    return NULL;
}

struct TreeNode* Insert(int val,char instructor[],char title[],struct TreeNode* t)
{
    if(t == NULL)
    {
        t = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        if(t == NULL)
            printf("Out of memory space!!!\n");
        else
        {
            t->val = val;
            t->instructor=strdup(instructor);
            t->title=strdup(title);
            t->left = t->right = NULL;
        }
    }
    else {
        if (strcmp(instructor,t->instructor)<0)
            t->left = Insert(val, instructor,title, t->left);
        else if (strcmp(instructor,t->instructor)>0)
            t->right = Insert(val, instructor,title, t->right);
    }
    return t;
}
char *searchInstructor(char instructor[],struct TreeNode *t)
{
    if(t==NULL)
    {
        return "n";
    }
    int cmp= strcmp(instructor,t->instructor);
    if(cmp==0)
    {
        return t->title;
    }
    if(cmp<0)
    {
        return searchInstructor(instructor,t->left);
    }
    else
    {
        return searchInstructor(instructor,t->right);
    }

}
void searchInstructors(char *c, struct TreeNode *t)
{
    if (t != NULL) {
        searchInstructors(c, t->left);
        if (t->instructor[0] == c[0]) {
            printf("\n%s %s", t->instructor, t->title);
        }
        searchInstructors(c, t->right);
    }
}
void DisplayTree(struct TreeNode* t)
{
    if (t !=NULL)
    {
        DisplayTree(t->left);
        printf("\n%s %s",t->instructor,t->title);
        DisplayTree(t->right);
    }
}
