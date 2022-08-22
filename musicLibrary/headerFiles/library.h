#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

typedef struct song Song;
typedef struct artist Artist;
typedef struct snode SNode;

struct song{
    int index;
    char *title;
    Artist *artist;
    char *path;
};

struct snode{
    Song *song;
    struct snode *prev, *next;
};

struct artist{
    char *name;
    Artist *next;
    SNode *head,*tail;
};

void initialize();

void search_song_by_name(char *name);

void search_song_by_name_title(char *name, char *title);

int add_song(char *artist, char *title, char *path);

int remove_song(int id);

void play(int id);

void status();

void load(FILE *fp);

#endif


