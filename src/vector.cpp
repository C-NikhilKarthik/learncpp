#include <vector.hpp>
#include <cstdlib> // malloc, free

// Constructor
template <class T>
Vector<T>::Vector() : _buffer(nullptr), _size(0), _capacity(0) {}

template <class T>
Vector<T>::Vector(unsigned int size)
    : _buffer(static_cast<T *>(calloc(size, sizeof(T)))),
      _size(0),
      _capacity(size) {}

template <class T>
T &Vector<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("index out of range");
    }
    return _buffer[index];
}

template <class T>
unsigned int Vector<T>::size() const { return _size; }

template <class T>
void Vector<T>::push_back(const T &value)
{
    if (_capacity == 0)
    {
        _capacity = 1;
        _buffer = static_cast<T *>(malloc(_capacity * sizeof(T)));
    }
    else if (_size >= _capacity)
    {
        _capacity *= 2;
        _buffer = static_cast<T *>(
            realloc(_buffer, _capacity * sizeof(T)));
    }
    _buffer[_size++] = value;
}

template <class T>
Vector<T>::~Vector()
{
    free(_buffer);
}

// -------------------------------
// Explicit instantiations
// -------------------------------
template class Vector<int>;
template class Vector<double>;
template class Vector<char>;
// add more as needed
