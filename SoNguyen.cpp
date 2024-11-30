#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pNext;
}NODE;
typedef NODE* NODEPTR;

NODEPTR createNode(int input) {
    NODEPTR newNode = new NODE;
    newNode->data = input;
    newNode->pNext = NULL;
    return newNode;
}
void InsertToHead(NODEPTR &pHead, int input) {
    NODEPTR newNode = createNode(input);
    newNode->pNext = pHead;
    pHead = newNode;
}
NODEPTR getNode(NODEPTR &pHead,int k) {
     NODEPTR current = pHead;
     int i = 0;
     while (current != NULL&&i<=k) {
           current = current->pNext;
           i++;
     }
     if(i<k){
       return NULL;
     }
     return current;
}

void InsertToTail(NODEPTR &pHead, int input) {
     if(pHead == NULL) {
           InsertToHead(pHead, input);
     }
    NODEPTR current = pHead;
    while(current->pNext != NULL) {
          current = current->pNext;
    }
    current->pNext = createNode(input);

}

void Print(NODEPTR pHead) {
    for (NODEPTR current = pHead;
        current != NULL;
        current=current->pNext) {
            printf("%d ", current->data);
        }
}
void InsertToPositionK(NODEPTR &pHead, int input, int k) {
    NODEPTR current = pHead;
    int i = 0;
    while (current ->pNext!= NULL&&i<=k) {
      current = current->pNext;
    }
    if(i<k){
        InsertToTail(pHead, input);
        return;
    }
    NODEPTR newNode = createNode(input);
    newNode->pNext = current->pNext;
    current->pNext = newNode;
}
void RemoveHead(NODEPTR &pHead) {
    if (pHead->pNext == NULL||pHead==NULL) {
        pHead = NULL;
    }
    NODEPTR temp = pHead;
    pHead = pHead->pNext;
    delete temp;
}
void RemoveTail(NODEPTR &pHead) {
    if (pHead->pNext == NULL||pHead==NULL) {
        pHead = NULL;
    }
    NODEPTR current = pHead;
    while (current->pNext->pNext != NULL) {
        current = current->pNext;
    }
    NODEPTR temp = current->pNext;
    current->pNext = NULL;
    delete temp;
}
void RemoveAtPosition(NODEPTR &pHead, int k) {
    NODEPTR current = pHead;
    int i = 0;
    while (current ->pNext->pNext!= NULL&&i<k) {
      current = current->pNext;
    }
    if(i<k-1){
      return;
    }
    current->pNext = current->pNext->pNext;
}

void Sort(NODEPTR &pHead) {
    for(NODEPTR i = pHead;i->pNext != NULL;i = i->pNext){
        for(NODEPTR j = i->pNext;j!= NULL;j = j->pNext){
            if(i->data > j->data){
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

int main() {
    NODEPTR phead = NULL;

    return 0;
}