#include <stdio.h>
#include <stdlib.h>

typedef struct DonThuc {
    int CoSo;
    int SoMu;
}DonThuc;
typedef struct Node {
    DonThuc data;
    struct Node *pNext;
}NODE;
typedef NODE* NODEPTR;

void Output(DonThuc dt) {
    if (dt.CoSo>0) {
        printf("%dx^%d", dt.CoSo, dt.SoMu);
    }
    if (dt.CoSo<0) {
        printf("(%d)x^%d", dt.CoSo, dt.SoMu);
    }

}

NODEPTR createNode(DonThuc input) {
    NODEPTR newNode = new NODE;
    newNode->data = input;
    newNode->pNext = NULL;
    return newNode;
}
void InsertToHead(NODEPTR &pHead, DonThuc input) {
    NODEPTR newNode = createNode(input);
    newNode->pNext = pHead;
    pHead = newNode;
}
void Print(NODEPTR pHead) {
    for (NODEPTR current = pHead;
        current != NULL;
        current=current->pNext) {
        Output(current->data);
        if (current->pNext != NULL) {
            printf("+");
        }
    }
}

int main() {
    NODEPTR phead = NULL;
    for (int i = 1; i < 7; ++i) {
        DonThuc dt;
        dt.CoSo= i%2==0?i*-1:i;
        dt.SoMu = i;
        InsertToHead(phead, dt);
    }
    Print(phead);
    return 0;
}