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
        printf("%d", dt.CoSo);
    }
    if (dt.CoSo<0) {
        printf("%d", dt.CoSo);
    }
    if (dt.SoMu<2) {
        if(dt.SoMu>0) {
            printf("x");
        }else {
        }
    }else {
        printf("x^%d", dt.SoMu);
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
    NODEPTR current = pHead;
    for (;current != NULL;current=current->pNext) {
        if(current->data.CoSo!=0) {
            Output(current->data);
            if (current->pNext != NULL) {
                if(current->pNext->data.CoSo>0) {
                    printf("+");
                }
            }
        }
    }
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

void InsertToTail(NODEPTR &pHead, DonThuc input) {
    if(pHead == NULL) {
       InsertToHead(pHead, input);
        return;
    }
    NODEPTR current = pHead;
    while(current->pNext != NULL) {
          current = current->pNext;
    }
    current->pNext = createNode(input);

}
void InsertToPositionK(NODEPTR &pHead, DonThuc input, int k) {
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
    if(k==0) {
        RemoveHead(pHead);
        return;
    }
    int i = 1;
    while (current->pNext->pNext!= NULL&&i<k) {
      current = current->pNext;
      i++;
    }
    if(i<k-1){
      return;
    }
    current->pNext = current->pNext->pNext;
}

void Sort(NODEPTR &pHead) {
    for(NODEPTR i = pHead;i->pNext != NULL;i = i->pNext){
        for(NODEPTR j = i->pNext;j!= NULL;j = j->pNext){
            if(i->data.SoMu > j->data.SoMu){
                DonThuc temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}
void DaoHam(NODEPTR &pHead) {
    Sort(pHead);
    while(pHead->data.SoMu == 0){
        RemoveHead(pHead);
    }
    NODEPTR current = pHead;
    while(current != NULL){
        current->data.CoSo  *= current->data.SoMu;
        current->data.SoMu--;
        current = current->pNext;
    }
}
void ChuanHoaDaThuc(NODEPTR pHead) {
    printf("ChuanHoaDaThuc\n");
    Print(pHead);
    Sort(pHead);
    NODEPTR current = pHead;

}
void CongHaiDay(NODEPTR &pHead1, NODEPTR pHead2) {
    NODEPTR current = pHead1;
    while(current->pNext != NULL){
        current = current->pNext;
    }
    current->pNext = pHead2;
    Sort(pHead1);
    current = pHead1;
    while(current->pNext->pNext != NULL){
        if(current->pNext!=NULL){
            if(current->pNext->data.SoMu==current->data.SoMu){
                current->data.CoSo+=current->pNext->data.CoSo;
                current->pNext = current->pNext->pNext;
            }
            //Output(current->data);
        }else{
            break;
        }
        current = current->pNext;
    }
}
void InsertInt(NODEPTR &pHead, int CoSo,int SoMu) {
    DonThuc temp;
    temp.CoSo = CoSo;
    temp.SoMu = SoMu;
    InsertToTail(pHead, temp);
}


int main() {
    NODEPTR phead1 = NULL;
    InsertInt(phead1, 7, 4);
    InsertInt(phead1, 3, 3);
    InsertInt(phead1, -2, 2);
    InsertInt(phead1, 1, 1);
    InsertInt(phead1, -6, 0);
    NODEPTR phead2 = NULL;
    InsertInt(phead2, 4, 5);
    InsertInt(phead2, -6, 3);
    InsertInt(phead2, 4 , 2);
    InsertInt(phead2, 7, 1);
    InsertInt(phead2, -8, 0);
    //Print(phead1);
    //RemoveAtPosition(phead1,2);
    CongHaiDay(phead1, phead2);
    Print(phead1);
    //printf("\n");
    //Print(phead2);
    return 0;
}