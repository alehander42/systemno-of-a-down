#include <stdio.h>

void fail(char* message) {
  printf("wc: %s\n", message);
  exit(1);
}

int count_stdin_lines() {
  int count = 0;
  char c;
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      count++;
    }
  }
  return count;
}

int count_file_lines(char* filename) {
  FILE* file = fopen(filename, "r");
  if(!file) {
    char message[256];
    sprintf(message, "%s: No such file or directory", filename);
    fail(message);
  }

  int count = 0; char c;
  while((c = fgetc(file)) != EOF) {
    if(c == '\n') {
      count++;
    }
  }
  return count;
}

int main(int argc, char* argv[]) {
  int count = 0;

  if(argc == 1) {
    count = count_stdin_lines();
    printf("%d\n", count);
  }
  else if(argc == 2) {
    count = count_file_lines(argv[1]);
    printf("%d %s\n", count, argv[1]);
  }
  else {
    int i;
    int j;
    for(i = 1; i < argc;i ++) {
      j = count_file_lines(argv[i]);
      printf("%d %s\n", j, argv[i]);
      count += j;
    }
    printf("%d total\n", count);
  }
  return 0;
}
