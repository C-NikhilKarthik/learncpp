#include <vector.hpp>
#include <stdexcept> // for std::out_of_range
#include <algorithm> // for std::copy
#include <string>

/**
 * @brief Default constructor for Vector.
 *
 * Initializes an empty vector with no allocated storage.
 * Memory will be allocated dynamically on the first push_back().
 */
template <class T>
Vector<T>::Vector() : _buffer(nullptr), _size(0), _capacity(0) {}

/**
 * @brief Constructs a Vector with a given initial capacity.
 *
 * Allocates storage for @p size elements. The vector will be empty initially
 * (size = 0), but can grow up to @p size before reallocation is required.
 *
 * @param size Initial capacity of the vector.
 */
template <class T>
Vector<T>::Vector(unsigned int size)
    : _buffer(new T[size]),
      _size(0),
      _capacity(size) {}

/**
 * @brief Destructor.
 *
 * Releases the allocated storage used by the vector.
 */
template <class T>
Vector<T>::~Vector()
{
    delete[] _buffer;
}

/**
 * @brief Returns the number of elements in the vector.
 *
 * @return The current size of the vector.
 */
template <class T>
unsigned int Vector<T>::size() const { return _size; }

/**
 * @brief Checks whether the array is empty.
 *
 * @return true if the array contains no elements, false otherwise.
 */
template <class T>
bool Vector<T>::empty() const
{
    return _size == 0;
}

/**
 * @brief Appends an element to the end of the vector.
 *
 * If the capacity is reached, the vector doubles its capacity and copies
 * existing elements to the new storage.
 *
 * @param value The element to be added.
 */
template <class T>
void Vector<T>::push_back(const T &value)
{
    if (_capacity == 0)
    {
        _capacity = 1;
        _buffer = new T[_capacity];
    }
    else if (_size >= _capacity)
    {
        _capacity *= 2;
        T *newBuffer = new T[_capacity];
        std::copy(_buffer, _buffer + _size, newBuffer);
        delete[] _buffer;
        _buffer = newBuffer;
    }
    _buffer[_size++] = value;
}

/**
 * @brief Removes the last element from the array.
 *
 * Does not free memory; only reduces the logical size by one.
 * Undefined behavior if called on an empty array.
 */
template <class T>
void Vector<T>::pop_back()
{
    _size--;
}

/**
 * @brief Accesses the element at a given index.
 *
 * Provides unchecked read/write access to the element at position @p index.
 * If @p index is out of range (i.e. >= size()), an exception is thrown.
 *
 * @param index Position of the element to access.
 * @return Reference to the element at the given index.
 * @throws std::out_of_range if index >= size().
 */
template <class T>
T &Vector<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("index out of range");
    }
    return _buffer[index];
}

/**
 * @brief Accesses the first element.
 *
 * @return Reference to the first element.
 * @warning Undefined behavior if the array is empty.
 */
template <class T>
T &Vector<T>::front()
{
    return _buffer[0];
}

/**
 * @brief Accesses the last element.
 *
 * @return Reference to the last element.
 * @warning Undefined behavior if the array is empty.
 */
template <class T>
T &Vector<T>::back()
{
    return _buffer[_size - 1];
}

/**
 * @brief Returns an iterator to the first element.
 *
 * @return Pointer to the first element, or nullptr if empty.
 */
template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return _buffer;
}

/**
 * @brief Returns an iterator past the last element.
 *
 * @return Pointer one past the last element.
 */
template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return _buffer + size();
}

// -------------------------------
// Explicit instantiations
// -------------------------------
template class Vector<int>;
template class Vector<double>;
template class Vector<char>;
template class Vector<std::string>;
