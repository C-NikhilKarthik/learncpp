#include <dynamic_array.hpp>
#include <cstdlib> // malloc, free

template <class T>
DynamicArray<T>::DynamicArray() : _buffer(nullptr), _size(0), _capacity(0){};

template <class T>
DynamicArray<T>::DynamicArray(unsigned int size)
    : _buffer(static_cast<T *>(calloc(size, sizeof(T)))),
      _size(0),
      _capacity(size) {}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    free(_buffer);
}

template <class T>
unsigned int DynamicArray<T>::size() const
{
    return _size;
}

template <class T>
bool DynamicArray<T>::empty() const
{
    return _size == 0;
}

template <class T>
void DynamicArray<T>::push_back(const T &value)
{
    if (_capacity == 0)
    {
        _capacity = 1;
        _buffer = static_cast<T *>(calloc(_capacity, sizeof(T)));
    }
    else if (_size >= _capacity)
    {
        _capacity *= 2;
        _buffer = static_cast<T *>(realloc(_buffer, _capacity * sizeof(T)));
    }
    _buffer[_size++] = value;
}

template <class T>
void DynamicArray<T>::pop_back()
{
    _size--;
}

template <class T>
T &DynamicArray<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("Out of Bounds");
    }

    return _buffer[index];
}

template <class T>
T &DynamicArray<T>::front()
{
    return _buffer[0];
}

template <class T>
T &DynamicArray<T>::back()
{
    return _buffer[_size - 1];
}

template <class T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin()
{
    return _buffer;
}

template <class T>
typename DynamicArray<T>::iterator DynamicArray<T>::end()
{
    return _buffer + size();
}

template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<char>;
