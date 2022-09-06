#ifndef LIST_H
#define LIST_H

#include <iostream>

struct ListNode {
  ListNode() : next(nullptr), prev(nullptr), rand(nullptr) {}
  ListNode(std::string str)
      : data(str), next(nullptr), prev(nullptr), rand(nullptr) {}
  ListNode(std::string str, ListNode* prev)
      : data(str), prev(prev), next(nullptr), rand(nullptr) {}
  ListNode(std::string str, ListNode* prev, ListNode* next)
      : data(str), prev(prev), next(next), rand(nullptr) {}
  ListNode* prev;
  ListNode* next;
  ListNode*
      rand;  // указатель на произвольный элемент данного списка, либо NULL
  std::string data;
};

class List {
 public:
  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
  void Serialize(FILE* file);
  // загрузка из файла (файл открыт спомощью fopen(path, "rb"))
  void Deserialize(FILE* file);

 private:
  ListNode* head;
  ListNode* tail;
  int count;
};

#endif  // LIST_H
