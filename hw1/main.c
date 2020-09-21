#define MAX_LIMIT 1000

#include <stdio.h>

#include "wc.h"

int main(int argc, char** argv) {
  WCInfo* wc;
  if (argc == 1) {
    char input[MAX_LIMIT];
    fflush(stdin);
    fread(input, sizeof(char), MAX_LIMIT, stdin);
    // scanf("%[^\n]%*c", input);
    wc = word_count(input);
  }
  else {
    char* input;
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
      return 1;
    }
    fseek(fp, 0L, SEEK_END);
    int numbytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    input = malloc(numbytes * sizeof(char));
    if (input == NULL) {
      return 2;
    }
    fread(input, sizeof(char), numbytes, fp);
    wc = word_count(input);
    fclose(fp);
  }

  printf("\t%d\t%d\t%d\t", wc->newlines, wc->words, wc->bytes);
  if (argc > 1) {
    printf(" %s", argv[1]);
  }
  printf("\n");
  
  return 0;
}
