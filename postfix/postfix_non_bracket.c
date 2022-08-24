
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stacks/stackADT.h"


static char OPERATORS[] = "+-*/";
static int PRECEDENCE[] = {1, 1, 2, 2};  // 우선 순위

Stack operator_stack; // stack 가정  // char

int is_operator(char ch); // operator division
int precedence(char op); // order
char *convert(char *infix); // infix >> postfix
void handle_exception(const char *err_msg); // Error controller
char *process_op(char op, char *pos); //

char *convert(char *infix)
{
    operator_stack = create(); // stack create

    char *postfix = (char *) malloc(strlen(infix) + 1); // infix  + 1
    char *pos = postfix;

    char *token = strtok(infix, " ");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            sprintf(pos, "%s", token); // operand push
            pos += (strlen(infix) + 1);
        } else if (is_operator(token[0]) > -1) { // operator push
            pos = process_op(token[0], pos);
        }else{
            handle_exception("Syntax Error : invalid character encountered."); // error control
        }
        token = strtok(NULL, " ");
    }
    while (!is_empty(operator_stack)) {  //while not empty operator_stack
        char op = (char) pop(operator_stack); //
        sprintf(pos, "%c", op);
        pos += 2;
    }
    *pos = "\0"; // last push
    return postfix;
}

int precedence(char op)
{
    return PRECEDENCE[is_operator(op)];
}

int is_operator(char ch)
{
    for (int i = 0; i < strlen(OPERATORS); i++) {
        if (OPERATORS[i] == ch) {
            return i;
        }
    }
    return -1;
}

void handle_exception(const char *err_msg){
    printf("%s\n", err_msg);
    exit(1);
}

char *process_op(char op, char *pos)
{
    if (is_empty(operator_stack)) {   // if operator_stack is empty
        push(operator_stack, op); // then push operator push on operator_stack
    }else{                                            // if operator_stack is not empty
        char top_op = peek(operator_stack);
        if (precedence(op) > precedence(top_op)) { // if operator_stack top stack is lower than parameter op
            push(operator_stack, op);           // then push parameter op push on operator_stack
        }else{
            while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op)) { // while operator stack not empty ...
                pop(operator_stack);               // pop
                sprintf(pos, "%c", top_op);  // top_op append on pos
                pos += 2;     // blank space
                if (!is_empty(operator_stack)) {           // doing 'while' statement, operator_stack is not empty top_op is peek.
                    top_op = (char) peek(operator_stack);
                }
                push(operator_stack, op); // op push on operator_stack.
            }
        }
    }
    return pos;  // then
}