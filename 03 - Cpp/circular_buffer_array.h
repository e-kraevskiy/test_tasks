#ifndef CIRCULAR_BUFFER_ARRAY_H
#define CIRCULAR_BUFFER_ARRAY_H

#include <optional>

template <class T, size_t max_size>
class CircularBufferArray {
 public:
  explicit CircularBufferArray() = default;

  void write(T item) noexcept;
  std::optional<T> read() noexcept;
  std::optional<T> get() noexcept;
  void reset() noexcept;
  bool empty() const noexcept { return (!is_full_ && (tail_ == head_)); }
  bool full() const noexcept { return is_full_; }

  /// \brief Максимальный размер буфера
  size_t capacity() const noexcept { return max_size; }
  /// \brief Текущий размер буфера
  size_t size() const noexcept;

 private:
  T buffer_[max_size];
  size_t tail_ = 0;  /// Индекс записи новых данных
  size_t head_ = 0;  /// Индекс чтения данных
  bool is_full_ = false;
};

template <class T, size_t max_size>
void CircularBufferArray<T, max_size>::write(T item) noexcept {
  buffer_[tail_] = item;
  if (is_full_) {
    head_ = (head_ + 1) % max_size;
  }
  tail_ = (tail_ + 1) % max_size;
  is_full_ = tail_ == head_;
}

template <class T, size_t max_size>
std::optional<T> CircularBufferArray<T, max_size>::read() noexcept {
  if (empty()) return std::nullopt;
  T val = buffer_[head_];
  is_full_ = false;
  head_ = (head_ + 1) % max_size;
  return val;
}

template <class T, size_t max_size>
std::optional<T> CircularBufferArray<T, max_size>::get() noexcept {
  if (empty()) return std::nullopt;
  return buffer_[head_];
}

template <class T, size_t max_size>
void CircularBufferArray<T, max_size>::reset() noexcept {
  tail_ = head_;
  is_full_ = false;
}

template <class T, size_t max_size>
size_t CircularBufferArray<T, max_size>::size() const noexcept {
  size_t size = max_size;
  if (!is_full_) {
    if (tail_ >= head_) {
      size = tail_ - head_;
    } else {
      size = max_size + tail_ - head_;
    }
  }
  return size;
}

#endif  // CIRCULAR_BUFFER_ARRAY_H
