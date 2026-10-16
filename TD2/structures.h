#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stddef.h>

/*================================ Array ================================*/
struct Sarray{
    int array[100];
};
typedef struct SArray* Array;

/*================================ List ================================*/
struct cell {
    int head;
    struct cell* tail;
};
typedef struct cell* list;

list new_list(int h);

/*================================ Stack ================================*/
struct SStack {
    int tab[100];
    int index;
};
typedef struct SStack* Stack;

Stack new_Stack(void);
void push(Stack p, int val);
int top(Stack p);
void pop(Stack p);
void print(Stack p);

/*================================ Queue ================================*/
struct Queue {
    int first;
    struct Queue* tail;
};
typedef struct Queue* queue;

queue new_q(int f);
queue append(int f, queue q);
int peek(queue q);
int dequeue(queue* q);

/*============================== Hash table ==============================*/
int hash(const char* key, int size);

#endif /* STRUCTURES_H */