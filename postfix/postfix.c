/*
 * 모든 연산자는 양의 정수
 * 연산자 사이에는 하나의 공백이 존재
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stacks/stackADT.h"

static char OPERATORS[] = "+_*/";

Stack operand_stack;
int eval_op(char op);
void handle_exception(const char *err_msg);

int is_operator(char ch)
{
    for (int i = 0; i < strlen(OPERATORS); i++) {
        if (OPERATORS[i] == ch) {
            return i;
        }
    }
    return -1;
}

int eval(char *expr)
{
    operand_stack = create();                       // stack create
    char *token = strtok(expr, " ");   // 공백기준 나눔
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {   // 0~9 사이 일경우
            int value = atoi(token);           // atoi int 변환
            push(operand_stack, value);              // stack push
        } else if (is_operator(token[0]) > -1) { // 연산자 존재시
            int result = eval_op(token[0]);      // eval_op 함수 호출
            push(operand_stack, result);              // stack push
        }else{
            handle_exception("Syntax Error : invalid character encountered.");  // Error control
        }
        token = strtok(NULL, " ");       // return while
    }

    if (is_empty(operand_stack)) {
        handle_exception("Syntax Error: stack empty in eval_op");   // empty
    }
    int answer = pop(operand_stack);     // stack pop
    if (is_empty(operand_stack)) {       // emtpy case return answer
        return answer;
    }else{
        handle_exception("Syntax Error: stack should be empty");    // Error control
        return -1;
    }
}

int eval_op(char op)
{
    if (is_empty(operand_stack)) {
        handle_exception("Syntax Error : Stack empty in eval_op."); // Empty case
    }
    int rhs = pop(operand_stack);   // right number
    if (is_empty(operand_stack)) {
        handle_exception("Syntax Error : Stack empty in eval_op.");
    }
    int lhs = pop(operand_stack); // left number
    int result = 0;
    switch (op) {   // calc
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
    }
    return result;   // result return
}

void handle_exception(const char *err_msg){   // Error Control
    printf("%s\n", err_msg);
    exit(1);
}

