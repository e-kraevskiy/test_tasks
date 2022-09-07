#include "list.h"

void List::Serialize(FILE* file) {
  fwrite(&count_, sizeof(count_), 1, file);

  int index = 0;
  // Записываем длинну data + data
  // Меняем prev на узел с индексом в data
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    int data_size = cur->data.size();
    fwrite(&data_size, sizeof(int), 1, file);
    fwrite(&cur->data, sizeof(char), data_size, file);
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
  // Восстанавливаем указатели на prev
  if (head_ != nullptr) {
    delete head_->prev;
    head_->prev = nullptr;
  }
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next) {
    if (cur->next != nullptr) {
      delete cur->next->prev;
      cur->next->prev = cur;
    }
  }
}

void List::Deserialize(FILE* file) {
  fread(&count_, sizeof(count_), 1, file);
  std::vector<ListNode*> ptr_vec(count_);
  ListNode* cur = nullptr;

  // Заполняем next и prev
  for (int i = 0; i < count_; ++i) {
    int data_size = 0;
    fread(&data_size, sizeof(int), 1, file);
    std::string tmp;
    fread(&tmp, sizeof(char), data_size, file);

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
    cur->rand = ptr_vec.at(index);
  }
}
