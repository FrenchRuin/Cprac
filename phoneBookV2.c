#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0;

void add();
void find();
void status();
void delete();
void load();
void save();
int search(char *name);

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
        } else if ((strcmp(command, "read")) == 0) {
            load();
        } else if ((strcmp(command, "save")) == 0) {
            save();
        } else if ((strcmp(command, "exits")) == 0)
            break;
    }
    return 0;
}

void load() {
    char fileName[BUFFER_SIZE];
    char namesTmp[BUFFER_SIZE];
    char numbersTmp[BUFFER_SIZE];

    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    while ((fscanf(fp, "%s", namesTmp)) != EOF) {
        fscanf(fp, "%s", numbersTmp);
        names[n] = strdup(namesTmp);
        numbers[n] = strdup(numbersTmp);
        n++;
    }
    fclose(fp);
}

void save()
{
    int i;
    char fileName[BUFFER_SIZE];
    char tmp[BUFFER_SIZE];

    scanf("%s", tmp);
    scanf("%s",fileName);

    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }

    fclose(fp);
}

void add()
{
    char namesTmp[BUFFER_SIZE], numbersTmp[BUFFER_SIZE];
    scanf("%s", namesTmp);
    scanf("%s", numbersTmp);

    int i = n-1;
    while (i >= 0 && strcmp(names[i], namesTmp) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(namesTmp);
    numbers[i + 1] = strdup(numbersTmp);

    n++;
    printf("%s was added successfully.\n", namesTmp);
}

void delete()
{
    char namesTmp[BUFFER_SIZE];
    scanf("%s", namesTmp);

    int index = search(namesTmp);
    if (index == -1) {
        printf("No person named '%s' exists.\n", namesTmp);
        return;
    }
    int j = index;
    for (; j < n-1 ; j++) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }
    n--;
    printf("'%s' was deleted successfully.  \n", namesTmp);
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

int search(char *name)
{
    int i;
    for (int i = 0; i < n; ++i) {
        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void status()
{
    int i ;
    for (int i = 0; i < n; ++i) {
        printf("%s %s\n", names[i], numbers[i]);
    }
    printf("Total %d persons \n", n);
}