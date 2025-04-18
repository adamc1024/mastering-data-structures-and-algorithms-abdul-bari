#ifndef LINKEDLISTCLANG_H
#define LINKEDLISTCLANG_H

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Structure definition
typedef struct NodeSll
{
    int data;
    struct NodeSll *next;
} NodeSll;

NodeSll *newNodeSll();

void nodeSllInit(NodeSll *node, int data, NodeSll *next);

typedef struct NodeDll
{
    struct NodeDll *prev;
    int data;
    struct NodeDll *next;
} NodeDll;

NodeDll *newNodeDll();

void nodeDllInit(NodeDll *node, NodeDll *prev, int data, NodeDll *next);

typedef struct LL
{
    uint8_t typeLL;
    void *head;
    void *tail;
} LL;

extern const uint8_t SINGLY_LINKED;
extern const uint8_t DOUBLY_LINKED;

//typeLL: 1 == singly linked list, 2 = doubly linked list
void llInit(LL *ll, uint8_t typeLL);

void *nextNodeByType(void *p, uint8_t typeLL);

void assignNextNodeByType(void *p, void *q, uint8_t typeLL);

int getDataByType(void *p, uint8_t typeLL);

void *newNodeByType(uint8_t typeLL);

void llAppend(LL *ll, int data);

LL newLLFromArray(uint8_t typeLL, int *arr, int n);

void llDisplay(LL *ll);

void llPrintHeadAndTail(LL *ll);

void llDestruct(LL *ll);

int llLength(LL *ll);

int llSum(LL *ll);

float llAverage(LL *ll);

int llMin(LL *ll);

int llMax(LL *ll);

void llInsert(LL *ll, int pos, int data);

int llPop(LL *ll, int pos);

bool llIsSorted(LL *ll, bool ascending);

void llSort(LL *ll, bool ascending);

void llDeleteDuplicates(LL *ll);

void llReverse(LL *ll);

bool llIsLooped(LL *ll);

void llConcatenate(LL *ll_1, LL *ll_2);

void llMerge(LL *ll_1, LL *ll_2, bool ascending);

#endif // LINKEDLISTCLANG_H