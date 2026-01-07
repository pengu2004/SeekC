#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "reader.h"

int check_text_file(const char *name) {
  const char *extension = strrchr(name, '.');
  if (!extension) {
    return 0;
  }
  const char *extentions[] = {".csv", ".c", ".h"};
  int count =
      sizeof(extentions) / sizeof(extentions[0]); // find the lenght of array
  for (int i = 0; i < count; i++) {
    if (strcmp(extension, extentions[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

void scan_dir(const char *path) {
  DIR *openfile = opendir(path); // open the file
  if (!openfile) {
    perror("Open Dir error");
  }
  while (1) {
    struct dirent *pfile =
        readdir(openfile); // read the file the fro the file stream
    if (pfile ==
        NULL) { // check if the readdir returns null which indicates end of dir
      break;
    }
    if (check_text_file(pfile->d_name)) { // if the checked fike is a text file
      char full_path[1024];
      snprintf(full_path, sizeof(full_path), "%s/%s", path, pfile->d_name);
      process_file(full_path);
    }
  }
  closedir(openfile);
}
