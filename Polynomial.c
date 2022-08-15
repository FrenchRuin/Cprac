#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct term{
    int coef; // 계수         4x^2   4-계수 2-차수(지수)
    int expo; // 차수
    struct term *next;
};

typedef struct term Term;

typedef struct polynomial{
    char name;
    Term *first;
    int size;
} Polynomial;

#define MAX_POLYS 100
#define BUFFER_LENGTH 100

Polynomial  *polys[MAX_POLYS]; // 다항식에 대한 포인터들의 배열
int n = 0;  // 저장된 다항식의 개수

/*****************메소드 정의***************/
Term *create_term_instance();
Polynomial *create_polynomial_instance(char name);
void add_term(int c, int e, Polynomial *poly);
void process_command();
int eval_poly(Polynomial *poly, int x);   // 다항식의 값을 계산하는 함수
int eval_term(Term *term,int x);  // 하나의 항의 값을 계산하는 함수
void print_poly(Polynomial *p);
void print_term(Term *pTerm);
void handle_calc(char name, char *x_str);
void handle_definition(char *expression);
Polynomial *create_by_parse_polynomial(char name, char *body);
Polynomial *create_by_add_two_polynomials(char name,char f, char g);
Term *parse_term(char *expr, int begin, int end, Polynomial *p_poly);
void insert_polynomial(Polynomial *ptr_poly);
void destroy_polynomial(Polynomial *ptr_poly);
/*******************************************/

int main()
{

    process_command();
    return 0;
}


Term *create_term_instance(){
    Term *t = (Term *) malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;  // 동적으로 메모리 생성후 초기값을 지정
    return t;
};

Polynomial *create_polynomial_instance(char name) // 다항식을 생성
{
    Polynomial *ptr_poly = (Polynomial *) malloc(sizeof(Polynomial));
    ptr_poly->name = name;
    ptr_poly->size = 0;
    ptr_poly->first = NULL;    //동적 메모리 생성후 초기값 지정
}

void add_term(int c, int e, Polynomial *poly) // c = 계수 , e = 차수(지수)
{
    if (c == 0) {
        return; // 계수가 0 일 경우에는 바로 return
    }
    Term  *p = poly->first, *q = NULL; // 연결리스트에서 뒷부분을 알아야 하기 때문에 p 의 뒤를 쫒는 q 포인터배열을 선언
    while (p != NULL && p->expo > e) {
        q = p;
        p = p->next; // 차수 내림차순
    }
    if (p != NULL && p->expo == e) { // 동일한 차수의 항이 존재하는 경우...
        p->coef +=c;
        if (p->coef == 0) { // 더했더니 계수가 0이 되는 경우...?????
            if (q == NULL) {
                poly->first = p->next;
            }else{    // q의 다음노드를 삭제한다. 단, q가 NULL이면 첫번째 노드를 삭제
                q->next = p->next;
            }
            poly->size --;
            free(p); // 불필요한 노드 p를 삭제
        }
        return;
    }

    Term  *term = create_term_instance(); // 위의 로직을 타고 내려왔다는것은 p와 q의 사이에 넣어야하는 것
    term->coef = c;
    term->expo = e;

    if (q == NULL) {
        term->next = poly->first;   // 맨 첫번째 항으로 들어감
        poly->first = term;
    }else{
        term->next = p;             // 사이에 들어감
        q->next = term;
    }
    poly->size ++;                  // 항 증가
}

int eval_poly(Polynomial *poly, int x)
{
    int result = 0;
    Term *t = poly->first;
    while (t != NULL) {
        result += eval_term(t, x); // 각각의 항의 값을 계산해서 더한다.
        t = t->next;
    }
    return result;
}

int eval_term(Term *term,int x)
{
    int result = term->coef; // 계수
    for (int i = 0; i < term->expo; i++) {
        result *=x;
    }
    return result;    //
}

void print_poly(Polynomial *p)
{
    printf("%c=", p->name);
    Term *t = p->first;
    while (t != NULL) {
        print_term(t);
        printf("+");
        t = t->next;
    }
}

void print_term(Term *pTerm){   // 완벽한 함수 아님 개선필요..
    printf("%dx^%d", pTerm->coef, pTerm->expo);
}

void process_command()
{
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *arg1, *arg2;

    while (1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0) {
            continue;
        }
        strcpy(copied, command_line); // 입력 라인을 복사한다. 꼭 필요한것은 아니다.
        command = strtok(command_line, " ");
        if (strcmp(command, "print") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_print(arg1[0]);
        } else if (strcmp(command, "calc") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            arg2 = strtok(NULL, " ");
            if (arg2 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_calc(arg1[0], arg2);
        } else if (strcmp(command, "exit") == 0) {
            break;
        }else{
            handle_definition(copied);
        }
    }
}

void handle_calc(char name, char *x_str)
{
    //직접 코딩해야함..
}

void handle_definition(char *expression)
{
    erase_blanks(expression);  // 모든 공백 문자열을 제거한다.

    char *f_name = strtok(expression, "=");
    if (f_name == NULL || strlen(f_name) != 1) {
        printf("Unsupported command.");
        return;
    }

    char *exp_body = strtok(NULL, "=");
    if (exp_body == NULL || strlen(exp_body) <= 0) {
        printf("invalid expression format. --");
        return;
    }

    if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
        char *former = strtok(exp_body, "+");
        if (former == NULL || strlen(former) != 1) {
            printf("Invalid expression format.");
            return;
        }

        char *later = strtok(NULL, "+");
        if (later == NULL || strlen(later) != 1) {
            printf("Invalid expression format.");
            return;
        }
        Polynomial *pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);

        if (pol == NULL) {
            printf("Invalid expression format.");
            return;
        }
        insert_polynomial(pol);
    }else{
        Polynomial *pol = create_by_parse_polynomial(f_name[0],exp_body);
        if (pol == NULL) {
            printf("Invalid expression format.");
            return;
        }
        insert_polynomial(pol);
    }
}

void erase_blanks(char *expression)
{
    // 직접 코딩해야함...  (주의) -- 맨 마지막은  /0 로 마무리 해야함
}


Polynomial *create_by_parse_polynomial(char name, char *body){
    Polynomial *ptr_poly = create_polynomial_instance(name);
    int i = 0, begin_term = 0;
    while (i < strlen(body)) {
        if (body[i] == '+' || body[i] == '-') {
            i++;
        }
        while (i < strlen(body) && body[i] != '+' && body[i] != '-') {
            i++;
        }
        int result = parse_and_add_term(body, begin_term, i, ptr_poly);
        if (result == 0) {
            destroy_polynomial(ptr_poly);
            return NULL;
        }
        begin_term = i;
    }
    return ptr_poly;
}

Term *parse_term(char *expr, int begin, int end, Polynomial *p_poly){
    int i = begin;
    int sign_coef = 1, coef = 0, expo = 1;
                                            //  계수의 양수 음수 측정
    if (expr[i] == '+') {
        i++;
    } else if (expr[i] == '-') {
        sign_coef = -1;
        i++;
    }
    while (i < end && expr[i] >= '0' && expr[i] <= '9') {
        // digit들을 읽어서 계수의 절대값(coef)를 계산한다.
        // 계수가 1 혹은 -1 인경우 digit이 없을 수도 있다.
        coef = coef * 10 + (int) (expr[i] - '0');
        i++;
    }

    if (coef == 0) { // coef가 0인 경우 계수는 0이 아니라 1 혹은 -1 이다.
        coef = sign_coef;
    }else{
        coef *= sign_coef;
    }

    if (i >= end) { // 더이상 항을 구성하는 문자가 없다면 상수항이라는 의미.
        add_term(coef, 0, p_poly);
        return 1;
    }

    if (expr[i] != 'x') {
        return 0;
    }
    i++;

    if (i >= end) {
        add_term(coef, 1, p_poly);
        return 1;
    }

    if (expr[i] != '^') {
        return 0;
    }
    i++;

    expo = 0;
    while (i < end && expr[i] >= '0' && expr[i] <= '9') {
        expo = expo * 10 + (int) (expr[i] - '0');
        i++;
    }
    add_term(coef, expo, p_poly);
    return 1;
}

void insert_polynomial(Polynomial *ptr_poly)
{
    for (int i = 0; i < n; i++) {
        if (polys[i]->name == ptr_poly->name) {
            destroy_polynomial(polys[i]); // 다항식을 덮어쓸 경우에는 기존의 다항식 객체를 free 시켜주어야 한다.
            polys[i] = ptr_poly;
            return;
        }
    }
    polys[n++] = ptr_poly;
}

void destroy_polynomial(Polynomial *ptr_poly)
{
    if (ptr_poly == NULL) {
        return;
    }
    Term *t = ptr_poly->first, *tmp;
    while (t != NULL) {
        tmp = t;
        t = t->next;
        free(tmp);
    }
    free(ptr_poly);
}

Polynomial *create_by_add_two_polynomials(char name, char f, char g)
{
    //내가 직접 코딩.. (새로운 empty 다항식을 만든후, 두 다항식의 모든 항들을 add 해주면 된다.)
}