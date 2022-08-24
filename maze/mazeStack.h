//
// Created by XENSF101 on 2022-08-24.
//

#ifndef C_MAZESTACK_H
#define C_MAZESTACK_H
#include <stdbool.h>
#include "pos.h"

typedef Position Item; // Code Recycle possible.

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
Item pop(Stack s);
Item peek(Stack s);
void push(Stack s,Item i);
bool is_full(Stack s);

#endif //C_MAZESTACK_H
