#include <stdio.h>
#include "index.h"
void process_file(char *fullpath) {
  printf("processing  the file%s", fullpath);
  FILE *fptr = fopen(fullpath, "r");
  if (!fptr) {
    perror("Opening error");
    return;
  }
  printf("\nFILE: %s\n\n", fullpath);
  char word[256]; 
  
  Word *head=NULL;
  while(fscanf(fptr,"%99s",word)==1){
  head=add_word(head,word);
  }
  head=sort_word(head);
  print_words(head);
  // open the file
}
