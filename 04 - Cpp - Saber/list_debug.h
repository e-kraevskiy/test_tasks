#ifndef LIST_DEBUG_H
#define LIST_DEBUG_H

#include "list.h"

List getTestList() {
  std::string tmp = "AA";
  ListNode* n1 = new ListNode(tmp);

  n1->next_ = new ListNode("BB", n1);
  ListNode* n2 = n1->next_;

  n2->next_ = new ListNode("CC", n2);
  ListNode* n3 = n2->next_;

  n3->next_ = new ListNode("DD", n3);
  ListNode* n4 = n3->next_;

  n4->next_ = new ListNode("EE", n4);
  ListNode* n5 = n4->next_;

  n1->rand_ = n5;
  n2->rand_ = n1;
  n3->rand_ = n3;
  //  n4->rand_ = n2;
  n5->rand_ = n3;

  return List(n1, n5, 5);
}

#endif  // LIST_DEBUG_H
