#ifndef SECONT_TASK_H
#define SECONT_TASK_H

void RemoveDups(char* str) {
  char* cur = str;
  char* last_unique = str;
  while (*cur != '\0') {
    if (*cur != *last_unique) *(++last_unique) = *cur;
    ++cur;
  }
  *(++last_unique) = '\0';
}

#endif  // SECONT_TASK_H
