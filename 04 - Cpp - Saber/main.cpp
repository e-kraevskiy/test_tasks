#include <cstdint>
#include <iostream>

#include "first_task.h"
#include "list.h"
#include "list_debug.h"
#include "secont_task.h"

using namespace std;

int main() {
  //  cout << "1=\t" << intToBinStr(1) << endl;
  //  cout << "-2147483647=\t" << intToBinStr(-2147483647) << endl;
  //  cout << "-2147483648=\t" << intToBinStr(-2147483648) << endl;
  //  cout << "2147483647=\t" << intToBinStr(2147483647) << endl;
  //  cout << "-1=\t" << intToBinStr(-1) << endl;
  //  cout << "2=\t" << intToBinStr(2) << endl;
  //  cout << "3=\t" << intToBinStr(3) << endl;
  //  cout << "4=\t" << intToBinStr(4) << endl;
  //  cout << "5=\t" << intToBinStr(5) << endl;
  //  cout << "8=\t" << intToBinStr(8) << endl;
  //  cout << "16=\t" << intToBinStr(16) << endl;
  //  cout << "32=\t" << intToBinStr(32) << endl;

  //  char data[] = "AAA BBB CCC";
  //  cout << data << "=";
  //  RemoveDups(data);
  //  cout << data << endl;
  //  char test[] = "AAA asdasdasdasdasdadsssa BBB CCC";
  //  cout << test << "=";
  //  RemoveDups(test);
  //  cout << test << endl;
  FILE* file;

  List test = getTestList();
  test.printList();
  file = fopen("debug.dat", "wb");
  test.serialize(file);
  fclose(file);
  cout << "-----------" << endl;
  test.printList();
  cout << "-----------" << endl;

  file = fopen("debug.dat", "rb");
  test.deserialize(file);
  fclose(file);
  test.printList();

  return 0;
}
