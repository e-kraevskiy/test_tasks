#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

struct ListNode {
  ListNode() : next_(nullptr), prev_(nullptr), rand_(nullptr) {}
  ListNode(std::string str)
      : data(str), next_(nullptr), prev_(nullptr), rand_(nullptr) {}
  ListNode(std::string str, ListNode* prev)
      : data(str), prev_(prev), next_(nullptr), rand_(nullptr) {}
  ListNode* prev_;
  ListNode* next_;
  ListNode*
      rand_;  // указатель на произвольный элемент данного списка, либо NULL
  std::string data;
};

class List {
 public:
  List() : head_(nullptr), tail_(nullptr), count_(0) {}
  List(ListNode* head, ListNode* tail, int count)
      : head_(head), tail_(tail), count_(count) {}
  ~List() { clear(); };
  void serialize(FILE* file);
  void deserialize(FILE* file);

  void printList();
  void clear();

 private:
  ListNode* head_;
  ListNode* tail_;
  int count_;
};

#endif  // LIST_H
