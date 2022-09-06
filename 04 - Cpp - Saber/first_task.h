#ifndef FIRST_TASK_H
#define FIRST_TASK_H
#include <limits.h>

#include <cstdint>
#include <iostream>

template <typename T>
std::string intToBinStr(T num) {
  std::string res;
  int shifts_count = sizeof(T) * 8 - 2;
  T mask = static_cast<T>(1);
  mask <<= shifts_count;

  if (num < 0) res.push_back('1');

  while (mask) {
    if (num & mask)
      res.push_back('1');
    else
      res.push_back('0');
    mask >>= 1;
  }
  return res;
}

#endif  // FIRST_TASK_H
