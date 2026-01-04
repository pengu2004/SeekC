#include <stdio.h>

#include <dirent.h>
#include <sys/types.h>

void scan_dir(const char *path) {
  printf("The path %s", path);
  DIR *openfile = opendir(path); //open the file
  while (1) {
    struct dirent *pfile = readdir(openfile); //read the file the fro the file stream
    if (pfile == NULL) { //check if the readdir returns null which indicates end of dir
      break;
    }
    printf("%s\n", pfile->d_name);
  }
}
