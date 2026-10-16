#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* List */
list new_list(int h) {
    list l = malloc(sizeof(struct cell));
    l->head = h;
    l->tail = NULL;
    return l;
}

/* Stack */
Stack new_Stack(void) {
    Stack p = malloc(sizeof(struct SStack));
    p->index = 0;
    return p;
}

void push(Stack p, int val) {
    p->tab[p->index++] = val;
}


int top(Stack p) {
    return p->tab[p->index - 1];
}

void pop(Stack p) {
    p->index--;
}

void print(Stack p) {
    for (int i = 0; i < p->index; i++) {
        printf("%d ", p->tab[i]);
    }
    printf("\n");
}

/* Queue */
queue new_q(int f) {
    queue q = malloc(sizeof(struct Queue));
    q->first = f;
    q->tail = NULL;
    return q;
}

queue append(int f, queue q) {
    queue nouveau = new_q(f);

    queue courant = q;
    while (courant->tail != NULL) {
        courant = courant->tail;
    }
    courant->tail = nouveau;
    return q;
}

int peek(queue q) {
    return q->first;
}

int dequeue(queue* q) {
    queue a_supprimer = *q;
    int val = a_supprimer->first;
    *q = (*q)->tail;
    free(a_supprimer);

    return val;
}

/* Hash table */
int hash(const char* key, int size) {
    int sum = 0;
    for (int k = 0; k<strlen(key); k++) {
        sum += (char)key[k];
    }
    return sum % size;
}