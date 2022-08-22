#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char *data;
    struct node next;
    struct node prev;
};

typedef struct node Node;

Node *head;
Node *tail;
int size = 0;


void add_after(Node *pre , char *item)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (pre == NULL && head == NULL) {
        head = new_node;
        tail = new_node;
    } else if (pre == NULL) {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    } else if (pre == tail) {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }else{
        new_node->prev = pre;
        new_node->next = pre->next;
        pre->next->prev = new_node;
        pre->next = new_node;
    }
    size ++;
}

void add_ordered_list(char *item)
{
    Node *p = tail;
    while (p != NULL && strcmp(item, p->data) < 0) {
        p = p->prev;
    }
    add_after(p, item);
}