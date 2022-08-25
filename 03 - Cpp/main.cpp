#include <iostream>
#include <vector>

#include "circular_buffer_array.h"
#include "circular_buffer_list.h"

using namespace std;

int main() {
  // CircularBuffer test
  //  CircularBufferArray<int, 5> buf;
  CircularBufferList<int, 5> buf;
  buf.write(1);
  buf.write(2);
  buf.write(3);
  buf.write(4);
  buf.write(5);
  buf.write(6);
  std::optional<int> got = buf.get();
  if (got) cout << "5add got = " << *got << endl;
  got = buf.get();
  if (got) cout << "6add got = " << *got << endl;
  //  buf.write(7);
  //  buf.write(8);
  while (!buf.empty()) {
    std::optional<int> tmp = buf.read();
    if (tmp) {
      cout << *tmp << endl;
    }
  }
  got = buf.get();
  if (got) cout << "got = " << *got << endl;

  buf.write(4);
  cout << "bufer write 4" << endl;
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
  cout << "~CircularBuffer test" << endl;

  //  int a[5] = {1, 1, 1, 1, 1};

  //  cout << a[0] - a[4] << endl;
  //  cout << a - (a + 4) << endl;

  //  std::forward_list<int> l;
  //  l.insert_after(l.begin(), 1);
  //  l.insert_after(l.begin(), 2);
  //  l.insert_after(l.begin(), 3);
  //  l.insert_after(l.begin(), 4);
  //  l.insert_after(l.begin(), 5);

  //  auto it = l.begin();
  //  ++it;
  //  cout << "IT=" << *it << endl;
  //  int b = *it;

  return 0;
}
