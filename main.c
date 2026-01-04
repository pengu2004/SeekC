#include "scanner.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
  printf("The value of argc is %d\n", argc);
  char cmd[255];
  char folder1[255];
  strcpy(cmd, argv[1]);
  strcpy(folder1, argv[2]);
  scan_dir(folder1);
}
