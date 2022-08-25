#include <iostream>
#include <vector>

#include "circular_buffer_array.h"
#include "circular_buffer_list.h"
#include "timsort.h"

using namespace std;

int main() {
  // CircularBuffer test
  CircularBufferArray<float, 5> buf;
  //  CircularBufferList<float, 5> buf;
  buf.write(1.0);
  buf.write(2.0);
  cout << "size = " << buf.size() << endl;
  buf.write(3.4);
  buf.write(4.4);
  buf.write(5.4);
  buf.write(6.4);
  buf.write(3.4);
  buf.write(4.4);
  buf.write(5.4);
  buf.write(6.4);
  buf.write(3.4);
  buf.write(4.4);
  buf.write(5.4);
  buf.write(6.4);
  std::optional<float> got = buf.get();
  if (got) cout << "5add got = " << *got << endl;
  got = buf.get();
  if (got) cout << "6add got = " << *got << endl;
  while (!buf.empty()) {
    std::optional<float> tmp = buf.read();
    if (tmp) {
      cout << *tmp << endl;
    }
  }
  got = buf.get();
  if (got) cout << "got = " << *got << endl;

  buf.write(4.2);
  cout << "bufer write 4" << endl;
  cout << "bufer capacity = " << buf.capacity() << endl;
  cout << "bufer size = " << buf.size() << endl;
  optional<float> tmp = buf.read();
  if (tmp) cout << endl << *tmp << endl;
  if (buf.empty()) {
    cout << "bufer empty" << endl;
  }
  cout << "bufer size = " << buf.size() << endl;
  cout << "bufer capacity = " << buf.capacity() << endl;
  // ~CircularBuffer test
  cout << "~CircularBufferList test" << endl;

  int a[15] = {4, 3, 4, 1, 5, 76, 12, 43, 43, 34, 45, 12, 43, 43, 23};
  timSort(a, 15);

  for (int i : a) {
    cout << i << " ";
  }

  return 0;
}
