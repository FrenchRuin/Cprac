

#include <stdio.h>
#include <stdlib.h>
#include "mazeStack.h"

#define INIT_CAPACITY 100

struct stack_type{
    pos *contents;
    int top;
    int size;
};

static void terminate(const char *message){
    printf("%s\n", message);
    exit(1);
}

void reallocate(Stack s);

void push(Stack s, pos i)
{
    if (is_full(s)) {
        reallocate(s);
    }
    s->top++;
    s->contents[s->top + 1] = i;
}
bool is_full(Stack s)
{
    return s->top == INIT_CAPACITY-1;
}

pos pop(Stack s)
{
    if (is_empty(s)) {
        terminate("Error in pop : stack is empty");
    }
    s->top--;
    return s->contents[s->top + 1];
}

pos peek(Stack s)
{
    if (is_empty(s)) {
        terminate("Error in peek : stack is empty");
    }
    return s->contents[s->top];
}

Stack create()
{
    Stack s = (Stack) malloc(sizeof(struct stack_type));
    if (s == NULL) {
        terminate("Error in create : stack could not be created.");
    }
    s->contents = (pos *) malloc(INIT_CAPACITY * sizeof(pos));
//    if (s->contents == NULL) {
//        free(s);
//        terminate("Error in create : stack could not be created.");
//    }
    s->top = -1;
    s->size = INIT_CAPACITY;
    return s;
}

void destroy(Stack s)
{
    free(s->contents);
    free(s);
}

void make_empty(Stack s)
{
    s->top = -1;
}

bool is_empty(Stack s)
{
    return s->top == -1;
}

void reallocate(Stack s)
{
    pos *tmp = (pos *) malloc(2 * s->size * sizeof(pos));
    if (tmp == NULL) {
        terminate("Error in create : Stack could not be created.");
    }
    for (int i = 0; i < s->size; i++) {
        tmp[i] = s->contents[i];
    }
    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}