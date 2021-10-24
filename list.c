#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

// Create new song node
struct song_node * create_song(char *a, char *n){
  struct song_node *s =	malloc(sizeof(struct song_node));
  strcpy(s->name, n);
  strcpy(s->artist, a);
  s->next = NULL;
  return s;
}

// Prints a song node
void print_node(struct song_node *s){
  if(s)
    printf("{%s, %s}", s->artist, s->name);
  return;
}

// Inserts nodes at the front
struct song_node * insert_front(struct song_node *s, char *a, char *n){
  struct song_node * new_song = create_song(a, n);
  new_song->next = s;
  return new_song;
}

// Compares song nodes
int songcmp(struct song_node *s1, struct song_node *s2){
  int artistcmp = strcmp(s1->artist, s2->artist);
  if(artistcmp == 0){
    return strcmp(s1->name, s2->name);
  }
  return artistcmp;
}

// Inserts nodes in order
struct song_node * insert_order(struct song_node *s, char *a, char *n){
  struct song_node * new_song = create_song(a, n);
  if(!s){
    return new_song;
  }
  if(songcmp(new_song, s) < 0){
    s = insert_front(s, a, n);
    return s;
  }
  struct song_node * tmp = s;
  while(s->next && songcmp(new_song, s->next) > 0){
    s = s->next;
  }
  if(s->next)
    new_song->next = s->next;
  s->next = new_song;
  return tmp;
  return s;
}

// Print the entire list of song nodes
void print_list(struct song_node *front){
  printf("[ ");
  while(front){
    print_node(front);
    printf(" | ");
    front = front->next;
  }
  printf("]\n");
  return;
}

// Finds and returns a pointer to a node based on artist and song name
struct song_node * find_node(struct song_node *s, char *a, char *n){
  while(s){
    if(!strcmp(s->name, n) && !strcmp(s->artist, a)){
      return s;
    }
    s = s->next;
  }
  return s;
}

// Finds and returns a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node *s, char *a){
  while(s){
    if(!strcmp(s->artist, a)){
      return s;
    }
    s = s->next;
  }
  return NULL;
}

// Returns the size of a list
int list_size(struct song_node *s){
  int count = 0;
  while(s){
    count++;
    s = s->next;
  }
  return count;
}

// Returns a pointer to random element in the list.
struct song_node * random_song(struct song_node *s){
  int len = list_size(s);
  int x = rand()%len;
  while(x){
    s = s->next;
    x--;
  }
  return s;
}

// Removes a single specified node from the list
struct song_node * remove_song(struct song_node *front, char *a, char *n){
  struct song_node *tmp = front;
  struct song_node *first = front;
  if(!strcmp(front->artist, a) && !strcmp(front->name, n)){
    front = front->next;
    free(tmp);
    return front;
  }
  front = front->next;
  while(front){
    if(!strcmp(front->artist, a) && !strcmp(front->name, n)){
      tmp->next = front->next;
      free(front);
      return first;
    }
    front = front->next;
    tmp = tmp->next;
  }
  return first;
}

// Frees the entire list
struct song_node * free_list(struct song_node *s){
  struct song_node *tmp;
  while(s){
    tmp = s;
    s = s->next;
    printf("freeing_node: {%s, %s}\n", tmp->artist, tmp->name);
    free(tmp);
  }
  return s;
}


