#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "library.h"

struct song_node ** make_library(){
  struct song_node ** lib = calloc(27, sizeof(struct song_node *));
  return lib;
}

int find_ind(char *a){
  if (a[0] >= 97 && a[0] <= 122)
    return a[0]-97;
  else if (a[0] >= 65 && a[0] <= 90)
    return a[0]-65;
  return 26;
}

struct song_node ** add_song(struct song_node **lib, char *a, char *n){
  int i = find_ind(a);
  lib[i] = insert_order(lib[i], a, n);
  return lib;
}

struct song_node * find_song_lib(struct song_node **lib, char *a, char *n){
  return find_node(lib[find_ind(a)], a, n);
}

struct song_node * find_artist_lib(struct song_node **lib, char *a){
  return find_artist(lib[find_ind(a)], a);
}

void print_letter(struct song_node **lib, char c){
  char *cp = &c;
  struct song_node *list = lib[find_ind(cp)];
  print_list(list);
}

void print_artist(struct song_node **lib, char *a){
  printf("%s: ", a);
  struct song_node *tmp = find_artist_lib(lib, a);
  if(tmp){
    printf("[ ");
    while(tmp && !strcmp(tmp->artist, a)){
      print_node(tmp);
      printf(" | ");
      tmp = tmp->next;
    }
    printf(" ]\n");
  }
  else
    printf("\n");
  return;
}

void print_library(struct song_node **lib){
  int i;
  for(i=0; i<=26; i++){
    if(lib[i]){
      printf("%c: ", i+97);
      print_list(lib[i]);
    }
  }
}

void shuffle(struct song_node **lib){
  srand(time(NULL));
  struct song_node *tmp = lib[rand()%27];
  int count = rand()%5 + 2;
  while(count){
    tmp = lib[rand()%27];
    if(tmp){
      print_node(random_song(tmp));
      printf("\n");
      count--;
    }
  }
}

struct song_node ** remove_song_lib(struct song_node **lib, char *a, char *n){
  int i = find_ind(a);
  lib[i] = remove_song(lib[i], a, n);
  return lib;
}

struct song_node ** clear_library(struct song_node **lib){
  int i;
  for(int i=0; i<27; i++){
    lib[i] = free_list(lib[i]);
  }
  return lib;
}

