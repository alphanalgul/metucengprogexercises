#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BorrowRecord {
    char borrowID[20];
    char bookTitle[200];
    char author[300];
    char borrowDate[20];
    struct BorrowRecord* next;
} BorrowRecord;

typedef struct {
    int studentID;
    char studentName[50];
    BorrowRecord* borrowList;
    int borrowCount;
} Student;

typedef struct {
    int isOccupied;
    Student student;
} HashEntry;

//helper functions
int calculate_key(int id);
int linear_probing(int key, int table_size, int i);
int quadratic_probing(int key, int table_size, int i);
int double_hashing(int key, int table_size, int i);
int prime(int num);
int next_prime(int num);
double load_factor(HashEntry* table, int *sizePtr);
int search_student(HashEntry *table, int *sizePtr,int method, int id);
//prototypes
HashEntry* createHashTable(int size);
HashEntry* readBorrowings(FILE* inFile, HashEntry* table, int* sizePtr, int method);
HashEntry* addStudent(HashEntry* table, Student addedStudent, int* sizePtr, int method);
HashEntry* rehash(HashEntry* table, int* sizePtr, int method);
void printTable(HashEntry* table, int size);
void searchTable(HashEntry* table, int size, int studentID, int method);
void returnBook(HashEntry* table, int size, int studentID, char borrowID[], int method);

int main() {
    FILE* inFile = fopen("borrowed_books.txt", "r");
    if (!inFile) {
        printf("Error: Could not open borrowed_books.txt\n");
        return 1;
    }
    int method = 0;
    int tableSize = 11;
    printf("Select collision resolution technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing\n");
    printf("Enter your choice: ");
    scanf("%d", &method);
    while (method < 1 || method > 3) {
        printf("Invalid choice. Enter 1, 2, or 3: ");
        scanf("%d", &method);
    }
    HashEntry* table = createHashTable(tableSize);
    table = readBorrowings(inFile, table, &tableSize, method);
    fclose(inFile);
    int choice = -1;
    while (choice != 0) {
        printf("\n------ MENU ------\n");
        printf("1. Print Hash Table\n");
        printf("2. Search Student\n");
        printf("3. Return Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printTable(table, tableSize);
        } else if (choice == 2) {
            int sid;
            printf("Enter Student ID to search: ");
            scanf("%d", &sid);
            searchTable(table, tableSize, sid, method);
        } else if (choice == 3) {
            int sid;
            char borrowID[20];
            printf("Enter Student ID: ");
            scanf("%d", &sid);
            printf("Enter Borrow ID to return: ");
            scanf("%19s", borrowID);
            returnBook(table, tableSize, sid, borrowID, method);
        } else if (choice == 0) {
            printf("Exiting program...\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    free(table);
    return 0;
}

HashEntry* createHashTable(int size) {
    HashEntry* array = (HashEntry*) malloc(sizeof(HashEntry) * size);
    for (int i = 0; i < size; i++) {
        array[i].student.studentID = -1;
        array[i].student.borrowCount = 0;
        array[i].student.borrowList = NULL;
        strcpy(array[i].student.studentName, "unassigned");
        array[i].isOccupied = 0;
    }
    return array;
}

HashEntry* readBorrowings(FILE* inFile, HashEntry* table, int* sizePtr, int method) {

    //defining variables to store file data
    int student_id;
    char name[50];
    char borrow_id[20];
    char book_title[200];
    char author[300];
    char borrow_date[20];

    //skip the header
    char header[100];
    fgets(header,sizeof(header),inFile);

    int i = 0;

    //reading data from the file
    while (fscanf(inFile, "%d;%49[^;];%19[^;];%199[^;];%299[^;];%19[^\n]",&student_id,name,borrow_id
        ,book_title,author,borrow_date) == 6) {

        //end the loop if the data is larger than table size
        if ( i >= *sizePtr) {
            break;
        }

        //creating a new borrow record
        BorrowRecord *b = malloc(sizeof(BorrowRecord));
        strcpy(b->borrowID,borrow_id);
        strcpy(b->bookTitle,book_title);
        strcpy(b->borrowDate,borrow_date);
        strcpy(b->author,author);
        b->next = NULL;

        int index = search_student(table,sizePtr,method,student_id);

        //if the student already exists, append the new record to the end of their borrowed record list
        if (index != -1) {
            BorrowRecord * current = table[index].student.borrowList;
            while (current->next != NULL) {
                current = current -> next;
            }
            current->next = b;
            table[index].student.borrowCount++;
        }

        else {
            //creating a new student
            Student *s = malloc(sizeof(Student));
            s->borrowList = b;
            s->borrowCount=1;
            s->studentID = student_id;
            strcpy(s->studentName ,name);
            //adding student to the table
            table = addStudent(table,*s,sizePtr,method);

            printf("\n\n%d(%s) has been added to the table, the hash table now can be seen below:\n",student_id
            ,name);
            printTable(table,*sizePtr);
        }

        i++;
        }
    return table;
}

HashEntry* addStudent(HashEntry* table, Student addedStudent, int* sizePtr, int method) {
    double load = load_factor(table,sizePtr);
    if (load >= 0.5) {
        table = rehash(table,sizePtr,method);
    }
    for (int i = 0; i < *sizePtr; i++) {
        int key,hash;
        //linear probing
        if (method == 1) {
             key = calculate_key(addedStudent.studentID);
            hash = linear_probing(key,*sizePtr,i);
        }
        //quadratic probing
        if (method == 2) {
            key = calculate_key(addedStudent.studentID);
            hash = quadratic_probing(key,*sizePtr,i);

        }
        //double hashing
        if (method == 3) {
            key = calculate_key(addedStudent.studentID);
            hash = double_hashing(key,*sizePtr,i);

        }
        //if the slot is empty insert
        if (table[hash].isOccupied == 0) {
            table[hash].student = addedStudent;
            table[hash].isOccupied = 1;
            return table;
        }
    }
    printf("\nThe table is full! Can't add any students!");
    return table;
}

HashEntry* rehash(HashEntry* table, int* sizePtr, int method) {
    int old_size = *sizePtr;
    int new_size = next_prime(*sizePtr * 2);

    printf("\n\n Load factor exceeded 0.5 rehashing table from size %d to %d."
        ,old_size,new_size);
    HashEntry *new_table = createHashTable(new_size);
    *sizePtr = new_size;

    for (int i = 0; i < old_size; i++) {
        if (table[i].isOccupied == 1) {
            new_table = addStudent(new_table,table[i].student, sizePtr,method);
        }
    }

    free(table);
    return new_table;
}

void printTable(HashEntry* table, int size) {
    printf("\nIndex \t StudentID \t Name \t         BorrowCount");
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied == 0) {
            printf("\n%d \t \t \t \t",i);
        }
        else {
            printf("\n%d \t %d \t %s \t         %d ",i,table[i].student.studentID,table[i].student.studentName,
                table[i].student.borrowCount);
        }
    }
}

void searchTable(HashEntry* table, int size, int studentID, int method) {
        int index = search_student(table,&size,method,studentID);
        if (index == -1) {
            printf("\nStudent not found!");
            return;
        }
        printf("\nStudent ID: %d",table[index].student.studentID);
        printf("\nStudent Name: %s",table[index].student.studentName);
        printf("\nNumber of Borrowed Books: %d\n",table[index].student.borrowCount);

       BorrowRecord * current = table[index].student.borrowList;
       while (current!=NULL) {
           printf("\nBorrow ID: %s",current->borrowID);
           printf("\nTitle: %s",current->bookTitle);
           printf("\nAuthors: %s", current->author);
           printf("\nBorrow Date: %s\n",current->borrowDate);
           current = current -> next;
    }

}


void returnBook(HashEntry* table, int size, int studentID, char borrowID[], int method) {
    int index = search_student(table,&size,method,studentID);
    if (index == -1) {
        printf("\nStudent not found!");
        return;
    }

    BorrowRecord * current = table[index].student.borrowList;
    BorrowRecord * prev =  NULL;

    while (current!=NULL) {
        if (strcmp(current->borrowID, borrowID) == 0) {
            if (prev == NULL) {
                table[index].student.borrowList = current->next;
            }
            else {
                prev -> next = current -> next;
            }


            free(current);
            table[index].student.borrowCount--;

            printf("\nBorrow ID %s removed for Student %d",borrowID,studentID);
            return;

        }
        prev = current;
        current = current -> next;
    }
    printf("\nBorrow ID %s not found for Student %d!",borrowID,studentID);
}

//Function to calculate the hash key from student id
int calculate_key(int id)
{
    int key = 1;
    while (id > 0)
    {
        int d = id % 10;
        if(d == 0)
        {
            d = 1;
        }
        key = key * d;

        id = id / 10;
    }
    return key;
}

//linear probing
int linear_probing(int key, int table_size, int i){
    return (key % table_size + i) % table_size;
}

//quadratic probing
int quadratic_probing(int key, int table_size, int i) {
    return (key % table_size + i*i) % table_size;
}

//double hashing
int double_hashing(int key,int table_size, int i ) {
    return (key % table_size + i* (7 - (key % 7)) ) % table_size;
}

// Checks if a number is prime
int prime(int num) {
    if (num <= 1) {
        return -1;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return -1;
        }
    }
    return 1;
}

// Finds the next prime number after a given number
int next_prime(int num)
{
    int check = 0;
    while (check==0)
    {
        if (prime(num) == 1)
        {
            check = 1;
            return num;
        }
        num++;
    }
}

//function to calculate load factor
double load_factor(HashEntry* table, int *sizePtr) {
    int n = 0;
    for (int i = 0; i < *sizePtr ; i++) {
        if (table[i].isOccupied == 1) {
            n++;
        }
    }
    return (double)n / *sizePtr;
}

//function to find the index of a student
int search_student(HashEntry *table, int *sizePtr, int method, int id) {
    int key,hash = 0;
    for (int i = 0; i < *sizePtr; i++) {
        //linear probing
        if (method == 1) {
            key = calculate_key(id);
            hash = linear_probing(key,*sizePtr,i);
        }
        //quadratic probing
        if (method == 2) {
            key = calculate_key(id);
            hash = quadratic_probing(key,*sizePtr,i);

        }
        //double hashing
        if (method == 3) {
            key = calculate_key(id);
            hash = double_hashing(key,*sizePtr,i);

        }

        if (table[hash].student.studentID == id && table[hash].isOccupied == 1) {
            return hash;
        }
    }
    return -1;
}