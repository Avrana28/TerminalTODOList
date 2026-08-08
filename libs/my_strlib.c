#include <stdlib.h>
#include "my_strlib.h"


size_t my_strlen( const char s[]) {
    const char *ptr = s;
    while ( *ptr != '\0' ) {
        ptr++;
    }
    return ptr - s;
}
char* my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return ptr;
}

int my_strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1 < *s2) {
      return -1;
    }
    if (*s1 > *s2) {
      return 1;
    }
    s1++;
    s2++;
  }
  
  if (*s1 < *s2) {
    return -1;
  }
  if (*s1 > *s2) {
    return 1;
  }
  return 0;
}

char *my_join(const char *s1, const char *s2) {
  int len1 = 0;
  int len2 = 0;

  while (s1[len1] != '\0')
    len1++;
  while (s2[len2] != '\0')
    len2++;

  char *result = (char *)malloc(len1 + len2 + 1);

  if (result == NULL) {
    return NULL;
  }
  
  int i = 0;
  for (int j = 0; j < len1; j++) {
    result[i] = s1[j];
    i++;
  }

  for (int j = 0; j < len2; j++) {
    result[i] = s2[j];
    i++;
  }
  result[i] = '\0';

  return result;
}
