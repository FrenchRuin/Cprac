#include <stdio.h>
#include <string.h>
#include "stack.h" // 문자(char)들을 저장하는 스택이 stack.c 파일에 구현되어 있다고 가정한다.

#define MAX_LENGTH 100

char OPEN[] = "([{";
char CLOSE[] = ")]}";

int is_balanced(char *expr);

int is_open(char ch);

int is_close(char ch);

int main()
{
    char expr[MAX_LENGTH];
    scanf("%s", expr); // 괄호를 포함한 수식을 작성 하여 입력
    if (is_balanced(expr)) {
        printf("%s: balanced.\n", expr);
    } else {
        printf("%s: unbalanced.\n", expr);
    }
}

int is_balanced(char *expr)
{
    int balanced = 1;
    int index = 0;
    while (balanced && index < strlen(expr)) {
        char ch = expr[index];     // 입력한 수식을 한글자 씩 순회
        if (is_open(ch) > -1) {    // 여는 괄호가 있다면
            push(ch);
        } else if (is_close(ch) > -1) {   // 닫는 괄호가 있다면
            if (is_empty()) {    //근데 비어 있다면? break;
                balanced = 0;
                break;
            }
            char top_ch = pop();
            if (is_open(top_ch) != is_close(ch)) {
                balanced = 0;
            }
        }
        index ++;
    }
    return (balanced == 1 && is_empty() == 1);
}

int is_close(char ch)
{
    for (int i = 0; i < strlen(CLOSE); i++) {
        if (CLOSE[i] == ch) {
            return i;               // 해당 괄호의 index 번호를 return
        }
    }
    return -1;   // 해당 괄호가 없다면 -1 return
}

int is_open(char ch)
{
    for (int i = 0; i < strlen(OPEN); i++) {
        if (OPEN[i] == ch) {
            return i;                          // 해당 괄호의 index 번호를 return
        }
    }
    return -1;            // 해당 괄호가 없다면 -1 return
}