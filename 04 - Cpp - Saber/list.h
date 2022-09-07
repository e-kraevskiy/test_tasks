#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

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
  List() : head_(nullptr), tail_(nullptr), count_(0) {}
  List(ListNode* head, ListNode* tail, int count)
      : head_(head), tail_(tail), count_(count) {}
  ~List() { clearList(); };
  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
  void serialize(FILE* file);
  // загрузка из файла (файл открыт спомощью fopen(path, "rb"))
  void deserialize(FILE* file);

  void printList();
  void clearList();

  ListNode* head_;

 private:
  ListNode* tail_;
  int count_;
};

#endif  // LIST_H
