#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <class T>
class Vector
{
private:
    T *_buffer;
    unsigned int _size;
    unsigned int _capacity;

public:
    typedef T *iterator;

    Vector();
    Vector(unsigned int size);
    ~Vector();

    unsigned int size() const;
    bool empty() const;
    void push_back(const T &value);
    void pop_back();

    T &operator[](unsigned int index);
    T &front();
    T &back();
    iterator begin();
    iterator end();
};

#endif // VECTOR_H
