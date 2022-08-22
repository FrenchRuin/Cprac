#include "stack.h" // 가정가정
#include <stdio.h>
#define MAX_CAPACITY 100

struct node{                 // node를 활용하여 stack 구현
    char *data;
    struct node *next;
};
typedef struct node Node;

Node *top = NULL;

void push_node(char *item)
{
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = item;
    p->next = top;
    top = p;
}

char *pop()
{
    if (is_empty()) {
        return NULL;
    }
    char *result = top->data;
    top = top->next;
    return result;
}

char *peek()
{
    if(is_empty()){
        return NULL;
    }
    return top->data;
}

int is_empty()
{
    return top == NULL;
}
/*******************************/


char stack[MAX_CAPACITY];   // 스택에 저장되는 데이터 타입이 char 가정
int top = -1;

void push(char ch)
{
    if (is_full()) {
        return;
    }
    top++;
    stack[top] = ch;
}

char pop(){
    char tmp = stack[top];
    top--;
    return tmp;
}


