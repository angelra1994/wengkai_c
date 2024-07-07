#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// typedef struct _node {
//     int value;
//     struct _node *next;
// } Node;

typedef struct _lsit {
    Node* head;
    // Node* tail;
} List;



void add(List* pList, int number);

int main(int argc, char const *argv[])
{
    List list;
    list.head = NULL;
    // list.head = list.tail = NULL;
    int number;
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);
        }
    } while (number != -1);

    print(&list);

    scanf("%d", &number);
    Node *p;
    int isFound = 0;
    for ( p=list.head; p; p = p->next) {
        if (p->value == number) {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound) {
        printf("没找到\n");
    }

    Node *q;
    for (q=NULL, p=list.head; p; q=p, p = p->next) {
        if (p->value == number) {
            if (q) {
                // 代码中出现可能左值为null的情况就是边界条件。Any pointer at the left of -> nust be checked
                q->next = p->next;
            } else {
                list.head = p->next;
            }
            free(p);
            break;
        }
    }

    return 0;
}

void add(List* pList, int number)
{ 
    // add to linked_list
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;

    // find the last
    Node *last = pList->head;
    if (last) {
        while (last->next)
        {
            last = last->next;
        }
        // attach
        last->next = p;
    } else { // list 是 空的场景
        pList->head = p;
    }
}

void print(List *pList)
{
    Node* p;
    for ( p=pList->head; p; p = p->next) {
        printf("%d\t", p->value);
    }
    printf("\n");
}
