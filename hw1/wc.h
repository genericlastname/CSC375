#ifndef WC_H
#define WC_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct WCInfo {
  int newlines;
  int words;
  int bytes;
} WCInfo;

WCInfo* word_count(char* s);

#endif
