#ifndef __CSTRING_LIB_FELIX__
#define __CSTRING_LIB_FELIX__

typedef struct CString {
  char *str;
  int size;
} CString;

// methods

// init a new CString
CString *cstring_new(void);

// init a new CString with a string
CString *cstring_from(const char *str);

// append a string to a CString
void cstring_append(CString *cstr, const char *str);

// free a CString
void cstring_free(CString *cstr);

#endif // __CSTRING_LIB_FELIX__
