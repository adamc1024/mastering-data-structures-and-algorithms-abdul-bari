#include <linkedListClang.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const uint8_t SINGLY_LINKED = 0x01;
const uint8_t DOUBLY_LINKED = 0x02;

NodeSll *newNodeSll()
{
    NodeSll *t = (NodeSll *) malloc(sizeof(NodeSll));
    return t;
}

void nodeSllInit(NodeSll *node, int data, NodeSll *next)
{
    node->data = data;
    node->next = next;
}

NodeDll *newNodeDll()
{
    NodeDll *t = (NodeDll *) malloc(sizeof(NodeDll));
    return t;
}

void nodeDllInit(NodeDll *node, NodeDll *prev, int data, NodeDll *next)
{
    node->prev = prev;
    node->data = data;
    node->next = next;
}

void llInit(LL *ll, uint8_t typeLL)
{
    ll->typeLL = 1;
    if (typeLL == DOUBLY_LINKED)
    {
        ll->typeLL = DOUBLY_LINKED;
    }
    ll->head = NULL;
    ll->tail = NULL;
}

void *nextNodeByType(void *p, uint8_t typeLL)
{
    if (typeLL == SINGLY_LINKED)
    {
        return ((NodeSll *)p)->next;
    }
    else if (typeLL == DOUBLY_LINKED)
    {
        return ((NodeDll *)p)->next;
    }
    return p;
}

void assignNextNodeByType(void *p, void *q, uint8_t typeLL)
{
    if (typeLL == SINGLY_LINKED)
    {
        ((NodeSll *)p)->next = ((NodeSll *)q);
    }
    else if (typeLL == DOUBLY_LINKED)
    {
        ((NodeDll *)p)->next = ((NodeDll *)q);
    }
}

int getDataByType(void *p, uint8_t typeLL)
{
    if (typeLL == SINGLY_LINKED)
    {
        return ((NodeSll *)p)->data;
    }
    else if (typeLL == DOUBLY_LINKED)
    {
        return ((NodeDll *)p)->data;
    }
    return -1;
}

void *newNodeByType(uint8_t typeLL)
{
    if (typeLL == SINGLY_LINKED)
    {
        return newNodeSll();
    }
    else if (typeLL == DOUBLY_LINKED)
    {
        return newNodeDll();
    }
    return NULL;
}

void llAppend(LL *ll, int data)
{
    void *t;
    t = newNodeByType(ll->typeLL);
    if (ll->typeLL == SINGLY_LINKED)
    {
        nodeSllInit(t, data, NULL);
    }
    else if (ll->typeLL == DOUBLY_LINKED)
    {
        nodeDllInit(t, NULL, data, NULL);
    }
    if (ll->head == NULL && ll->tail == NULL)
    {
        ll->head = ll->tail = t;
    }
    else {
        assignNextNodeByType(ll->tail, t, ll->typeLL);
        if (ll->typeLL == DOUBLY_LINKED)
        {
            ((NodeDll *)t)->prev = ll->tail;
        }
        ll->tail = t;
    }
}

LL newLLFromArray(uint8_t typeLL, int *arr, int n)
{
    LL ll;
    llInit(&ll, typeLL);
    if (typeLL == SINGLY_LINKED)
    {
        printf("Singly Linked List\n");
    }
    else if (typeLL == DOUBLY_LINKED)
    {
        printf("Doubly Linked List\n");
    }
    for (int i = 0; i < n; i++)
    {
        llAppend(&ll, arr[i]);
    }
    return ll;
}

void llDisplay(LL *ll)
{
    void *p = ll->head;
    printf("[");
    bool comma = false;
    while (p)
    {
        if (comma)
        {
            printf(", ");
        }
        printf("%d", getDataByType(p, ll->typeLL));
        p = nextNodeByType(p, ll->typeLL);
        comma = true;
    }
    printf("]\n");
}

void llPrintHeadAndTail(LL *ll)
{
    printf("Head: %d\n", getDataByType(ll->head, ll->typeLL));
    printf("Tail: %d\n", getDataByType(ll->tail, ll->typeLL));
}


void llDestruct(LL *ll)
{
    void *p = ll->head;
    void *q;
    while (p != NULL)
    {
        q = p;
        p = nextNodeByType(p, ll->typeLL);
        free(q);
    }
    printf("LL Deallocated\n");
}

int llLength(LL *ll)
{
    int result = 0;
    void *p = ll->head;
    while (p)
    {
        result++;
        p = nextNodeByType(p, ll->typeLL);
    }
    return result;
}

int llSum(LL *ll)
{
    int result = 0;
    void *p = ll->head;
    while (p)
    {
        result += getDataByType(p, ll->typeLL);
        p = nextNodeByType(p, ll->typeLL);
    }
    return result;
}

float llAverage(LL *ll)
{
    return (float)llSum(ll)/llLength(ll);
}

int llMin(LL *ll)
{
    void *p = ll->head;
    int result = getDataByType(p, ll->typeLL);
    int pData;
    while (p)
    {
        pData = getDataByType(p, ll->typeLL);
        if (pData < result)
        {
            result = pData;
        }
        p = nextNodeByType(p, ll->typeLL);
    }
    return result;
}

int llMax(LL *ll) {
    void *p = ll->head;
    int result = getDataByType(p, ll->typeLL);
    int pData;
    while (p)
    {
        pData = getDataByType(p, ll->typeLL);
        if (pData > result)
        {
            result = pData;
        }
        p = nextNodeByType(p, ll->typeLL);
    }
    return result;
}

void llInsert(LL *ll, int pos, int data)
{
    void *p = ll->head;
    void *q;
    int n = llLength(ll);
    if (pos == n)
    {
        llAppend(ll, data);
    }
    else if (pos >= 0 && pos < n)
    {
        void *t = newNodeByType(ll->typeLL);
        if (pos == 0)
        {
            if (ll->typeLL == SINGLY_LINKED)
            {
                nodeSllInit((NodeSll *)t, data, (NodeSll *)p);
            }
            else if (ll->typeLL == DOUBLY_LINKED)
            {
                nodeDllInit((NodeDll *)t, NULL, data, (NodeDll *)p);
            }
            ll->head = t;
        }
        else
        {
            for (int i = 0; i < pos; i++)
            {
                q = p;
                p = nextNodeByType(p, ll->typeLL);
            }
            if (ll->typeLL == SINGLY_LINKED)
            {
                nodeSllInit((NodeSll *)t, data, (NodeSll *)p);
                ((NodeSll *)q)->next = t;
            }
            else if (ll->typeLL == DOUBLY_LINKED)
            {
                nodeDllInit((NodeDll *)t, (NodeDll *)q, data, (NodeDll *)p);
                ((NodeDll *)q)->next = t;
                ((NodeDll *)p)->prev = t;
            }
        }
    }
}

int llPop(LL *ll, int pos)
{
    int data, n;
    data = -1;
    n = llLength(ll);
    if (n && pos >= 0 && pos < n)
    {
        void *p = ll->head;
        if (pos == 0)
        {
            data = getDataByType(p, ll->typeLL);
            ll->head = nextNodeByType(p, ll->typeLL);
            if (ll->typeLL == DOUBLY_LINKED)
            {
                ((NodeDll *)ll->head)->prev = NULL;
            }
            free(p);
        }
        else {
            void *q;
            for (int i = 0; i < pos; i++)
            {
                q = p;
                p = nextNodeByType(p, ll->typeLL);
            }
            data = getDataByType(p, ll->typeLL);
            if (ll->typeLL == SINGLY_LINKED)
            {
                ((NodeSll *)q)->next = ((NodeSll *)p)->next;
            }
            else if (ll->typeLL == DOUBLY_LINKED)
            {
                ((NodeDll *)q)->next = ((NodeDll *)p)->next;
                if (((NodeDll *)q)->next)
                {
                    ((NodeDll *)q)->next->prev = q;
                }
            }
            free(p);
            if (pos == n - 1)
            {
                ll->tail = q;
            }
        }
    }
    return data;
}

bool llIsSorted(LL *ll, bool ascending)
{
    void *p = ll->head;
    int data;
    while (nextNodeByType(p, ll->typeLL))
    {
        data = getDataByType(p, ll->typeLL);
        p = nextNodeByType(p, ll->typeLL);
        if (ascending && data > getDataByType(p, ll->typeLL))
        {
            break;
        }
        if (!ascending && data < getDataByType(p, ll->typeLL))
        {
            break;
        }
    }
    if ((ll->typeLL == 1 && ((NodeSll *)p)->next == NULL) ||
    (ll->typeLL == 2 && ((NodeDll *)p)->next == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void llSort(LL *ll, bool ascending)
{
    void *p, *q, *r;
    while (!llIsSorted(ll, ascending))
    {
        p = NULL;
        q = ll->head;
        r = nextNodeByType(q, ll->typeLL);
        while (r)
        {
            if (ascending && getDataByType(q, ll->typeLL) > getDataByType(r, ll->typeLL) ||
            !ascending && getDataByType(q, ll->typeLL) < getDataByType(r, ll->typeLL))
            {
                assignNextNodeByType(q, nextNodeByType(r, ll->typeLL), ll->typeLL);
                assignNextNodeByType(r, q, ll->typeLL);
                q = r;
                r = nextNodeByType(r, ll->typeLL);
                if (p)
                {
                    assignNextNodeByType(p, q, ll->typeLL);
                }
                else
                {
                    ll->head = q;
                }
                if (ll->typeLL == DOUBLY_LINKED)
                {
                    ((NodeDll *)q)->prev = p;
                    ((NodeDll *)r)->prev = q;
                    if (((NodeDll *)r)->next)
                    {
                        ((NodeDll *)r)->next->prev = r;
                    }
                }
            }
            p = q;
            q = nextNodeByType(q, ll->typeLL);
            r = nextNodeByType(r, ll->typeLL);
        }
    }
    ll->tail = q;
}

void llDeleteDuplicates(LL *ll) {
    int max = llMax(ll);
    int min = llMin(ll);
    int n = max - min + 1;
    int H[n];
    for (int i = 0; i < n; i++)
    {
        H[i] = 0;
    }
    void *p, *q;
    p = ll->head;
    while (p)
    {
        int pData = getDataByType(p, ll->typeLL);
        if (H[pData - min] == 0)
        {
            H[pData - min]++;
            q = p;
            p = nextNodeByType(p, ll->typeLL);
        }
        else if (H[pData - min] > 0)
        { 
            assignNextNodeByType(q, nextNodeByType(p, ll->typeLL), ll->typeLL);
            if (nextNodeByType(q, ll->typeLL) == NULL)
            {
                ll->tail = q;
            }
            else if (ll->typeLL == 2 && nextNodeByType(q, ll->typeLL))
            {
                ((NodeDll *)q)->next->prev = q;
            }
            printf("Deleted duplicate: %d\n", pData);
            free(p);
            p = nextNodeByType(q, ll->typeLL);
        }
    }
}

void llReverse(LL *ll)
{
    void *p, *q;
    if (ll->typeLL == SINGLY_LINKED)
    {
        printf("hi\n");
        void *r;
        p = ll->head;
        q = r = NULL;
        while (p)
        {
            r = q;
            q = p;
            p = nextNodeByType(p, ll->typeLL);
            assignNextNodeByType(q, r, ll->typeLL);
        }
        ll->tail = ll->head;
        ll->head = q;
    }
    else if (ll->typeLL == DOUBLY_LINKED)
    {
        p = ll->tail;
        ll->tail = ll->head;
        ll->head = p;
        while (p)
        {
            q = nextNodeByType(p, ll->typeLL);
            assignNextNodeByType(p, ((NodeDll *)p)->prev, ll->typeLL);
            ((NodeDll *)p)->prev = q;
            p = nextNodeByType(p, ll->typeLL);
        }

    }
}

bool llIsLooped(LL *ll)
{
    if (ll->typeLL == DOUBLY_LINKED)
    {
        return ((((NodeDll *)ll->head)->prev == ll->tail) && 
        (((NodeDll *)ll->tail)->next == ll->head));
    }
    return nextNodeByType(ll->tail, ll->typeLL) != NULL;

    // void *p;
    // p = ll->head;
    // do {
    //     p = nextNodeByType(p, ll->typeLL);
    //     if (p == ll->head) {
    //         return true;
    //     }
    // } while (p);
    // return false;

    // void *p, *q;
    // p = q = ll->head;
    // do {
    //     p = nextNodeByType(p, ll->typeLL);
    //     q = nextNodeByType(q, ll->typeLL);
    //     q = q ? nextNodeByType(q, ll->typeLL) : q;
    // } while (p && q && p != q);
    // if (p == q) {
    //     return true;
    // } 
    // else {
    //     return false;
    // }
}

void llConcatenate(LL *ll_1, LL *ll_2)
{
    if (ll_1->typeLL == ll_2->typeLL)
    {
        assignNextNodeByType(ll_1->tail, ll_2->head, ll_1->typeLL);
        if (ll_1->typeLL == 2)
        {
            ((NodeDll *)ll_2->head)->prev = ll_1->tail;
        }
        ll_1->tail = ll_2->tail;
        ll_2->head = ll_2->tail = NULL;
    }
}

void llMerge(LL *ll_1, LL *ll_2, bool ascending)
{
    llConcatenate(ll_1, ll_2);
    if (ll_1->typeLL == ll_2->typeLL)
    {
        llSort(ll_1, ascending);
    }
}
