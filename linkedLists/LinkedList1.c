#include <stdio.h>
#include <stdlib.h>

struct node {
    char *data;
    struct node *next;
};

typedef struct node Node;
Node *head = NULL;

void add_first1(char *item);
void add_first2(Node **ptr_head, char *item);
Node *add_first3(Node *head, char *item);


int main()
{
    head = (Node *) malloc(sizeof(Node));        // head 선언
    head->data = "Tuesday";
    head->next = NULL;                                // h.data - TuesDay | h.next  - null //

    Node *q = (Node *) malloc(sizeof(Node));
    q->data = "Thursday";                             // q.data - Thursday | q.next - null //
    q->next = NULL;
    head->next = q;                                   // h.data - Tuesday | h.next - q //
                                                      // q.data - Thursday | q.next - Null//

    q = (Node *) malloc(sizeof(Node));           // q 재할당
    q->data = "Monday";                               // q.data - Monday | q.next - head //
    q->next = head;                                   // h.data - Tuesday | h.data - q //
    head = q;                                         // q.data - Thursday | q.data - Null //

    Node *p = head;                                   // p =  head의 주소
    while (p != NULL) {
        printf("%s\n", p->data);               //
        p = p->next;
    }

    /*
     * LinkedList 주소값(Node) 로 이어 붙이기
     * */
}
/*******************************************/
/*
 * 연결 리스트 맨앞에 새로운 노드 삽입 하기
 * */

void add_first1(char *item)  // 단순히 head 를 교체
{
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}

void add_first2(Node **ptr_head, char *item)
{
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = *ptr_head;
    *ptr_head = head;
    /*
     * head가 전역변수가 아닌 경우
     * 포인터 변수 head 의 주소값을 매개변수로 받고
     * 바뀐 head의 주소를 포인터를 이용하여 변수 head에 쓴다.
     *
     * 구현 방법 >>> add_first(&head, item_to_store);
     * */
}

Node *add_first3(Node *head, char *item){
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    return tmp;

    /*
     * head가 전역변수가 아닌경우에는
     * return 하여 값을 매긴다.
     *
     * 구현 방법 >>>
     * head = add_first(head, item_to_store);
     * */
}

