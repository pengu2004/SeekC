#include <stdio.h>
void process_file(char *fullpath) {
  printf("processing  the file%s", fullpath);
  FILE *fptr = fopen(fullpath, "r");
  if (!fptr) {
    perror("Opening error");
    return;
  }
  printf("\nFILE: %s\n\n", fullpath);

  // open the file
}
