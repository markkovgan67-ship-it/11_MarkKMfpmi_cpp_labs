#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <initializer_list>

class Vector {
private:
    int* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    // Конструкторы
    Vector() = default;
    explicit Vector(size_t size);
    Vector(std::initializer_list<int> list);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    // Методы
    void Swap(Vector& other);

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    int& At(size_t index);
    const int& At(size_t index) const;

    size_t Size() const;
    size_t Capacity() const;

    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(size_t new_capacity);
};

// Оператор вывода (не член класса)
std::ostream& operator<<(std::ostream& os, const Vector& vec);

#endif // VECTOR_IMPL_H
