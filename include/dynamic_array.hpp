#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stdexcept>

template <class T>
class DynamicArray
{
private:
    T *_buffer;
    unsigned int _size;
    unsigned int _capacity;

public:
    typedef T *iterator;

    DynamicArray();
    DynamicArray(unsigned int size);
    ~DynamicArray();

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

#endif