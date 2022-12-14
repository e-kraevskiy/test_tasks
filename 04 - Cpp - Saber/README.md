#### ФИО - Краевский Евгений Игоревич
#### Дата выполнения - 07.09.2022
#### Время выполенения - 8-9 часов

## Первое задание:

--- 
Напишите функцию, которая принимает на вход знаковое целое число и печатает его двоичное
представление, не используя библиотечных классов или функций.
---

```cpp
template <typename T>
void printIntBinary(T num) {
  int shifts_count = sizeof(T) * 8 - 2;
  T mask = static_cast<T>(1);
  mask <<= shifts_count;
  // Знаковый бит
  if (num < 0)
    std::cout << '1';
  else
    std::cout << '0';
  while (mask) {
    if (num & mask)
      std::cout << '1';
    else
      std::cout << '0';
    mask >>= 1;
  }
  std::cout << std::endl;
}
```
### Принцип работы:
Для получения каждого бита используется маска, состоящая из одного поднятого бита.
В начале это маска с поднятым старшим битом числа. Для ее получения необходимо сдвинуть единицу на количество бит, занимаемое числом минус два (первая единица - т.к. начинаем с 1 а не 0, вторая единица - чтобы не учитывать знаковый бит, который обрабатывается отдельно).
После получения текущего бита маска сдвигается на бит вправо, до тех пор, пока в маске есть биты (маска > 0).

## Второе задание:
--- 
Напишите функцию, удаляющую последовательно дублирующиеся символы в строке:
---
```cpp
void RemoveDups(char* str);
```
---

```cpp
void RemoveDups(char* str) {
  char* cur = str;
  char* last_unique = str;
  while (*cur != '\0') {
    if (*cur != *last_unique) *(++last_unique) = *cur;
    ++cur;
  }
  *(++last_unique) = '\0';
}
```

### Принцип работы: 

Два указателя (cur и last_unique)

Первым идем по всей строке, второй указывает на последний уникальный элемент. 
Когда `*cur` не совпадает с `*last_unique`, то `last_unique` сдвигается на один элемент и на его место заносится новый уникальный символ.
  
## Третье задание:
--- 
Реализуйте функции сериализации и десериализации двусвязного списка в бинарном формате в
файл. Алгоритмическая сложность решения должна быть меньше квадратичной. 
---
Интерфейс:
```cpp
struct ListNode {
  ListNode* prev;
  ListNode* next;
  ListNode* rand;  // указатель на произвольный элемент данного списка, либо NULL
  std::string data;
};

class List {
 public:
  void serialize(FILE* file);   // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
  void deserialize(FILE* file); // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

 private:
  ListNode* head;
  ListNode* tail;
  int count;
};
```
---

Реализация:
[.h file](https://github.com/e-kraevskiy/test_tasks/blob/develop/04%20-%20Cpp%20-%20Saber/list.h)
[.cpp file](https://github.com/e-kraevskiy/test_tasks/blob/develop/04%20-%20Cpp%20-%20Saber/list.cpp)

Сериализация:
1. Сначала записывается количество узлов списка.
2. Записывается размер data и сама data. 
3. Пралельное с п. 2 меняем prev у каждого узла на новый узел, data которого содержит индекс текущего узла.
4. Идем по списку, записываем в файл индекс узла, на который указвыает rand. Этот индекс лежит в cur->rand->prev->data (см. 3 пункт)
5. Проходим по списку и восстанавливаем prev для каждой ноды.

Проход по списку осуществляется 3 раза (пункты 2-3, 4, 5).
Следоватлеьно, алгоритмическая сложность - O(n).

Десериализация:
1. Читаем колчисетво узлов.
2. Получаем размер data и саму data для каждого узла, после чего добавляем в список соответствующий узел.
3. Паралельно с п.2 заполняем вектор указателей на ноды.
4. Считываем индексы rand узлов, и заполняем rand у каждого узла значем из вектора указателей.

Два прохода по списку (пункты 2-3 и 4), поэтому сложность также - O(n).
