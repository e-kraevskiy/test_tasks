#include "list.h"

void List::serialize(FILE* file) {
  fwrite(&count_, sizeof(count_), 1, file);

  int index = 0;
  // Записываем длинну data + data
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    int data_size = cur->data.size();
    fwrite(&data_size, sizeof(int), 1, file);
    fwrite(cur->data.c_str(), sizeof(char), data_size, file);
    // Меняем prev на узел с индексом текущего узла в data
    cur->prev = new ListNode(std::to_string(index));
    ++index;
  }
  // Записываем индекс rand узла
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    int rand_index = 0;
    // Если rand == nullptr -> записываем -1;
    if (cur->rand != nullptr) {
      rand_index = atoi(cur->rand->prev->data.c_str());
    } else {
      rand_index = -1;
    }
    fwrite(&rand_index, sizeof(int), 1, file);
  }
  // Восстанавливаем prev у головы
  if (head_ != nullptr) {
    delete head_->prev;
    head_->prev = nullptr;
  }
  // Восстанавливаем prev у всех остальных
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    if (cur->next != nullptr) {
      delete cur->next->prev;
      cur->next->prev = cur;
    }
  }
}

void List::deserialize(FILE* file) {
  clear();
  fread(&count_, sizeof(count_), 1, file);
  std::vector<ListNode*> ptr_vec;
  ptr_vec.reserve(count_);

  // Заполняем next и prev
  for (int i = 0; i < count_; ++i) {
    int data_size = 0;
    fread(&data_size, sizeof(int), 1, file);
    std::string tmp;
    tmp.resize(data_size);
    fread(tmp.data(), sizeof(char), data_size, file);

    // Добавляем новый узел
    if (i != 0) {
      tail_->next = new ListNode(tmp, tail_);
      tail_ = tail_->next;
    } else {
      head_ = new ListNode(tmp);
      tail_ = head_;
    }
    ptr_vec.push_back(tail_);
  }
  // Заполняем rand
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    int index = 0;
    fread(&index, sizeof(int), 1, file);
    if (index != -1)
      cur->rand = ptr_vec.at(index);
    else
      cur->rand = nullptr;
  }
}

void List::printList() {
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    std::cout << "cur=" << cur->data;
    std::string tmp;
    if (cur->prev)
      tmp = cur->prev->data;
    else
      tmp = "null";

    std::cout << "\tprev=" << tmp;
    if (cur->rand)
      tmp = cur->rand->data;
    else
      tmp = "null";
    std::cout << "\trand=" << tmp << std::endl;
  }
}

void List::clear() {
  ListNode* cur = head_;
  ListNode* tmp = nullptr;

  while (cur != nullptr) {
    tmp = cur->next;
    delete cur;
    cur = tmp;
  }
  head_ = nullptr;
  tail_ = nullptr;
  count_ = 0;
}
