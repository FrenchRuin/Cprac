#include <stdio.h>
#include <stdlib.h>

struct node {
    char *data;
    struct node *next;
};

typedef struct node Node;
Node *head = NULL;

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
}