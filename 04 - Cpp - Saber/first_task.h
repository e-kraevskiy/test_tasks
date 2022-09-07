#ifndef FIRST_TASK_H
#define FIRST_TASK_H
#include <limits.h>

#include <cstdint>
#include <iostream>

template <typename T>
void printIntBinary(T num) {
  int shifts_count = sizeof(T) * 8 - 2;
  T mask = static_cast<T>(1);
  mask <<= shifts_count;
  // Знаковый бит
  if (num < 0)
    std::cout << '1';
  else
    std::cout << '0';

  while (mask) {
    if (num & mask)
      std::cout << '1';
    else
      std::cout << '0';
    mask >>= 1;
  }
  std::cout << std::endl;
}

#endif  // FIRST_TASK_H
