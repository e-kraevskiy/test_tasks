#include <iostream>

#include "circular_buffer_array.h"

using namespace std;

int main() {
  // CircularBuffer test
  CircularBuffer<int, 5> buf;
  buf.write(1);
  buf.write(2);
  buf.write(3);
  buf.write(4);
  buf.write(5);
  buf.write(6);
  while (!buf.empty()) {
    std::optional<int> tmp = buf.read();
    if (tmp) {
      cout << *tmp << endl;
    }
  }
  std::optional<int> got = buf.get();
  if (got) cout << "got = " << *got << endl;
  buf.write(4);
  cout << "bufer capacity = " << buf.capacity() << endl;
  cout << "bufer size = " << buf.size() << endl;
  optional<int> tmp = buf.read();
  if (tmp) cout << endl << *tmp << endl;
  if (buf.empty()) {
    cout << "bufer empty" << endl;
  }
  cout << "bufer size = " << buf.size() << endl;
  cout << "bufer capacity = " << buf.capacity() << endl;
  // ~CircularBuffer test

  return 0;
}
