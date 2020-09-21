#include "map.h"

Map* create_map() {
  Map* m = malloc(sizeof(Map));
  if (m == NULL) {
    return NULL;
  }
  m->count = 0;
  m->pairs = NULL;
  return m;
}

int search_map(Map* m, char* key) {
  if (m != NULL) {
    for (int i = 0; i < m->count; i++) {
      if (strcmp(key, m->pairs[i].key) == 0) {
        return i;
      }
    }
  }
  return -1;
}

void add_key(Map* m, char* key) {
  if (m != NULL) {
    if (m->pairs == NULL) {
      m->count = 1;
      m->pairs = malloc(sizeof(Pair));
      m->pairs->key = key;
      m->pairs->value = 1;
    }
    else {
      m->count++;
      Pair* new_pairs = realloc(m->pairs, m->count * sizeof(Pair));
      if (new_pairs) {
        new_pairs[m->count-1].key = key;
        new_pairs[m->count-1].value = 1;
        m->pairs = new_pairs;
      }
    }
  }
}
