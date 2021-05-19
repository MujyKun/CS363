#include "Array.h"


template <typename T>
Array <T> ::Array(void)
    :cur_size_(0),
    max_size_(0)
{
    // parent default constructor is called.
}

template <typename T>
Array <T> ::Array(size_t length)
    :cur_size_(length),
    max_size_(length),
    Array_Base<T>(length)
{
}

template<typename T>
Array<T>::Array(size_t length, T fill)
    :cur_size_(length),
    max_size_(length),
    Array_Base<T>(length, fill)
{
}

template<typename T>
Array<T>::Array(const Array<T>& arr)
    :cur_size_(arr.cur_size_),
    max_size_(arr.max_size_),
    Array_Base<T>(arr.max_size_)
{
    // copy data of the passed in array.
    *this = arr;
}

template<typename T>
Array<T>::~Array(void)
{
    // parent destructor is called.
}

template <typename T>
const Array<T>& Array<T>::operator = (const Array<T>& rhs)
{
    if (this != &rhs) {
        Array_Base<T>::operator=(rhs);
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
    }
    return *this;
}

template <typename T>
void Array<T>::resize(size_t new_size)
{
    // cases to do nothing
    if (new_size == cur_size_) {
        return;
    }

    // change current size of array if it's a value less than max size.
    if (max_size_ >= new_size) {
        cur_size_ = new_size;
    }

    if (new_size > max_size_) {
        // increase the array size.
        copy_and_replace_existing_data(new_size);
    }
}

template <typename T>
void Array<T>::shrink(void)
{
    if (cur_size_ == 0) {
        *this = Array<T>();
    }
    else {
        *this = slice(0);
    }
}

template <typename T>
Array<T> Array<T>::slice(size_t begin) const
{
    return slice(begin, cur_size_);
}

template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end) const
{
    if (begin == 0 && end == 0) {
        // equivalent of returning an empty array 
        return Array<T>(end);
    }
    // raise error if the begin or end input do not exist
    this->get(begin);
    this->get(end-1);

    Array<T> copied_array = Array<T>(end - begin);
    size_t new_array_index = 0;
    for (size_t i = begin; i < end; i++) {
        copied_array[new_array_index] = (*this)[i];
        new_array_index++;
    }
    return copied_array;
}

template <typename T>
void Array<T>::copy_and_replace_existing_data(size_t length) {
    // this method is always called when the length is greater than the maximum size
    // of the current array.

    Array temp_arr = Array<T>(length);
    // temp_arr.fill(0);

    // copy data
    for (size_t i = 0; i < max_size_; i++) {
        // expected IDE buffer overrun is invalid because it is filtered.
        // we do not use the get method to properly retrieve ghosted elements
        // without causing an out of range error
        temp_arr[i] = (*this)[i];
    }

    // replace the current array with an array that allocated space.
    *this = temp_arr;

    cur_size_ = length;
    if (cur_size_ > max_size_) {
        max_size_ = cur_size_;
    }

}
