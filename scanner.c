#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int check_text_file(const char *name) {
  const char *extension = strchr(name, '.');
  if (!extension) {
    return 0;
  }
  const char *extentions[] = {".csv", ".c", ".h"};
  int count =
      sizeof(extentions) / sizeof(extentions[1]); // find the lenght of array
  for (int i = 0; i < count; i++) {
    if (strcmp(extension, extentions[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

void scan_dir(const char *path) {
  printf("The path %s", path);
  DIR *openfile = opendir(path); // open the file
  while (1) {
    struct dirent *pfile =
        readdir(openfile); // read the file the fro the file stream
    if (pfile ==
        NULL) { // check if the readdir returns null which indicates end of dir
      break;
    }
    if (check_text_file(pfile->d_name)) {
      printf("%s\n", pfile->d_name);
    }
  }
}
