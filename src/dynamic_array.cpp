#include <dynamic_array.hpp>
#include <cstdlib>   // malloc, free
#include <stdexcept> // std::out_of_range

/**
 * @brief Default constructor.
 *
 * Creates an empty DynamicArray with no allocated storage.
 */
template <class T>
DynamicArray<T>::DynamicArray() : _buffer(nullptr), _size(0), _capacity(0) {}

/**
 * @brief Constructs a DynamicArray with a given capacity.
 *
 * Allocates storage for @p size elements. The array starts empty
 * (size = 0), but can grow up to @p size before reallocation is required.
 *
 * @param size Initial capacity of the array.
 */
template <class T>
DynamicArray<T>::DynamicArray(unsigned int size)
    : _buffer(static_cast<T *>(calloc(size, sizeof(T)))),
      _size(0),
      _capacity(size) {}

/**
 * @brief Destructor.
 *
 * Frees the allocated storage.
 */
template <class T>
DynamicArray<T>::~DynamicArray()
{
    free(_buffer);
}

/**
 * @brief Returns the number of elements currently stored.
 *
 * @return The current size of the array.
 */
template <class T>
unsigned int DynamicArray<T>::size() const
{
    return _size;
}

/**
 * @brief Checks whether the array is empty.
 *
 * @return true if the array contains no elements, false otherwise.
 */
template <class T>
bool DynamicArray<T>::empty() const
{
    return _size == 0;
}

/**
 * @brief Adds a new element to the end of the array.
 *
 * If the capacity is exceeded, the array doubles its capacity and reallocates
 * storage to fit the new elements.
 *
 * @param value The element to add.
 */
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

/**
 * @brief Removes the last element from the array.
 *
 * Does not free memory; only reduces the logical size by one.
 * Undefined behavior if called on an empty array.
 */
template <class T>
void DynamicArray<T>::pop_back()
{
    _size--;
}

/**
 * @brief Provides access to the element at a given index.
 *
 * @param index Position of the element to access.
 * @return Reference to the element at the given index.
 * @throws std::out_of_range if index >= size().
 */
template <class T>
T &DynamicArray<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("Out of Bounds");
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
T &DynamicArray<T>::front()
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
T &DynamicArray<T>::back()
{
    return _buffer[_size - 1];
}

/**
 * @brief Returns an iterator to the first element.
 *
 * @return Pointer to the first element, or nullptr if empty.
 */
template <class T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin()
{
    return _buffer;
}

/**
 * @brief Returns an iterator past the last element.
 *
 * @return Pointer one past the last element.
 */
template <class T>
typename DynamicArray<T>::iterator DynamicArray<T>::end()
{
    return _buffer + size();
}

// -------------------------------
// Explicit instantiations
// -------------------------------
template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<char>;
