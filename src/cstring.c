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

void cstring_free(CString *cstr) {
  free(cstr->str);
  free(cstr);
}
