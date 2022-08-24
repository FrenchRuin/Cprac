//
// Created by XENSF101 on 2022-08-24.
//

#ifndef C_MAZESTACK_H
#define C_MAZESTACK_H
#include <stdbool.h>
#include "pos.h"

typedef Position pos; // Code Recycle possible.

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
pos pop(Stack s);
pos peek(Stack s);
void push(Stack s, pos i);
bool is_full(Stack s);

#endif //C_MAZESTACK_H
