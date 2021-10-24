#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"
#include "list.h"

int main(){

  srand(time(NULL));

  printf("\nLINKED LIST TESTS\n");                  // LIST TESTS
  printf("\n====================================\n\n");

  // Adding songs for list tests
  struct song_node *list = create_song("pearl jam", "yellow ledbetter");
  list = insert_order(list, "radiohead", "paranoid android");
  list = insert_order(list, "pearl jam", "even flow");
  list = insert_order(list, "ac/dc", "thunderstruck");
  list = insert_order(list, "radiohead", "street spirit (fade out)");
  list = insert_order(list, "pink floyd", "time");
  list = insert_order(list, "pearl jam", "alive");
  

  printf("Testing print_list:\n ");
  print_list(list);
  printf("\n====================================\n\n");


  printf("Testing find_node:\n");                 // FIND_NODE
  printf("looking for [pearl jam: even flow]\n");
  struct song_node * s1 = find_node(list, "pearl jam", "even flow");
  if(s1){
    printf("\tnode found! ");
    print_node(s1);
  }
  else
    printf("\tnode not found\n");

  printf("\nlooking for [pearl jam: daughter]\n");
  struct song_node * s2 = find_node(list, "pearl jam", "daughter");
  if(s2){
    printf("\tnode found! ");
    print_node(s2);
  }
  else
    printf("\tnode not found\n");
  printf("\n====================================\n\n");


  printf("Testing find_artist:\n");             // FIND_ARTIST
  printf("looking for [pink floyd]\n");
  struct song_node * s3 = find_artist(list, "pink floyd");
  if(s3){
    printf("\tartist found! ");
    print_list(s3);
  }
  else
    printf("\tartist not found\n");

  printf("looking for [pearl jam]\n");
  struct song_node * s4 = find_artist(list, "pearl jam");
  if(s4){
    printf("\tartist found! ");
    print_list(s4);
  }
  else
    printf("\tartist not found\n");

  printf("looking for [presidents of the united states of america]\n");
  struct song_node * s5 = find_artist(list, "presidents of the united states of america");
  if(s5){
    printf("\tartist found! ");
    print_list(s5);
  }
  else
    printf("\tartist not found\n");
  printf("\n====================================\n\n");


  printf("Testing songcmp (helper function):\n"); // SONGCMP
  struct song_node * s6 = create_song("pearl jam", "even flow");
  struct song_node * s7 = create_song("pearl jam", "even flow");
  struct song_node * s8 = create_song("pearl jam", "alive");
  struct song_node * s9 = create_song("pink floyd", "time");
  printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n");
  printf("\t%d\n", songcmp(s6, s7));
  printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n");
  printf("\t%d\n", songcmp(s7, s8));
  printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n");
  printf("\t%d\n", songcmp(s8, s7));
  printf("Comparing [pearl jam: even flow] to [pink floyd: time]\n");
  printf("\t%d\n", songcmp(s6, s9));
  printf("\n====================================\n\n");

  
  printf("Testing random:\n");                    // RANDOM
  print_node(random_song(list));
  printf("\n");
  print_node(random_song(list));
  printf("\n");
  print_node(random_song(list));
  printf("\n");
  print_node(random_song(list));
  printf("\n");
  printf("\n====================================\n\n");


  printf("Testing remove:\n");                    // REMOVE
  printf("Removing [ac/dc: thunderstruck]\n ");
  list = remove_song(list, "ac/dc", "thunderstruck");
  print_list(list);
  printf("Removing [radiohead: street spirit (fade out)]\n ");
  list = remove_song(list, "radiohead", "street spirit (fade out)");
  print_list(list);
  printf("Removing [pearl jam: yellow ledbetter]\n ");
  list = remove_song(list, "pearl jam", "yellow ledbetter");
  print_list(list);
  printf("Removing [pearl jam: yellow ledbetter]\n ");
  list = remove_song(list, "pearl jam", "yellow ledbetter");
  print_list(list);
  printf("\n====================================\n\n");


  printf("Testing free_list:\n");                 // FREE_LIST
  list = free_list(list);
  printf("list after free_list:\n");
  print_list(list);
  printf("\n====================================\n\n");





  printf("MUSIC LIBRARY TESTS\n");                // LIBRARY TESTS
  printf("\n====================================\n\n");
  struct song_node **library = make_library();

  printf("Testing print_letter\n");               // PRINT_LETTER AND PRINT_LIBRARY
  print_letter(library, 'a');
  printf("\n====================================\n\n");
  printf("Testing print_library\n");
  print_library(library);
  printf("\n====================================\n\n");

  // Adding songs for more tests
  library = add_song(library, "pearl jam", "alive");
  library = add_song(library, "radiohead", "street spirit (fade out)");
  library = add_song(library, "radiohead", "paranoid android");
  library = add_song(library, "ac/dc", "thunderstruck");
  library = add_song(library, "pearl jam", "even flow");
  library = add_song(library, "pearl jam", "yellow ledbetter");
  library = add_song(library, "pink floyd", "time");
  library = add_song(library, "presidents of the united states of america", "peaches");
  library = add_song(library, "!@#", "TEST"); // Fake song to test symbols

  printf("Testing print_letter - p\n"); 
  print_letter(library, 'p');
  printf("\n====================================\n\n");
  printf("Testing print_library\n");
  print_library(library);
  printf("\n====================================\n\n");


  printf("Testing find:\n");                      // FIND_SONG_LIB
  printf("looking for [pearl jam: alive]\n");
  struct song_node * s10 = find_song_lib(library, "pearl jam", "alive");
  if(s10){
    printf("\tsong found! ");
    print_node(s10);
  }
  else
    printf("\tsong not found");

  printf("\nlooking for [pearl jam: time]\n");
  struct song_node * s11 = find_song_lib(library, "pearl jam", "alive");
  if(s11){
    printf("\tsong found! ");
    print_node(s11);
  }
  else
    printf("\tsong not found");
  printf("\n\n====================================\n\n");


  printf("Testing find artist:\n");                // FIND_ARTIST_LIB
  printf("looking for [pearl jam]\n");
  struct song_node * s12 = find_artist_lib(library, "pearl jam");
  if(s12){
    printf("\tartist found! ");
    print_list(s12);
  }
  else
    printf("\tartist not found");

  printf("looking for [pink floyd]\n");
  struct song_node * s13 = find_artist_lib(library, "pink floyd");
  if(s12){
    printf("\tartist found! ");
    print_list(s13);
  }
  else
    printf("\tartist not found\n");

  printf("looking for [bob dylan]\n");
  struct song_node * s14 = find_artist_lib(library, "bob dylan");
  if(s14){
    printf("\tartist found! ");
    print_list(s14);
  }
  else
    printf("\tartist not found\n");
  
  printf("looking for [!@#]\n");
  struct song_node * s15 = find_artist_lib(library, "!@#");
  if(s15){
    printf("\tartist found! ");
    print_list(s15);
  }
  else
    printf("\tartist not found\n");
  printf("\n====================================\n\n");


  printf("Testing remove_song:\n");                // REMOVE_SONG_LIB
  printf("removing: [pearl jam: alive]\n");
  library = remove_song_lib(library, "pearl jam", "alive");
  print_library(library);
  printf("\nremoving: [pearl jam: yellow ledbetter]\n");
  library = remove_song_lib(library, "pearl jam", "yellow ledbetter");
  print_library(library);
  printf("\n====================================\n\n");


  printf("Testing clear_library:\n");              // CLEAR_LIBRARY
  library = clear_library(library);
  printf("\nLibrary after clear:");
  print_library(library);
  printf("\n\n====================================\n\n");


  printf("Adding songs to empty library\n");        // ADD_SONG AND PRINT_LIBRARY 
  library = add_song(library, "ac/dc", "thunderstruck");
  library = add_song(library, "pearl jam", "alive");
  library = add_song(library, "pearl jam", "even flow");
  library = add_song(library, "pearl jam", "yellow ledbetter");
  library = add_song(library, "pink floyd", "time");
  print_library(library);
  printf("\n====================================\n\n");


  printf("Testing print_artist:\n");               // PRINT_ARTIST
  printf("Printing [pearl jam]\n"); 
  print_artist(library, "pearl jam");
  printf("Printing [ac/dc]\n"); 
  print_artist(library, "ac/dc");
  printf("Printing [radiohead]\n"); 
  print_artist(library, "radiohead");
  printf("\n====================================\n\n");
  
  
  printf("Testing shuffle\n");                     // SHUFFLE
  shuffle(library);
  printf("\n====================================\n\n");


  return 0;
} 

/*

Testing shuffle
{pink floyd, time}
{pearl jam, yellow ledbetter}
{pearl jam, alive}
====================================

*/