#ifndef LIST_DEBUG_H
#define LIST_DEBUG_H

#include "list.h"

List getTestList() {
  std::string tmp = "AA";
  ListNode* n1 = new ListNode(tmp);

  n1->next = new ListNode("BB", n1);
  ListNode* n2 = n1->next;

  n2->next = new ListNode("CC", n2);
  ListNode* n3 = n2->next;

  n3->next = new ListNode("DD", n3);
  ListNode* n4 = n3->next;

  n4->next = new ListNode("EE", n4);
  ListNode* n5 = n4->next;

  n1->rand = n5;
  n2->rand = n1;
  n3->rand = n3;
  //  n4->rand = n2;
  n5->rand = n3;

  return List(n1, n5, 5);
}

void printList(List list) {
  ListNode* head = list.head_;
  while (head) {
    std::cout << "cur=" << head->data << "\trand=" << head->rand->data
              << std::endl;
    head = head->next;
  }
}

#endif  // LIST_DEBUG_H
