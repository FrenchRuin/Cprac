#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAPACITY 100
#define BUFFER_LENGTH 100

typedef struct {
    char *name;
    char *number;
    char *email;
    char *group
} Person;

Person ** directory;       // V4 와는 다르게 포인터 배열로 선언
int capacity;
int n;

void init(); // 초기화
void load(char *fileName);
int read_line(FILE *fp,char str[],int n);
void add(char *name,char *number, char *email, char*group);
void reallocate();
void delete(char *name);
void release_person(Person *p);
int compose_name(char str[], int limit);


int main(){
    char command_line[BUFFER_LENGTH];
    char *command, *arg;
    char name_str[BUFFER_LENGTH];
    init();

    while (1) {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0) {
            continue;
        }

        command = strtok(command_line, " ");
        if (strcmp(command, "read") == 0) {
            arg = strtok(NULL, " ");
            if (arg == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            load(arg);

        } else if (strcmp(command, "add") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Name required.\n");
                continue;
            }
            handle_add(name_str);
        } else if (strcmp(command, "find") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Name required.\n");
                continue;
            }
            find(name_str);
        } else if (strcmp(command, "save") == 0) {
            arg = strtok(NULL, " ");
            if (strcmp(arg, "as") != 0) {
                printf("Invalid arguments.\n");
                continue;
            }
            arg = strtok(NULL, " ");
            if (arg == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            save(arg);
        } else if (strcmp(command, "status") == 0) {
            status();
        } else if (strcmp(command, "delete") == 0) {
            if (compose_name(name_str, BUFFER_LENGTH) <= 0) {
                printf("Invalid arguments.\n");
                continue;
            }
            delete(name_str);
        } else if (strcmp(command, "exit") == 0) {
            break;
        }
    }
    return 0;
}


void init(){
    directory = (Person **) malloc(INIT_CAPACITY * sizeof(Person *));
    capacity = INIT_CAPACITY;
    n = 0;
}


void load(char *fileName){
    char buffer[BUFFER_LENGTH];
    char *name, *number,*email,*group;
    char *token;

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open Failed.\n");
        return;
    }

    while (1) {
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0) {
            break;
        }
        name = strtok(buffer, "#");
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0)
            number = NULL;
        else
            number = strdup(token);
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0)
            email = NULL;
        else
            email = strdup(token);
        token = strtok(NULL, "#");
        if (strcmp(token, " ") == 0)
            group = NULL;
        else
            group = strdup(token);
        add(strdup(name), number, email, group);
    }
    fclose(fp);
}

int read_line(FILE *fp,char str[],int n){
    int ch,i = 0;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

void add(char *name,char *number, char *email, char*group)
{
    if (n > capacity)
        reallocate();

    int i = n-1;
    while (i >= 0 && strcmp(directory[i]->name, name) > 0) {
        directory[i + 1] = directory[i];
        i--;
    }

    directory[i + 1] = (Person *)malloc(sizeof(Person));

    directory[i + 1] ->name = name;
    directory[i + 1] ->number = number;
    directory[i + 1] ->email = email;
    directory[i + 1] ->group = group;

    n++;
}

void reallocate()
{
    capacity *= 2;

    Person *tmp = (Person **) malloc(capacity * sizeof(Person *));
    for (int i = 0; i < n; ++i)
        tmp[i] = *directory[i];

    free(directory);
    directory = tmp;
}

void delete(char *name)
{
    int i = search(name);
    if (i == -1) {
        printf("No person named '%s' exists.\n", name);
        return;
    }

    Person *p = directory[i];
    for (int j = i; j < n - 1; ++j) {
        directory[j] = directory[j + 1];
    }
    n--;
    release_person(p);
    printf("'%s' was deleted successfully.\n", name);
}

void release_person(Person *p) {
    free(p->name);
    if(p->number != NULL) free(p->number);
    if(p->email != NULL) free(p->email);
    if(p->group != NULL) free(p->group);
    free(p);
}

int compose_name(char str[], int limit) {
    char *ptr;
    int length = 0;

    ptr = strtok(NULL, " ");
    if (ptr == NULL) {
        return 0;
    }

    strcpy(str, ptr);
    length += strlen(ptr);

    while ((ptr = strtok(NULL, " ")) != NULL) {
        if (length + strlen(ptr) + 1 < limit) {
            str[length++] = ' ';
            str[length] = '\0';
            strcat(str, ptr);
            length += strlen(ptr);
        }
    }
    return length;
}