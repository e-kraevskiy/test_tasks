#ifndef CIRCULAR_BUFFER_LIST_H
#define CIRCULAR_BUFFER_LIST_H

#include <array>
#include <cstdint>
#include <forward_list>
#include <iostream>
//#include <iterator>
#include <optional>

template <class T, size_t max_size>
class CircularBufferList {
 public:
  //  explicit CircularBufferList() = default;
  explicit CircularBufferList();

  void write(T item) noexcept;
  std::optional<T> read() noexcept;
  /// \brief Прочитать без уменьшения размера буфера
  std::optional<T> get() noexcept;
  void reset() noexcept;
  bool empty() const noexcept { return (!is_full_ && (tail_ == head_)); }
  bool full() const noexcept { return is_full_; }

  /// \brief Максимальный размер буфера
  size_t capacity() const noexcept { return max_size; }
  /// \brief Текущий размер буфера
  size_t size() const noexcept;

 private:
  /// Индекс записи новых данных
  std::forward_list<T> list_ = std::forward_list<T>(max_size);
  typename std::forward_list<T>::iterator head_ = list_.begin();
  typename std::forward_list<T>::iterator tail_ = list_.begin();
  typename std::forward_list<T>::iterator end_ = list_.end();
  bool is_full_ = false;
  size_t size_ = 0;
};

template <class T, size_t max_size>
CircularBufferList<T, max_size>::CircularBufferList() {
  head_ = list_.begin();
  tail_ = list_.begin();
  end_ = list_.begin();
  for (int i = 0; i < max_size - 1; ++i) {
    ++end_;
  }
  //  tail_ = head_;
  //  end_ = list_.end();
  //  head_ = buffer_[0];
  //  tail_ = buffer_[0];
}

template <class T, size_t max_size>
void CircularBufferList<T, max_size>::write(T item) noexcept {
  *tail_ = item;
  if (is_full_) {
    if (head_ == end_)
      head_ = list_.begin();
    else
      ++head_;
    //    head_ = (head_ + 1) % max_size;
  } else
    ++size_;
  if (tail_ == end_)
    tail_ = list_.begin();
  else
    ++tail_;
  //  tail_ = tail_->next;
  //  tail_ = (tail_ + 1) % max_size;
  is_full_ = tail_ == head_;
}

template <class T, size_t max_size>
std::optional<T> CircularBufferList<T, max_size>::read() noexcept {
  if (empty()) return std::nullopt;
  T val = *head_;
  is_full_ = false;
  if (head_ == end_)
    head_ = list_.begin();
  else
    ++head_;
  --size_;
  //  head_ = (head_ + 1) % max_size;
  return val;
}

template <class T, size_t max_size>
std::optional<T> CircularBufferList<T, max_size>::get() noexcept {
  if (empty()) return std::nullopt;
  return *head_;
}

template <class T, size_t max_size>
void CircularBufferList<T, max_size>::reset() noexcept {
  size_ = 0;
  tail_ = head_;
  is_full_ = false;
}

template <class T, size_t max_size>
size_t CircularBufferList<T, max_size>::size() const noexcept {
  return size_;
}

#endif  // CIRCULAR_BUFFER_LIST_H
