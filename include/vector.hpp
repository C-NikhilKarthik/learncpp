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
    Vector();
    Vector(unsigned int size);
    T &operator[](unsigned int index);
    unsigned int size() const;
    void push_back(const T &value);
    ~Vector();
};

#endif // VECTOR_H
