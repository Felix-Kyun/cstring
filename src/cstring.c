#include "cstring.h"
#include <stdlib.h>
#include <string.h>

CString *cstring_new(void) {
  CString *cstr = malloc(sizeof(CString));
  cstr->str = NULL;
  cstr->size = 0;
  return cstr;
}

CString *cstring_from(const char *str) {
  CString *cstr = cstring_new();
  cstr->str = strdup(str);
  cstr->size = strlen(str);

  return cstr;
}

void cstring_append(CString *cstr, const char *str) {
  cstr->str = realloc(cstr->str, cstr->size + strlen(str) + 1);
  strcat(cstr->str, str);
  cstr->size += strlen(str);
}

void cstring_replace(CString *cstr, const char *str) {
  free(cstr->str);
  cstr->str = strdup(str);
  cstr->size = strlen(str);
}

char *cstring_get(CString *cstr) {
  return cstr->str;
}

void cstring_free(CString *cstr) {
  free(cstr->str);
  free(cstr);
}

void cstring_append_char(CString *cstr, char c) {
  cstr->str = realloc(cstr->str, cstr->size + 2);
  cstr->str[cstr->size] = c;
  cstr->str[cstr->size + 1] = '\0';
  cstr->size++;
}

int cstring_cmp(CString *cstr, CString *cstr2) {
  // invert the return value of strcmp
  // because 0 means equal, and 1 means different
  // dont ask me why, I dont know
  return !strcmp(cstr->str, cstr2->str); 
}
