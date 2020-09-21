#include "wc.h"

WCInfo* word_count(char* s) {
  WCInfo* wc = malloc(sizeof(WCInfo));
  wc->newlines = 0;
  wc->words = 0;
  wc->bytes = 0;
  bool in_word = false;
  int i = 0;
  while (s[i] != '\0') {
    if (isalnum(s[i])) {
      in_word = true;
    }
    else {
      in_word = false;
      if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
        wc->words++;
      }
      if (s[i] == '\n') {
        wc->newlines++;
      }
    }
    i++;
  }
  if (in_word) {
    wc->words++;
  }
  wc->bytes = strlen(s);
  return wc;
}
