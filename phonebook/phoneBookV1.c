#include <stdio.h>
#include <string.h>


#define CAPACITY 100
#define BUFFER_SIZE 100

void add();

void find();

void delete();

void status();


char *names[BUFFER_SIZE];
char *numbers[BUFFER_SIZE];
int n = 0;


int main() {
    char command[BUFFER_SIZE];
    while (1) {
        printf("$   ");
        scanf("%s", command);

        if ((strcmp(command, "add")) == 0) {
            add();
        } else if ((strcmp(command, "find")) == 0) {
            find();
        } else if ((strcmp(command, "delete")) == 0) {
            delete();
        } else if ((strcmp(command, "status")) == 0) {
            status();
        } else if ((strcmp(command, "exits")) == 0)
            break;
    }
    return 0;
}

void add(){
    char addNameTmp[BUFFER_SIZE], addNumberTmp[BUFFER_SIZE];
    scanf("%s", addNameTmp);
    scanf("%s", addNumberTmp);

    names[n] = strdup(addNameTmp);
    numbers[n] = strdup(addNumberTmp);
    n++;

    printf("%s was added successfully.\n", addNameTmp);
}

void find(){
    char findNameTmp[BUFFER_SIZE];
    scanf("%s", findNameTmp);

    int i;

    for (int i = 0; i < n; ++i) {
        if ((strcmp(findNameTmp, names[i])) == 0) {
            printf("%s\n", numbers[i]);
            return;
        }
    }
    printf("nononooononononononon\n");
}

void status(){
    int i;
    for (int i = 0; i < n; ++i) {
        printf("%s : %s\n", names[i], numbers[i]);
    }
    printf("Total : %d\n", n);
}

void delete(){
    char deleteTmp[BUFFER_SIZE];
    scanf("%s", deleteTmp);
    int i ;
    for (int i = 0; i < n; ++i) {
        if ((strcmp(deleteTmp, names[i])) == 0) {
            names[i] = names[n - 1];
            numbers[i] = numbers[n - 1];
            n--;
            printf("delete ok\n");
            return;
        }
    }
    printf("no person deleted\n");
}