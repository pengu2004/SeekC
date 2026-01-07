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
    printf("%s \n", curr->text);
    curr = curr->next;
  }
  printf("You have reached the end");
}
