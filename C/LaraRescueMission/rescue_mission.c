
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//arc structure
struct arc {
    int distance;
    struct vertex *destination;
    struct arc *next;
};

//vertex structure
struct vertex {
    struct vertex *next;
    struct vertex *parent;
    char node_name[50];
    int cost;//required for UCS
    int in_degree;
    int out_degree;
    int processed;
    //coordinates for challenge 2
    int coordinate_1;
    int coordinate_2;
    struct arc *first;
};

//graph structure
struct graph_head {
    int count;
    struct vertex *first;
};

struct graph_head *create_graph() {
    struct graph_head * graph = malloc(sizeof(struct graph_head));
    graph->count = 0;
    graph->first = NULL;
    return graph;
}


void insert_vertex(struct graph_head *head, char *data) {
    struct vertex *vertex = malloc(sizeof(struct vertex));
    vertex->next = NULL;
    vertex->parent = NULL;
    vertex->first = NULL;

    vertex->in_degree = 0;
    vertex->out_degree = 0;
    vertex->processed = 0;
    head->count++;

    strcpy(vertex->node_name, data);
    vertex->cost = 999999999;
    vertex->coordinate_1 = 0;
    vertex->coordinate_2 = 0;

    if (head->first == NULL) {
        head->first = vertex;

    } else {
        struct vertex *temp = head->first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = vertex;
    }
}


int insert_arc(struct graph_head *head, char *fromKey, char *toKey, int weight) {

    struct vertex *from = head->first;
    struct vertex *to = head->first;

    while (from!=NULL && strcmp(from->node_name,fromKey)!=0) {
        from = from->next;
    }
    while (to!=NULL && strcmp(to->node_name,toKey)!=0) {
        to = to->next;
    }

    if (from == NULL || to == NULL) return 0;

    struct arc *arc = malloc(sizeof(struct arc));
    arc->distance = weight;
    arc->destination = to;
    arc->next = NULL;

    if (from->first==NULL) {
        from->first = arc;
    }
    else {
        struct arc *temp = from->first;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = arc;
    }
    from->out_degree++;
    to->in_degree++;
    return 1;
}


void print_graph(struct graph_head* graph) {
    struct vertex* vertex = graph->first;

    while (vertex != NULL) {
        printf("%s:", vertex->node_name);
        struct arc* arc = vertex->first;
        while (arc != NULL) {
            printf(" %s %d,", arc->destination->node_name, arc->distance);
            arc = arc->next;
        }
        printf("\n");
        vertex = vertex->next;
    }
}

//structures for queue
struct node {
    int distance;
    char node_name[50];
    struct node *next;
};
struct queue {
    struct node *head;
    struct node *tail;
};

void initialize_queue(struct queue *q) {
    q->head = NULL;
    q->tail = NULL;
}
int is_empty_queue(struct queue *q) {
    return (q->head == NULL);
}


void enqueue(struct queue * q,char *name) {
    struct node* n = malloc(sizeof(struct node));
    strcpy(n->node_name,name);
    n->next = NULL;

    if (q->head == NULL) {
        q->head = n;
        q->tail = n;
    }
    else {
        q->tail->next = n;
        q->tail = n;
    }
}


void enqueue_priority(struct queue *q, char *name, int distance) {
    struct node *node = malloc(sizeof(struct node));
    strcpy(node->node_name, name);
    node->distance = distance;
    node->next = NULL;

    if (q->head == NULL || distance< q->head->distance) {
        node->next = q->head;
        q->head = node;
        if (q->tail == NULL) {
            q->tail = node;
        }
        return;
    }

    struct node *current = q->head;
    while (current->next != NULL && current->next->distance <= distance) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    if (node->next == NULL) {
        q->tail = node;
    }
}

char *dequeue(struct queue *q) {
    if (q->head == NULL) {
        return NULL;
    }

    struct node *temp = q->head;
    char *name = malloc(strlen(temp->node_name) + 1);
    strcpy(name, temp->node_name);
    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return name;
}

void print_queue(struct queue *q) {
    struct node *temp = q->head;
    while (temp!=NULL) {
        printf("\n%s :%d",temp->node_name,temp->distance);
        temp = temp->next;
    }
}

//finding a location of a specific node (start, goal etc.)
struct vertex* find_vertex(struct graph_head *graph, char *name) {
    struct vertex *temp = graph->first;
    while (temp != NULL) {
        if (strcmp(temp->node_name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//initiaalizing all vertices before ucs and bfs
void reset_processed(struct graph_head *graph) {
    struct vertex *temp = graph->first;
    while (temp != NULL) {
        temp->processed = 0;
        temp->cost = 999999999;
        temp->parent = NULL;
        temp = temp->next;
    }
}

//finding which challenge is chosen
int challenge(struct vertex *goal) {
    struct vertex *temp = goal;

    while (temp != NULL) {
        if (strcmp(temp->node_name, "Challenge 1 (C1)") == 0) {
            return 1;
        }
        if (strcmp(temp->node_name, "Challenge 2 (C2)") == 0) {
            return 2;
        }
        temp = temp->parent;
    }
    return 0;
}

void print_solution_path(struct vertex *goal) {
    if (goal == NULL) return;

    if (goal->parent != NULL) {
        print_solution_path(goal->parent);
        printf(" -> ");
    }

    printf("%s", goal->node_name);
}

//heuristic for a*
int heuristic_challenge1(struct vertex *current) {
    int G, P, B;
    sscanf(current->node_name, "(%d,%d,%d)", &G, &P, &B);
    return (G + P + 1) / 2;
}

void a_star(struct graph_head *graph, char *start_name, char *goal_name) {
    struct queue q;
    initialize_queue(&q);

    struct vertex *start = find_vertex(graph, start_name);
    struct vertex *goal = find_vertex(graph, goal_name);

    if (start == NULL || goal == NULL) {
        printf("Start or goal node not found!\n");
        return;
    }

    start->cost = 0;
    start->parent = NULL;

    enqueue_priority(&q, start->node_name, start->cost + heuristic_challenge1(start));

    printf("\nA* Search for Challenge 1:\n");
    printf("\nExpansion Order:\n");

    while (!is_empty_queue(&q)) {
        char *name = dequeue(&q);
        struct vertex *current = find_vertex(graph, name);

        if (current->processed == 1) {
            free(name);
            continue;
        }

        current->processed = 1;

        printf("\nExpanding... %s", current->node_name);

        if (strcmp(current->node_name, goal->node_name) == 0) {
            printf("\nTotal Cost: %d\n", current->cost);
            free(name);
            break;
        }

        //expand neighbors based on lowest h(n) + g(n)
        struct arc *a = current->first;
        while (a != NULL) {
            struct vertex *neighbor = a->destination;
            int new_cost = current->cost + a->distance;

            if (neighbor->processed == 0 && new_cost < neighbor->cost) {
                neighbor->cost = new_cost;
                neighbor->parent = current;

                enqueue_priority(&q, neighbor->node_name,
                                 new_cost + heuristic_challenge1(neighbor));
            }

            a = a->next;
        }

        free(name);
    }

    printf("\nSolution Path:\n");
    print_solution_path(goal);
    printf("\n");
}

void challenge1() {
    //Constructing the challenge 1 graph(only valid and reachable states)
    struct graph_head *challenge1_graph = create_graph();

    insert_vertex(challenge1_graph,"(0,0,1)");
    insert_vertex(challenge1_graph,"(0,1,0)");
    insert_vertex(challenge1_graph,"(0,1,1)");
    insert_vertex(challenge1_graph,"(0,2,0)");
    insert_vertex(challenge1_graph,"(0,2,1)");
    insert_vertex(challenge1_graph,"(0,3,0)");
    insert_vertex(challenge1_graph,"(1,1,0)");
    insert_vertex(challenge1_graph,"(1,1,1)");
    insert_vertex(challenge1_graph,"(2,2,0)");
    insert_vertex(challenge1_graph,"(2,2,1)");
    insert_vertex(challenge1_graph,"(3,0,1)");
    insert_vertex(challenge1_graph,"(3,1,0)");
    insert_vertex(challenge1_graph,"(3,1,1)");
    insert_vertex(challenge1_graph,"(3,2,0)");
    insert_vertex(challenge1_graph,"(3,2,1)");
    insert_vertex(challenge1_graph,"(3,3,0)");

    insert_arc(challenge1_graph,"(0,0,1)","(0,1,0)",1);
    insert_arc(challenge1_graph,"(0,0,1)","(0,2,0)",1);
    insert_arc(challenge1_graph,"(0,0,1)","(1,1,0)",1);

    insert_arc(challenge1_graph,"(0,1,0)","(0,0,1)",1);

    insert_arc(challenge1_graph,"(0,1,1)","(1,1,0)",1);
    insert_arc(challenge1_graph,"(0,1,1)","(0,2,0)",1);
    insert_arc(challenge1_graph,"(0,1,1)","(0,3,0)",1);

    insert_arc(challenge1_graph,"(0,2,0)","(0,1,1)",1);
    insert_arc(challenge1_graph,"(0,2,0)","(0,0,1)",1);

    insert_arc(challenge1_graph,"(0,2,1)","(2,2,0)",1);
    insert_arc(challenge1_graph,"(0,2,1)","(0,3,0)",1);

    insert_arc(challenge1_graph,"(0,3,0)","(0,2,1)",1);
    insert_arc(challenge1_graph,"(0,3,0)","(0,1,1)",1);

    insert_arc(challenge1_graph,"(1,1,0)","(0,1,1)",1);
    insert_arc(challenge1_graph,"(1,1,0)","(0,0,1)",1);

    insert_arc(challenge1_graph,"(1,1,1)","(3,1,0)",1);
    insert_arc(challenge1_graph,"(1,1,1)","(2,2,0)",1);

    insert_arc(challenge1_graph,"(2,2,0)","(0,2,1)",1);
    insert_arc(challenge1_graph,"(2,2,0)","(1,1,1)",1);

    insert_arc(challenge1_graph,"(2,2,1)","(3,2,0)",1);
    insert_arc(challenge1_graph,"(2,2,1)","(3,3,0)",1);

    insert_arc(challenge1_graph,"(3,0,1)","(3,1,0)",1);
    insert_arc(challenge1_graph,"(3,0,1)","(3,2,0)",1);

    insert_arc(challenge1_graph,"(3,1,0)","(1,1,1)",1);
    insert_arc(challenge1_graph,"(3,1,0)","(3,0,1)",1);

    insert_arc(challenge1_graph,"(3,1,1)","(3,2,0)",1);
    insert_arc(challenge1_graph,"(3,1,1)","(3,3,0)",1);

    insert_arc(challenge1_graph,"(3,2,0)","(2,2,1)",1);
    insert_arc(challenge1_graph,"(3,2,0)","(3,1,1)",1);
    insert_arc(challenge1_graph,"(3,2,0)","(3,0,1)",1);

    insert_arc(challenge1_graph,"(3,2,1)","(3,3,0)",1);

    insert_arc(challenge1_graph,"(3,3,0)","(3,2,1)",1);
    insert_arc(challenge1_graph,"(3,3,0)","(3,1,1)",1);
    insert_arc(challenge1_graph,"(3,3,0)","(2,2,1)",1);

    printf("\nChosen Challenge: Challenge 1 (C1)\n");
    printf("\nChallenge 1 Graph:\n");
    print_graph(challenge1_graph);

    reset_processed(challenge1_graph);
    a_star(challenge1_graph, "(3,3,0)", "(0,0,1)");
}



int arc_exists(struct graph_head *graph, char *from, char *to) {
    struct vertex *v = find_vertex(graph, from);
    if (v==NULL) {
        return 0;
    }
    struct arc *a = v->first;
    while (a != NULL) {
        if (strcmp(a->destination->node_name, to) == 0) {
            return 1;
        }
        a = a->next;
    }

    return 0;
}

void load_labyrinth(struct graph_head *graph,char *filename,char *mad_scientist_room,char *exit_room) {
    FILE *inFile = fopen(filename, "r");

    char line[256];
    char room[100], n1[100], n2[100], n3[100], n4[100];
    int c1, c2;

    while (fgets(line, sizeof(line), inFile) != NULL) {

        if (sscanf(line, "mad scientist %49s", mad_scientist_room) == 1) {
            continue;
        }
        if (sscanf(line, "exit %49s", exit_room) == 1) {
            continue;
        }


        int count = sscanf(line, "\n%49s %d %d %49s %49s %49s %49s",
                    room, &c1, &c2, n1, n2, n3, n4);

        struct vertex *v = find_vertex(graph, room);
        if (v == NULL) {
            insert_vertex(graph, room);
            v = find_vertex(graph, room);
        }

        v->coordinate_1 = c1;
        v->coordinate_2 = c2;

        //inserting arcs based on number of neighbors if count =3 , then 1 neighbor if 4, then 2 neighbors etc.

        //assuming the distance between rooms is 1 in the labrynth
        if (count >= 4) {
            if (find_vertex(graph, n1) == NULL) {
                insert_vertex(graph, n1);
            }
            //inserting arcs in both ways so it wont get stuck
            if (!arc_exists(graph, room, n1)) {
                 insert_arc(graph, room, n1, 1);
            }
            if (!arc_exists(graph, n1, room)) {
                insert_arc(graph, n1, room, 1);
            }
        }

        if (count >= 5) {
            if (find_vertex(graph, n2) == NULL) {
                 insert_vertex(graph, n2);
            }
            if (!arc_exists(graph, room, n2)) {
                insert_arc(graph, room, n2, 1);
            }
            if (!arc_exists(graph, n2, room)) {
                insert_arc(graph, n2, room, 1);
            }
        }

        if (count >= 6) {
            if (find_vertex(graph, n3) == NULL) {
                insert_vertex(graph, n3);
            }
            if (!arc_exists(graph, room, n3)) {
                insert_arc(graph, room, n3, 1);
            }
            if (!arc_exists(graph, n3, room)) {
                insert_arc(graph, n3, room, 1);
            }
        }

        if (count >= 7) {
            if (find_vertex(graph, n4) == NULL) {
                insert_vertex(graph, n4);
            }
            if (!arc_exists(graph, room, n4)) {
                insert_arc(graph, room, n4, 1);
            }
            if (!arc_exists(graph, n4, room)) {
                insert_arc(graph, n4, room, 1);
            }
        }
    }

    fclose(inFile);
}

//heuristic for greedy
int heuristic(struct vertex *current, struct vertex *goal) {
    return abs(current->coordinate_1 - goal->coordinate_1) + abs(current->coordinate_2 - goal->coordinate_2);
}

void greedy(struct graph_head *graph, char *start_name, char *goal_name) {
    struct queue q;
    initialize_queue(&q);

    struct vertex *start = find_vertex(graph, start_name);
    struct vertex *goal = find_vertex(graph, goal_name);

    if (start == NULL || goal == NULL) {
        printf("Start or goal node not found!\n");
        return;
    }

    start->parent = NULL;
    enqueue_priority(&q, start->node_name, heuristic(start, goal));

    printf("\nExpansion Order:\n");

    while (!is_empty_queue(&q)) {
        char *name = dequeue(&q);
        struct vertex *current = find_vertex(graph, name);

        if (current->processed == 1) {
            free(name);
            continue;
        }

        current->processed = 1;

        printf("\nExpanding... %s", current->node_name);

        if (strcmp(current->node_name, goal->node_name) == 0) {
            free(name);
            break;
        }

        //expand neighbors based on lowest h(n)
        struct arc *a = current->first;
        while (a != NULL) {
            struct vertex *neighbor = a->destination;

            if (neighbor->processed == 0) {
                if (neighbor->parent == NULL) {
                    neighbor->parent = current;
                }
                enqueue_priority(&q, neighbor->node_name, heuristic(neighbor, goal));
            }
            a = a->next;
        }
        free(name);
    }
}

void challenge2() {
    printf("\nChosen Challenge: Challenge 2 (C2)\n");

    struct graph_head *g = create_graph();
    char mad_scientist[100] = "";
    char exit_room[100] = "";

    load_labyrinth(g, "challenge2.txt", mad_scientist, exit_room);

    print_graph(g);

    printf("\nMad Scientist Room: %s", mad_scientist);
    printf("\nExit Room: %s\n", exit_room);

    reset_processed(g);
    printf("\n\nGreedy Search 1: Start -> Mad Scientist\n");
    greedy(g, "A2", mad_scientist);
    printf("\nSolution Path:\n");
    print_solution_path(find_vertex(g, mad_scientist));

    reset_processed(g);
    printf("\n\nGreedy Search 2: Mad Scientist -> Exit\n");
    greedy(g, mad_scientist, exit_room);
    printf("\nSolution Path:\n");
    print_solution_path(find_vertex(g, exit_room));
}

void BFS(struct graph_head *graph, char *start_name, char *goal_name) {
    struct queue q;
    initialize_queue(&q);

    struct vertex *start = find_vertex(graph, start_name);
    struct vertex *goal = find_vertex(graph, goal_name);

    if (start == NULL || goal == NULL) {
        printf("Start or goal node not found!\n");
        return;
    }

    enqueue(&q, start->node_name);
    start->cost = 0;
    start->processed = 1;
    start->parent = NULL;

    printf("\nExpansion Order:\n");


    while (!is_empty_queue(&q)) {
        char *name = dequeue(&q);
        struct vertex *current = find_vertex(graph, name);

        printf("\nExpanding... %s", current->node_name);

        //expand neighbors by level
        struct arc *a = current->first;
        while (a != NULL) {
            if (a->destination->processed == 0) {
                a->destination->processed = 1;
                a->destination->parent = current;//save parent for solution path
                a->destination->cost = current->cost + a->distance;
                enqueue(&q, a->destination->node_name);
            }
            a = a->next;
        }

        free(name);
    }
    int c = challenge(goal);
    if (c == 1) {
        printf("\nMoving to Challenge 1 (C1)\n");
        challenge1();
    }
    else if (c == 2) {
        printf("\nMoving to Challenge 2 (C2)\n");
        challenge2();
    }
}


void UCS(struct graph_head *graph, char *start_name, char *goal_name) {
    struct queue q;
    initialize_queue(&q);

    struct vertex *start = find_vertex(graph, start_name);
    struct vertex *goal = find_vertex(graph, goal_name);

    if (start == NULL || goal == NULL) {
        printf("Start or goal node not found!\n");
        return;
    }

    start->cost = 0;
    start->parent = NULL;
    enqueue_priority(&q, start->node_name, start->cost);

    printf("\nExpansion Order:\n");


    while (!is_empty_queue(&q)) {
        char *name = dequeue(&q);
        struct vertex *current = find_vertex(graph, name);

        if (current->processed == 1) {
            free(name);
            continue;
        }

        current->processed = 1;

        printf("\nExpanding... %s", current->node_name);


        //expand neighbors based on lowest cost
        struct arc *a = current->first;
        while (a != NULL) {
            struct vertex *neighbor = a->destination;
            int new_cost = current->cost + a->distance;

            if (neighbor->processed == 0 && new_cost < neighbor->cost) {
                neighbor->cost = new_cost;
                neighbor->parent = current;//save parent for solution path
                enqueue_priority(&q, neighbor->node_name, new_cost);
            }

            a = a->next;
        }

        free(name);
    }
    int c = challenge(goal);
    if (c == 1) {
        printf("\nMoving to Challenge 1 (C1)\n");
        challenge1();
    }
    else if (c == 2) {
        printf("\nMoving to Challenge 2 (C2)\n");
        challenge2();
    }
}


// Data structures for chocolate and for making a move
struct Chocolate {
    int rows[5];
    int row;
    int column;
    int poisonous_row;
    int poisonous_column;
};

struct Move {
    int row;
    int column;
};

// for initializing the chocolate
void initialize_chocolate(struct Chocolate *c, int rows, int columns, int poison_row, int poison_column) {
    c->row = rows;
    c->column = columns;
    c->poisonous_row = poison_row;
    c->poisonous_column = poison_column;

    for (int i = 0; i < 5; i++) {
        if (i < rows)
            c->rows[i] = columns;
        else
            c->rows[i] = 0;
    }
}

//for printing the chocolate
void print_chocolate(struct Chocolate c) {
    printf("\nAvailable chocolate pieces:\n");

    for (int i = 0; i < c.row; i++) {
        for (int j = 0; j < c.rows[i]; j++) {
            if (i == c.poisonous_row && j == c.poisonous_column)
                printf("P(%d,%d) ", i + 1, j + 1);
            else
                printf("(%d,%d) ", i + 1, j + 1);
        }
        printf("\n");
    }
}

//for checking legal move
int legal_move(struct Chocolate c, int row, int column) {

    if (row < 0 || row >= c.row) {
        return 0;
    }
    if (column < 0 || column >= c.rows[row]) {
        return 0;
    }

    if (row <= c.poisonous_row && column <= c.poisonous_column) {
        return 0;
    }

    return 1;
}

//for checking if there is any legal move
int has_legal_move(struct Chocolate c) {
    for (int i = 0; i < c.row; i++) {
        for (int j = 0; j < c.rows[i]; j++) {
            if (legal_move(c, i, j))
                return 1;
        }
    }

    return 0;
}


//for choosing a piece (removes all the pieces right and below of the chosen piece)
struct Chocolate choose_piece(struct Chocolate c, int row, int column) {
    for (int i = row; i < c.row; i++) {
        if (c.rows[i] > column)
            c.rows[i] = column;
    }

    return c;
}


int max_value(struct Chocolate c, long long *nodeCount);
int min_value(struct Chocolate c, long long *nodeCount);

int max_value(struct Chocolate c, long long *nodeCount) {

    (*nodeCount)++;//count number of nodes for ai

    if (!has_legal_move(c)) {//if no legal moves lose
        return -1;
    }

    int v = -999999;

    //check entire chocolate, if legal move found eat piece, update v, and switch to min player
    for (int i = 0; i < c.row; i++) {
        for (int j = 0; j < c.rows[i]; j++) {

            if (legal_move(c, i, j)) {

                struct Chocolate next = choose_piece(c, i, j);

                int value = min_value(next, nodeCount);

                if (value > v) {
                    v = value;
                }
            }
        }
    }

    return v;
}

int min_value(struct Chocolate c, long long *nodeCount) {

    (*nodeCount)++; //count number of nodes for ai

    if (!has_legal_move(c)) { //if no legal moves lose
        return 1;
    }

    int v = 999999;

    //check entire chocolate, if legal move found eat piece, update v, and switch to max player
    for (int i = 0; i < c.row; i++) {
        for (int j = 0; j < c.rows[i]; j++) {

            if (legal_move(c, i, j)) {

                struct Chocolate next = choose_piece(c, i, j);

                int value = max_value(next, nodeCount);

                if (value < v) {
                    v = value;
                }
            }
        }
    }

    return v;
}

struct Move mini_max(struct Chocolate c, long long *nodeCount) {

    struct Move best;
    best.row = -1;
    best.column = -1;
    int best_value = -999999;

    *nodeCount = 1;//for counting number of processed nodes for ai(1 since root is also counted)

    //check entire chocolate, if legal move evaluate with minimax to find best move, return best move
    for (int i = 0; i < c.row; i++) {
        for (int j = 0; j < c.rows[i]; j++) {
            if (legal_move(c, i, j)) {

                struct Chocolate next = choose_piece(c, i, j);

                int value = min_value(next, nodeCount);

                if (value > best_value) {
                    best_value = value;
                    best.row = i;
                    best.column = j;
                }
            }
        }
    }
    return best;
}

int ai_move(struct Chocolate *c, int output_check) {
    long long nodeCount = 0;

    //AI uses minimax to go through chocolate, if finds a valid move retur 1, else return -1.
    struct Move move = mini_max(*c, &nodeCount);
    if (move.row == -1) {
        return -1;
    }
    if (output_check) {
        printf("AI chooses row: %d\n", move.row + 1);
        printf("AI chooses column: %d\n", move.column + 1);
        printf("Minimax visited nodes: %lld\n", nodeCount);
    }
    *c = choose_piece(*c, move.row, move.column);
    return 1;
}


void human_vs_human() {

    //initialize chocolate
    struct Chocolate c;
    int rows;
    int columns;
    int poison_row;
    int poison_column;
    int check1 = 0, check2 = 0, check3 = 0, check4 = 0;

    while (check1 != 1) {
        printf("\nEnter number of rows (2 to 5): ");
        scanf("%d", &rows);

        if (rows >= 2 && rows <= 5)
            check1 = 1;
    }
    while (check2 != 1) {
        printf("\nEnter number of columns (2 to 5): ");
        scanf("%d", &columns);

        if (columns >= 2 && columns <= 5)
            check2 = 1;
    }
    while (check3 != 1) {
        printf("\nEnter poisonous square row (1 to %d): ", rows);
        scanf("%d", &poison_row);

        if (poison_row >= 1 && poison_row <= rows)
            check3 = 1;
    }
    while (check4 != 1) {
        printf("\nEnter poisonous square column (1 to %d): ", columns);
        scanf("%d", &poison_column);

        if (poison_column >= 1 && poison_column <= columns)
            check4 = 1;
    }

    initialize_chocolate(&c, rows, columns, poison_row - 1, poison_column - 1);

    int row, column;
    int valid_check;
    int game_check = 0;
    while (game_check!=1) {

        //for player 1
        print_chocolate(c);
        valid_check = 0;
        while (valid_check != 1) {
            printf("Player 1 enter row (1 to %d): ", c.row);
            scanf("%d", &row);

            printf("Player 1 enter column (1 to %d): ", c.column);
            scanf("%d", &column);

            //converting to array index
            row--;
            column--;

            if (row >= 0 && row < c.row && column >= 0 && column < c.rows[row]) {//check if valid move
                c = choose_piece(c, row, column);
                valid_check = 1;

                if (row <= c.poisonous_row && column <= c.poisonous_column) {//if player 1 eats poison
                    printf("Player 1 ate the poisonous piece and loses!\n");
                    printf("Player 2 wins!\n");
                    game_check = 1;
                }
            }
            else {
                printf("Invalid move!\n\n");
            }
        }

        if (game_check == 1) {//ending the game if any player loses
            return;
        }

        //for player 2
        print_chocolate(c);
        valid_check = 0;
        while (valid_check != 1) {
            printf("Player 2 enter row (1 to %d): ", c.row);
            scanf("%d", &row);

            printf("Player 2 enter column (1 to %d): ", c.column);
            scanf("%d", &column);

            //converting to array index
            row--;
            column--;

            if (row >= 0 && row < c.row && column >= 0 && column < c.rows[row]) {//checking if valid move
                c = choose_piece(c, row, column);
                valid_check = 1;

                if (row <= c.poisonous_row && column <= c.poisonous_column) {//If player 2 eats poison
                    printf("Player 2 ate the poisonous piece and loses!\n");
                    printf("Player 1 wins!\n");
                    game_check = 1;
                }
            }
            else {
                printf("Invalid move!\n\n");
            }
        }
    }
}

void human_vs_ai() {

    //initializing chocolate
    struct Chocolate c;
    int rows;
    int columns;
    int poison_row;
    int poison_column;
    int check1 = 0, check2 = 0, check3 = 0, check4 = 0;

    int choice;
    int result;

    while (check1 != 1) {
        printf("Enter number of rows (2 to 5): ");
        scanf("%d", &rows);

        if (rows >= 2 && rows <= 5) {
            check1 = 1;
        }
    }
    while (check2 != 1) {
        printf("Enter number of columns (2 to 5): ");
        scanf("%d", &columns);

        if (columns >= 2 && columns <= 5) {
            check2 = 1;
        }
    }
    while (check3 != 1) {
        printf("Enter poisonous square row (1 to %d): ", rows);
        scanf("%d", &poison_row);

        if (poison_row >= 1 && poison_row <= rows) {
            check3 = 1;
        }
    }
    while (check4 != 1) {
        printf("Enter poisonous square column (1 to %d): ", columns);
        scanf("%d", &poison_column);

        if (poison_column >= 1 && poison_column <= columns) {
            check4 = 1;
        }
    }

    printf("Do you want to start first? 1 = yes, 0 = no: ");
    scanf("%d", &choice);

    initialize_chocolate(&c, rows, columns, poison_row - 1, poison_column - 1);

    int row = 0;
    int column = 0;
    int valid_check;
    int game_check = 0;
    while (game_check != 1) {

        if (choice == 1) { //human first

            //human
            print_chocolate(c);
            valid_check = 0;

            while (valid_check != 1) {
                printf("Player 1 enter row (1 to %d): ", c.row);
                scanf("%d", &row);

                printf("Player 1 enter column (1 to %d): ", c.column);
                scanf("%d", &column);

                //converting to array index
                row--;
                column--;

                if (row >= 0 && row < c.row && column >= 0 && column < c.rows[row]) {//check if valid move
                    c= choose_piece(c, row, column);
                    valid_check = 1;

                    if (row <= c.poisonous_row && column <= c.poisonous_column) {// if human eats poison
                        printf("Human ate the poisonous piece and loses!\n");
                        printf("AI wins!\n");
                        game_check = 1;
                    }
                }
                else {
                    printf("Invalid move. That piece is already eaten or outside the chocolate.\n\n");
                }
            }

            if (game_check == 1) {
                return;
            }

            //ai
            print_chocolate(c);
            result = ai_move(&c, 1);

            if (result == -1) {//if ai eats poison
                printf("AI has no safe move and must eat the poisonous piece.\n");
                printf("AI loses!\n");
                printf("Human wins!\n");
                game_check = 1;
            }
        }

        else { //ai first

            //ai
            print_chocolate(c);
            result = ai_move(&c, 1);

            if (result == -1) {//if ai eats poison
                printf("AI has no safe move and must eat the poisonous piece.\n");
                printf("AI loses!\n");
                printf("Human wins!\n");
                game_check = 1;
            }

            if (game_check == 1) {//if either human or ai eats posion game ends
                return;
            }

            //human
            print_chocolate(c);
            valid_check = 0;

            while (valid_check != 1) {
                printf("Player 1 enter row (1 to %d): ", c.row);
                scanf("%d", &row);

                printf("Player 1 enter column (1 to %d): ", c.column);
                scanf("%d", &column);

                //converting to array index
                row--;
                column--;

                if (row >= 0 && row < c.row && column >= 0 && column < c.rows[row]) {//check if valid move
                    c = choose_piece(c, row, column);
                    valid_check = 1;

                    if (row <= c.poisonous_row && column <= c.poisonous_column) {//player eats poison
                        printf("Human ate the poisonous piece and loses!\n");
                        printf("AI wins!\n");
                        game_check = 1;
                    }
                }
                else {
                    printf("Invalid move. That piece is already eaten or outside the chocolate.\n\n");
                }
            }
        }
    }
}

int lara_vs_ai() {
    //initialize a chocolate with a random size and poison at top left
    struct Chocolate c;
    int rows = 2 + rand() % 4;
    int columns = 2 + rand() % 4;
    initialize_chocolate(&c, rows, columns, 0, 0);


    while (has_legal_move(c)) {

        //lara
        //check entire chocolate, if a legal move exists, randomly select a piece
        int legalRows[50];
        int legalCols[50];
        int count = 0;
        for (int i = 0; i < c.row; i++) {
            for (int j = 0; j < c.rows[i]; j++) {
                if (legal_move(c, i, j)) {
                    legalRows[count] = i;
                    legalCols[count] = j;
                    count++;
                }
            }
        }
        if (count > 0) {
            int choice = rand() % count;
            c = choose_piece(c, legalRows[choice], legalCols[choice]);
        }


        //lara wins
        if (ai_move(&c, 0) == -1) {
            return 1;
        }
    }

    return 0;//ai wins
}

//runs lara vs ai 100 times and then prints out who won each game and win percentages
void lara_100_runs() {
    int laraWins = 0;
    int aiWins = 0;

    for (int i = 0; i < 100; i++) {
        int result = lara_vs_ai();

        if (result == 1) {
            laraWins++;
            printf("Game %d Winner: Lara\n", i + 1);
        }
        else {
            aiWins++;
            printf("Game %d Winner: AI\n", i + 1);
        }
    }

    printf("\nTotal games: 100");
    printf("\nLara wins: %d\n", laraWins);
    printf("\nAI wins: %d\n", aiWins);
    printf("\nLara winning percentage: %.2f%%\n", (laraWins / 100.0) * 100);
    printf("\nAI winning percentage: %.2f%%\n", (aiWins / 100.0) * 100);
}

void poisonous_chocolate_game() {
    int choice;
    int check = 0;

    while (check != 1) {

        printf("\n\nPoisonous Chocolate Bar Game\n");
        printf("1.Human vs Human\n");
        printf("2.Human vs AI\n");
        printf("3.Lara Simulation 100 Games\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            human_vs_human();
        }
        else if (choice == 2) {
            human_vs_ai();
        }
        else if (choice == 3) {
            lara_100_runs();
            return;
        }
        else if (choice == 4) {
            check = 1;
        }
        else {
            printf("Invalid choice! Please try again!\n");
        }
    }
}

int main() {
    srand(time(NULL));

    //Constructing the Survival Map
    struct graph_head *survival_map = create_graph();
    insert_vertex(survival_map,"Start(S)");
    insert_vertex(survival_map,"Safehouse(F)");
    insert_vertex(survival_map,"Challenge 1 (C1)");
    insert_vertex(survival_map,"Challenge 2 (C2)");
    insert_vertex(survival_map,"Exit (E)");

    insert_arc(survival_map,"Start(S)","Safehouse(F)",80);
    insert_arc(survival_map,"Start(S)","Challenge 1 (C1)",99);
    insert_arc(survival_map,"Safehouse(F)","Challenge 2 (C2)",97);
    insert_arc(survival_map,"Challenge 1 (C1)","Exit (E)",211);
    insert_arc(survival_map,"Challenge 2 (C2)","Exit (E)",101);

    printf("\nSurvival Map:\n");
    print_graph(survival_map);


    //Menu
    int choice = 0;
    printf("\nWelcome to Agent Lara's Rescue Mission -2> choose the Algorithm to Apply:");
    printf("\n1)UCS");
    printf("\n2)BFS");
    printf("\nChoice: ");
    scanf("%d",&choice);

    reset_processed(survival_map);
    struct vertex *goal = find_vertex(survival_map, "Exit (E)");

    if (choice == 1) {
        printf("\nChoice: UCS\n");
        UCS(survival_map, "Start(S)", "Exit (E)");
        printf("\nSolution Path:\n");
        print_solution_path(goal);
        poisonous_chocolate_game();
    }
    else if (choice == 2) {
        printf("\nChoice: BFS\n");
        BFS(survival_map, "Start(S)", "Exit (E)");
        printf("\nSolution Path:\n");
        print_solution_path(goal);
    }

    //Questions
    printf("\n---------------------------------------------------------------------------------");
    printf("\nQuestions(Task 1):");
    printf("\nQuestion 1: Which path passes through the safe house (F)?");
    printf("\nQ1 Answer: Start(S),Safe House(F),Challenge 2 (C2), Exit(E) "
           "which is the solution path taken by UCS\n");

    printf("\nQuestion 2: Which algorithm (BFS or UCS) reaches the goal with fewer expansions?");
    printf("\nQ2 Answer: They both reach their goal with 5 expansions\n");

    printf("\nQuestion 3: Does passing through the safe house always lead to an optimal solution? (Explain.)");
    printf("\nQ3 Answer:\nNo. The optimal solution depends on the total cost not on whether it"
    "passes through the safe house or not. In this case, passing through the safe house is the optimal"
    "solution but if the path costs were different, \nit may no longer be the optimal solution so:"
    "\noptimal solution in this case -> yes, always the optimal solution -> no \n");

    printf("\nQuestion 4: Compare the solution paths returned by BFS and UCS.");
    printf("\nQ4 Answer:");
    printf("\nBFS Path: Start(S), Challenge 1 (C1), Exit(E), Total Cost: 310");
    printf("\nUCS Path: Start(S), Safe House(F), Challenge 2(C2), Exit(E), Total Cost: 278");
    printf("\nSo UCS provides the optimal solution.\n");
    printf("\n---------------------------------------------------------------------------------\n");

    printf("\nQuestions(Challenge 1):");
    printf("\nQuestion 1: What makes a state invalid in this problem?");
    printf("\nQ1 Answer: In either side of the bank, if a guard is present,"
    "then the prisoners must never outnumber the guards. If this condition is not satisfied,"
    "then it is an invalid state");
    printf("\nQuestion 2: Why must the heuristic be admissible?");
    printf("\nQ2 Answer: Heuristic must be admissible to ensure that A* is optimal. So in this"
"case to find the most optimal sequence of boat moves, heuristic must be admissble.");
    printf("\nQuestion 3: What happens if your heuristic overestimates?");
    printf("\nQ3 Answer: If the heuristic overestimates, A* will not be optimal anymore."
"It may ignore shorter paths and instead choose longer paths which results in an inefficient and long"
"sequence of states.");

    printf("\n---------------------------------------------------------------------------------\n");
    printf("\nQuestions(Challenge 2):");
    printf("\nQuestion 1: Is Greedy Best-First Search guaranteed to find the optimal?");
    printf("\nQ1 Answer:");
    printf("\nNo. Greedy Best-First Search only expands based on heuristic(h(n)), not the distance."
           "Therefore, it always picks the one with the lowest h(n) even though its cost may not be optimal.");
    printf("\nQuestion 2: How does the heuristic affect node expansion?");
    printf("\nQ2 Answer:");
    printf("\nNode expansion depends only on the heuristic for greedy-best-first. Whichever node that"
           "has the lowest heuristic will be expanded next.");
    printf("\nQuestion 3: What happens if nodes are expanded more than once? ");
    printf("\nQ3 Answer:");
    printf("\nIf a node is expanded more than once, it may cause repeated nodes(inefficient) and"
           " infinite loops.");

    printf("\n---------------------------------------------------------------------------------\n");

}