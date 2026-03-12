#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graphArc {
    int weight;
    struct graphVertex *destination;
    struct graphArc *next;
};

struct graphVertex {
    struct graphVertex *next;
    char warehouseName[50];
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
void insertVertex(struct graphHead *head, char *data);
int insertArc(struct graphHead *head, char *fromKey, char *toKey, int weight);
void printAllArcOfVertex(struct graphVertex *graphVertexName);
void printAllVertex(struct graphHead *graphName);
void printAllVertexWithRoutes(struct graphHead *graphName);
void readRoutes(char *fileName, struct graphHead *warehouseGraph);
void readWarehouseNames(char *fileName, struct graphHead *warehouseGraph);
void getMostDeliveries(struct graphHead *warehouseGraph);
void sendMostDeliveries(struct graphHead *warehouseGraph);
void routesWithHighestDistance(struct graphHead *warehouseGraph);
void routesWithLowestDistance(struct graphHead *warehouseGraph);
int findPath(struct graphVertex *currentVertex,
             struct graphVertex *destinationVertex, int *totalDistance);
void checkDistance(struct graphHead *warehouseGraph, char *departure,
                   char *destination);

int main(int argc, char *argv[]) {
    struct graphHead *warehouseGraph = createGraph();

    readWarehouseNames("WarehouseLocations.txt", warehouseGraph);
    readRoutes("WarehouseRoutes.txt", warehouseGraph);

    printf("\nWarehouse and route data read successfully.\n");

    printf("\nRead warehouse locations:\n");
    printAllVertex(warehouseGraph);

    printf("\nRead routes:\n");
    printAllVertexWithRoutes(warehouseGraph);

    printf("\n");
    getMostDeliveries(warehouseGraph);

    printf("\n");
    sendMostDeliveries(warehouseGraph);

    printf("\n");
    routesWithHighestDistance(warehouseGraph);

    printf("\n");
    routesWithLowestDistance(warehouseGraph);

    printf("\n");
    if (argc > 1) {
        checkDistance(warehouseGraph, argv[1], argv[2]);
    }
}

struct graphHead *createGraph() {
    struct graphHead * head =
      (struct graphHead *)malloc(sizeof(struct graphHead));
    head->count = 0;
    head->first = NULL;
    return head;
}

void insertVertex(struct graphHead *head, char *data) {
    struct graphVertex *vertex =
      (struct graphVertex *)malloc(sizeof(struct graphVertex));
    vertex->next = NULL;
    strcpy(vertex->warehouseName, data);
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

int insertArc(struct graphHead *head, char *fromKey, char *toKey, int weight) {
    struct graphVertex *from = head->first;
    struct graphVertex *to = head->first;

    while (from!=NULL && strcmp(from->warehouseName,fromKey)!=0) {
        from = from->next;
    }

    while (to!=NULL && strcmp(to->warehouseName,toKey)!=0) {
        to = to->next;
    }

    if (from == NULL || to == NULL) {
        return 0;
    }

    struct graphArc *arc = (struct graphArc*)malloc(sizeof(struct graphArc));
    arc->weight = weight;
    arc->destination = to;
    arc->next = NULL;

    if (from->firstArc==NULL) {
        from->firstArc = arc;
    }
    else {
        struct graphArc *temp = from->firstArc;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = arc;
    }
    from->outDegree++;
    to->inDegree++;
    return 1;
}

void printAllVertex(struct graphHead *graphName) {
    struct graphVertex *temp = graphName->first;
    while (temp!=NULL) {
        printf("\n%s",temp->warehouseName);
        temp = temp->next;
    }
}

void printAllArcOfVertex(struct graphVertex *graphVertexName) {
    struct graphArc *temp = graphVertexName->firstArc;
    while (temp!=NULL) {
        printf(" -%d-> %s |",temp->weight,temp->destination->warehouseName);
        temp=temp->next;
    }
}

void printAllVertexWithRoutes(struct graphHead *graphName) {
    struct graphVertex *temp = graphName->first;
    while (temp!=NULL) {
        if (temp->outDegree > 0) {
            printf("\n%s |",temp->warehouseName);
            printAllArcOfVertex(temp);
        }
        temp = temp->next;
    }
}

void readWarehouseNames(char *fileName, struct graphHead *warehouseGraph) {
    FILE *infile = fopen(fileName,"r");
    if (infile==NULL) {
        return;
    }

    char line[100];
    while (fgets(line,sizeof(line),infile)) {
        line[strcspn(line,"\n")] = 0;
        insertVertex(warehouseGraph,line);
    }
    fclose(infile);
}

void readRoutes(char *fileName, struct graphHead *warehouseGraph) {
    FILE *infile = fopen(fileName,"r");
    if (infile==NULL) {
        return;
    }

    char line[300];
    while (fgets(line,sizeof(line),infile)) {
        char *token = strtok(line,"\n;");
        char from[50];
        strcpy(from,token);
        while ((token = strtok(NULL,"\n;"))!=NULL) {
            int weight = atoi(token);
            token = strtok(NULL,"\n;");
            insertArc(warehouseGraph,from,token,weight);
        }
    }
    fclose(infile);
}

void getMostDeliveries(struct graphHead *warehouseGraph) {
    struct graphVertex *temp = warehouseGraph->first;
    int max = 0;
    while (temp!=NULL) {
        if (temp->inDegree > max) {
            max = temp->inDegree;
        }
        temp = temp->next;
    }

    printf("\nWarehouses that receives deliveries from the most different locations (%d):",max);
    temp = warehouseGraph->first;
    while (temp!=NULL) {
        if (temp->inDegree == max) {
            printf("\n- %s",temp->warehouseName);
        }
        temp = temp->next;
    }
}

void sendMostDeliveries(struct graphHead *warehouseGraph) {
    struct graphVertex *temp = warehouseGraph->first;
    int max = 0;
    while (temp!=NULL) {
        if (temp->outDegree > max) {
            max = temp->outDegree;
        }
        temp = temp->next;
    }

    printf("\nWarehouses that sends deliveries to most different locations (%d):",max);
    temp = warehouseGraph->first;

    while (temp!=NULL) {
        if (temp->outDegree == max) {
            printf("\n- %s",temp->warehouseName);
        }
        temp = temp->next;
    }
}

void routesWithHighestDistance(struct graphHead *warehouseGraph) {
    struct graphVertex *temp = warehouseGraph->first;
    struct graphArc *arc = temp->firstArc;
    int max = 0;
    while (temp!=NULL) {
        while (arc!=NULL) {
            if (arc->weight > max) {
                max = arc->weight;
            }
            arc = arc->next;
        }
        temp = temp->next;
        if (temp!=NULL) {
            arc = temp->firstArc;
        }
    }

    printf("\nRoutes with the highest distance (%d): ",max);
    temp = warehouseGraph->first;
    arc = temp->firstArc;
    while (temp!=NULL) {
        while (arc!=NULL) {
            if (arc->weight == max) {
                printf("\n %s -%d-> %s",temp->warehouseName,arc->weight,arc->destination->warehouseName);
            }
            arc = arc->next;
        }
        temp = temp->next;
        if (temp!=NULL) {
            arc = temp->firstArc;
        }
    }
}

void routesWithLowestDistance(struct graphHead *warehouseGraph) {
    struct graphVertex *temp = warehouseGraph->first;
    struct graphArc *arc = temp->firstArc;
    int min = arc->weight;
    while (temp!=NULL) {
        while (arc!=NULL) {
            if (arc->weight < min) {
                min = arc->weight;
            }
            arc = arc->next;
        }
        temp = temp->next;
        if (temp!=NULL) {
            arc = temp->firstArc;
        }
    }

    printf("\nRoutes with the lowest distance (%d): ",min);
    temp = warehouseGraph->first;
    arc = temp->firstArc;
    while (temp!=NULL) {
        while (arc!=NULL) {
            if (arc->weight == min) {
                printf("\n %s -%d-> %s",temp->warehouseName,arc->weight,arc->destination->warehouseName);
            }
            arc = arc->next;
        }
        temp = temp->next;
        if (temp!=NULL) {
            arc = temp->firstArc;
        }
    }
}

int findPath(struct graphVertex *currentVertex,
             struct graphVertex *destinationVertex, int *totalDistance) {
    if (currentVertex==destinationVertex) {
        printf("%s ",currentVertex->warehouseName);
        return 1;
    }

    currentVertex->processed = 1;
    struct graphArc *arc = currentVertex->firstArc;
    while (arc!=NULL) {
        if (arc->destination->processed == 0) {
            int w = arc->weight;
            if (findPath(arc->destination,destinationVertex,totalDistance)==1) {
                printf(" <-%d- %s",w,currentVertex->warehouseName);
                *totalDistance += w;
                return 1;
            }
        }
        arc = arc->next;
    }
    return 0;
}

void checkDistance(struct graphHead *warehouseGraph, char *departure,
                   char *destination) {
    struct graphVertex *from = warehouseGraph->first;
    struct graphVertex *to = warehouseGraph->first;

    while (from !=NULL && strcmp(from->warehouseName,departure)!=0) {
        from = from->next;
    }

    while (to!=NULL && strcmp(to->warehouseName,destination)!=0) {
        to = to->next;
    }

    if (from == NULL || to == NULL) {
        return ;
    }

    printf("Searching for a route from %s to %s... \n",departure,destination);
    struct graphVertex *temp = warehouseGraph->first;
    while (temp!=NULL) {
        temp->processed = 0;
        temp = temp->next;
    }

    int total = 0;
    if (findPath(from,to,&total)==1) {
        printf("\nTotal Distance: %d",total);
    }
}
