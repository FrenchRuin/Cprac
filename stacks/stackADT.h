//
// Created by XENSF101 on 2022-08-23.
//

#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item; // Code Recycle possible.

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
Item pop(Stack s);
Item peek(Stack s);
void push(Stack s,Item i);
bool is_full(Stack s);
#endif //STACKADT_H
