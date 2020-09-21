#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <string.h>

typedef struct Pair {
  char* key;
  int value;
} Pair;

typedef struct Map {
  int count;
  Pair* pairs;
} Map;

Map* create_map();
int search_map(Map* m, char* key);
void add_key(Map* m, char* key);

#endif
