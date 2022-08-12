#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node *next;
};

typedef struct node Node;
Node *head = NULL;


//메소드//
void add_first(char *item);

int add_after(Node *prev, char *item);

Node *remove_first();

Node *remove_after(Node *prev);

Node *find(char *word);

Node *get_node(int index);

int add(int index,char *item);

Node *delete_index(int index);

Node *delete_item(char *item);

void add_to_ordered_list(char *item);
// //////

int main() {

}


/* 어떤 노드 뒤에 새로운 노드 삽입하기 ( insert After )*/
int add_after(Node *prev, char *item) {
    if (prev == NULL) {
        return 0;
    }

    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = prev->next;
    prev->next = tmp;

    return 1;
}

/* 첫번째 노드를 삭제하고 그 노드의 주소를 리턴 ( free 함수 사용을 위해서 ) */
Node *remove_first() {
    if (head == NULL) {
        return NULL;
    } else {
        Node *tmp = head;
        head = head->next;
        return tmp;
    }
}

/* 해당 노드를 삭제하기 위해서는 그전의 노드를 알아야 한다 ( 주소값을 가지고 있기 때문에 )
 * return 은 삭제한 노드 ( tmp ) 에 담아서 리턴한다.
 *
 * */
Node *remove_after(Node *prev) {
    Node *tmp = prev->next;
    if (tmp == NULL) {
        return NULL;
    } else {
        prev->next = tmp->next;
        return tmp;
    }
}
/* 연결리스트 순회 (traverse) // 노드의 처음부터 돌면서,
 * word와 일치하는 데이터를 가진 node의 주소를 반환 */
Node *find(char *word){
    Node *p = head;
    while (p != NULL) {
        if(strcmp(p->data,word) == 0){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/* 연결리스트의 index번째의 노드의 주소를 반환하는 메소드*/
Node *get_node(int index)
{
    if (index < 0) {
        return NULL;
    }
    Node *p = head;
    for (int i = 0; i < index && p!=NULL; ++i) {
        p = p->next;
    }
    return p;
}
/* add 함수를 통해서 첫번째에 추가하거나 사이에 추가하는 함수를 필터링*/
int add(int index,char *item)
{
    if (index < 0) {
        return NULL;
    }
    if (index == 0) {
        add_first(item);
        return 1;
    }

    Node *prev = get_node(index - 1);
    if (prev != NULL) {
        add_after(prev, item);
        return 1;
    }
    return 0;
}

/* 단순히 head를 추가하고자 하는 것으로 바꿔주는 메소드
 * 추가하고자하는 노드를 맨첫번째로 넣는것
 * */
void add_first(char *item)
{
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}
/* index번째 노드를 제거하기 위한 메소드*/
Node *delete_index(int index)
{
    if (index < 0) {
        return NULL;
    }
    if (index == 0) {
        return remove_first();
    }
    Node *prev = get_node(index - 1);
    if (prev == NULL) {
        return NULL;
    } else{
        return remove_after(prev);
    }
}

/* q를 head로 설정후, while문을 타고 돌면서 p는 q의 뒤를 쫒아다닌다.
 * 그다음 p가 Null 이면 Null return
 * q 가 Null 이면 remove_first
 * 그게 아니면 remove_after(q)*/
Node *delete_item(char *item)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL && strcmp(p->data, item) != 0) {
        q=p;
        p = p->next;
    }
    if (p == NULL) {
        return NULL;
    }
    if (q == NULL) {
        return remove_first();
    } else {
        return remove_after(q);
    }
}

/* add를 할때 정렬하면서 add하려는 함수*/
void add_to_ordered_list(char *item)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL && strcmp(p->next, item) <= 0) {
        q = p;
        p = p->next;
    }
    if (q == NULL) {
        add_first(item);
    }else{
        add_after(q, item);
    }
}