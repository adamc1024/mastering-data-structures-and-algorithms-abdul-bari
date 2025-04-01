#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure definition
typedef struct nodeSll {
    int data;
    struct nodeSll *next;
} nodeSll;

nodeSll *newNodeSll();

void nodeSllInit(nodeSll *node, int data, nodeSll *next);

typedef struct sll {
    nodeSll *head;
    nodeSll *tail;
} sll;

void sllInit(sll *sll);

void sllAppend(sll *sll, int data);

sll newSLLFromArray(int *arr, int n);

void sllDisplay(sll sll);

void sllDestruct(sll *sll);

int sllLength(sll sll);

int sllSum(sll sll);

float sllAverage(sll sll);

int sllMin(sll sll);

int sllMax(sll sll);

void sllInsert(sll *sll, int pos, int data);

int sllPop(sll *sll, int pos);

bool sllIsSorted(sll sll, bool ascending);

void sllSort(sll *sll, bool ascending);

#endif // LINKEDLIST_H