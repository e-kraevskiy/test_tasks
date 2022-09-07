#include <cstdint>
#include <iostream>

#include "first_task.h"
#include "list.h"
#include "list_debug.h"
#include "secont_task.h"

using namespace std;

int main() {
  cout << "1=\t";
  printIntBinary(1);
  cout << "2147483647= \t";
  printIntBinary(2147483647);
  cout << INT_MAX << "=INT_MAX=\t";
  printIntBinary(INT_MAX);
  cout << "-2147483648= \t";
  printIntBinary(-2147483648);
  cout << INT_MIN << "=INT_MIN=\t";
  printIntBinary(INT_MIN);
  cout << "2147483647=\t";
  printIntBinary(2147483647);
  cout << "-1=\t";
  printIntBinary(-1);
  cout << "2=\t";
  printIntBinary(2);
  cout << "3=\t";
  printIntBinary(3);
  cout << "4=\t";
  printIntBinary(4);
  cout << "5=\t";
  printIntBinary(5);
  cout << "8=\t";
  printIntBinary(8);
  cout << "16=\t";
  printIntBinary(16);
  cout << "32=\t";
  printIntBinary(32);
  cout << "1 long =\t";
  long long a = 1;
  printIntBinary(a);
  cout << endl << "----------------- II ----------------" << endl << endl;

  char data[] = "AAA BBB CCC";
  cout << data << "=";
  RemoveDups(data);
  cout << data << endl;
  char test1[] = "AAA asdasdasdasdasdadsssa  BBB CCC";
  cout << test1 << "=";
  RemoveDups(test1);
  cout << test1 << endl;

  cout << endl << "----------------- III ----------------" << endl << endl;

  FILE* file;
  List test = getTestList();
  test.printList();
  file = fopen("debug.dat", "wb");
  test.serialize(file);
  fclose(file);
  cout << "--------------------------------"
       << " after serialize:" << endl;
  test.printList();
  cout << "--------------------------------"
       << " after deserialize:" << endl;
  file = fopen("debug.dat", "rb");

  List test2;
  test2.deserialize(file);
  fclose(file);
  test2.printList();

  return 0;
}
