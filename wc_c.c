#include<stdio.h>

void fail(char* message) {
  printf("wc: %s\n", message);
  exit(1);
}

int count_stdin() {
  int count = 0;
  while(getchar() != EOF) {
  	count++;
  }
  return count;
}

int count_file_characters(char* filename) {
  FILE* file = fopen(filename, "r");
  if(!file) {
  	char message[256];
  	sprintf(message, "%s: No such file or directory", filename);
  	fail(message);
  }

  int count = 0;
  while(fgetc(file) != EOF) {
  	count++;
  }
  return count;
}

int main(int argc, char* argv[]) {
  int count = 0;

  if(argc == 1) {
    count = count_stdin();
    printf("%d\n", count);
  }
  else if(argc == 2) {
    count = count_file_characters(argv[1]);
    printf("%d %s\n", count, argv[1]);
  }
  else {
    int i;
    int j;
    for(i = 1; i < argc;i ++) {
      j = count_file_characters(argv[i]);
      printf("%d %s\n", j, argv[i]);
      count += j;
    }
    printf("%d total\n", count);
  }
  return 0;
}

