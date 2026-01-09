#include "index.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Word *add_word(Word *head, const char *word) {
  Word *curr = head;
  while (curr) {
    if (strcmp(curr->text, word) == 0) {
      curr->count++;
      return head;
    }
    curr = curr->next;
  }
  Word *new_word = malloc(sizeof(Word));
  if (!new_word) {
    printf("No space");
    return head;
  }

  new_word->text = strdup(word);
  new_word->count = 1;
  new_word->next = head;
  return new_word;
}

void print_words(Word *head) {
  printf("Printing the words");
  Word *curr = head;
  while (curr) {
    printf("%s %d\n", curr->text,curr->count);
    curr = curr->next;
  }
  printf("You have reached the end");
}

Word *sort_word(Word *head){
    //bubble sort
    //
    int swapped;

    do{
        swapped=0;
        
        Word *curr = head;
    while(curr->next    ){
        Word *second=curr->next;
        if (second->count>curr->count){
            char *temp_word=curr->text;
            int temp_count=curr->count;
            curr->text=second->text;
            curr->count=second->count;
            second->text=temp_word;
            second->count=temp_count;
            swapped = 1;   
        }
        curr = curr->next;
    }
    }
    while(swapped);
    return head;
}
