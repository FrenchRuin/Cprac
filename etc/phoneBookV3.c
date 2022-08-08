#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3
#define BUFFER_SIZE 50

char **names;
char **numbers;

int capacity = INIT_CAPACITY ;
int n = 0;

char delim[] = " ";

//void init_directory();
//
//void process_command();
//
//int read_line(char str[], int limit);
//void load(char * fileName);
//void add(char *name, char *numbers);
//void delete(char *name);
//void save(char *fileName);
//int search(char *name);
//void find();
//void status();
//void reallocate();


int main() {
    init_directory();
    process_command();

    return 0;
}


void init_directory() {
    names = (char **) malloc(INIT_CAPACITY *sizeof(char *));
    numbers = (char **) malloc(INIT_CAPACITY*sizeof(char *));
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < limit - 1) {
            str[i++] = ch;
        }
    }

    str[i] = '\0';

    return i;
}

void process_command() {
    char command_line[BUFFER_SIZE];
    char *command, *arg1, *arg2;

    while (1) {
        printf("$ ");

        if (read_line(command_line, BUFFER_SIZE) <= 0)       //명령줄을 통째로 읽는다.
            continue;

        command = strtok(command_line, delim);
        if (command == NULL)
            continue;

        if (strcmp(command, "read") == 0) {

            arg1 = strtok(NULL, delim);
            if (arg1 == NULL) {
                printf("File name required\n");
                continue;
            }

            load(arg1);
        } else if (strcmp(command, "add") == 0) {
            arg1 = strtok(NULL, delim);
            arg2 = strtok(NULL, delim);

            if (arg1 == NULL || arg2 == NULL) {
                printf("Invalid Arguments\n");
                continue;
            }
            add(arg1, arg2);

            printf("%s was added successfully\n", arg1);
        } else if (strcmp(command, "find") == 0) {
            arg1 = strtok(NULL, delim);
            if (arg1 == NULL) {
                printf("Invalid Arguments\n");
                continue;
            }
            find(arg1);
        } else if (strcmp(command, "status") == 0) {
            status();
        } else if (strcmp(command, "delete") == 0) {
            arg1 = strtok(NULL, delim);
            if (arg1 == NULL) {
                printf("Invalid Arguments\n");
                continue;
            }
            delete(arg1);
        } else if (strcmp(command,"save")==0) {
            arg1 = strtok(NULL, delim);
            arg2 = strtok(NULL, delim);

            if (arg1 == NULL || strcmp("as", arg1) != 0 || arg2 == NULL) {
                printf("Invalid command format\n");
                continue;
            }
            save(arg2);

        } else if (strcmp(command, "exit") == 0) {
            break;
        }

    }
}

void load(char * fileName)
{
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open Failed\n");
        return;
    }

    while ((fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        add(buf1, buf2);
    }
    fclose(fp);
}

void add(char *name, char *number)
{
    if (n >= capacity) {
        reallocate();
    }

    int i = n-1;
    while (i >= 0 && strcmp(names[i], name) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(name);
    numbers[i + 1] = strdup(number);
    n++;
}

void delete(char *name)
{
    int i = search(name);
    if (i == -1) {
        printf("No person named '%s' exists.\n", name);
        return;
    }
    int j = i;
    for (; j < n - 1; ++j) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }
    n--;
    printf("'%s' was deleted successfully\n",name);
}

void save(char *fileName)
{
    int i;
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Open Failed\n");
        return;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}

void reallocate()
{
    int i ;

    capacity *= 2;
    char **tmp1 = (char **) malloc(capacity * sizeof(char *));
    char **tmp2 = (char **) malloc(capacity * sizeof(char *));

    for (int i = 0; i < n; ++i) {
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }

    free(names);
    free(numbers);

    names = tmp1;
    numbers = tmp2;
}

int search(char *name)
{
    int i;
    for (; i < n; ++i) {
        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void find()
{
    char namesTmp[BUFFER_SIZE];
    scanf("%s", namesTmp);
    int index = search(namesTmp);
    if (index == -1) {
        printf("No person named '%s' exists.  \n", namesTmp);
    } else
        printf("%s\n", numbers[index]);
}

void status()
{
    int i ;
    for (int i = 0; i < n; ++i) {
        printf("%s %s\n", names[i], numbers[i]);
    }
    printf("Total %d persons \n", n);
}

