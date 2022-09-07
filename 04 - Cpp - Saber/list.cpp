#include "list.h"

void List::serialize(FILE* file) {
  fwrite(&count_, sizeof(count_), 1, file);

  int index = 0;
  // Записываем длинну data + data
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next_) {
    int data_size = cur->data.size();
    fwrite(&data_size, sizeof(int), 1, file);
    fwrite(cur->data.c_str(), sizeof(char), data_size, file);
    // Меняем prev_ на узел с индексом текущего узла в data
    cur->prev_ = new ListNode(std::to_string(index));
    ++index;
  }
  // Записываем индекс rand_ узла
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next_) {
    int rand__index = 0;
    // Если rand_ == nullptr -> записываем -1;
    if (cur->rand_ != nullptr) {
      rand__index = atoi(cur->rand_->prev_->data.c_str());
    } else {
      rand__index = -1;
    }
    fwrite(&rand__index, sizeof(int), 1, file);
  }
  // Восстанавливаем prev_ у головы
  if (head_ != nullptr) {
    delete head_->prev_;
    head_->prev_ = nullptr;
  }
  // Восстанавливаем prev_ у всех остальных
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next_) {
    if (cur->next_ != nullptr) {
      delete cur->next_->prev_;
      cur->next_->prev_ = cur;
    }
  }
}

void List::deserialize(FILE* file) {
  clear();
  fread(&count_, sizeof(count_), 1, file);
  std::vector<ListNode*> ptr_vec;
  ptr_vec.reserve(count_);

  // Заполняем next_ и prev_
  for (int i = 0; i < count_; ++i) {
    int data_size = 0;
    fread(&data_size, sizeof(int), 1, file);
    std::string tmp;
    tmp.resize(data_size);
    fread(tmp.data(), sizeof(char), data_size, file);

    // Добавляем новый узел
    if (i != 0) {
      tail_->next_ = new ListNode(tmp, tail_);
      tail_ = tail_->next_;
    } else {
      head_ = new ListNode(tmp);
      tail_ = head_;
    }
    ptr_vec.push_back(tail_);
  }
  // Заполняем rand_
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next_) {
    int index = 0;
    fread(&index, sizeof(int), 1, file);
    if (index != -1)
      cur->rand_ = ptr_vec.at(index);
    else
      cur->rand_ = nullptr;
  }
}

void List::printList() {
  for (ListNode* cur = head_; cur != nullptr; cur = cur->next_) {
    std::cout << "cur=" << cur->data;
    std::string tmp;
    if (cur->prev_)
      tmp = cur->prev_->data;
    else
      tmp = "null";

    std::cout << "\tprev=" << tmp;
    if (cur->rand_)
      tmp = cur->rand_->data;
    else
      tmp = "null";
    std::cout << "\trand=" << tmp << std::endl;
  }
}

void List::clear() {
  ListNode* cur = head_;
  ListNode* tmp = nullptr;

  while (cur != nullptr) {
    tmp = cur->next_;
    delete cur;
    cur = tmp;
  }
  head_ = nullptr;
  tail_ = nullptr;
  count_ = 0;
}
