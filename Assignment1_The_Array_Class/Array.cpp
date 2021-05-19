//==============================================================================
/**
 * @file       Array.cpp
 *
 * IMPORTANT NOTE: This file was given by the professor, but did not include 
 * any logic for the methods.
 */
 //==============================================================================


#include "Array.h"

Array::Array(void)
    :cur_size_(0),
    max_size_(0),
    data_(new char[0])
{
    // Data should be initialized to 0 (AKA NULL) if debugging through Visual Studio 2019.
    // or receiving valgrind uninitialised data errors.
    if (using_visual_studio_or_valgrind_errors) {
        initialize_data(data_, 0);
    }
}

Array::Array(size_t length)
    :cur_size_(length),
    max_size_(length),
    data_(new char[length])
{
    // Data should be initialized to 0 (AKA NULL) if debugging through Visual Studio 2019.
    // or receiving valgrind uninitialised data errors.
    if (using_visual_studio_or_valgrind_errors) {
        initialize_data(data_, length);
    }
}

Array::Array(size_t length, char fill)
    :cur_size_(length),
    max_size_(length),
    data_(new char[length])
{
    // Data should be initialized to 0 (AKA NULL) if debugging through Visual Studio 2019.
    // or receiving valgrind uninitialised data errors.
    if (using_visual_studio_or_valgrind_errors) {
        initialize_data(data_, length);
    }
    this->fill(fill); // fill the array with the char passed in. 
}

Array::Array(const Array& array)
    :cur_size_(array.cur_size_),
    max_size_(array.max_size_),
    data_(new char[array.max_size_])
{
    // copy data of the passed in array.
    for (size_t i = 0; i < max_size_; i++) {
        data_[i] = array[i];
    }
}

Array::~Array(void)
{
    destroy_data();
}

const Array& Array::operator = (const Array& rhs)
{
    if (this != &rhs) {
        destroy_data();
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
        data_ = new char[max_size_];
        for (size_t i = 0; i < max_size_; i++) {
            data_[i] = rhs[i];
        }
    }
    return *this;
}

char& Array::operator [] (size_t index)
{
    return get_char_from_index(index);
}

const char& Array::operator [] (size_t index) const
{
    return get_char_from_index(index);
}

char Array::get(size_t index) const
{
    return get_char_from_index(index);
}

void Array::set(size_t index, char value)
{
    check_out_of_range(index);
    data_[index] = value;
}

void Array::resize(size_t new_size)
{
    // cases to do nothing
    if (new_size <= 0 || new_size == cur_size_) {
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

int Array::find(char ch) const
{
    return get_index_from_char(ch, 0);
}

int Array::find(char ch, size_t start) const
{
    check_out_of_range(start);
    return get_index_from_char(ch, start);
}

bool Array::operator == (const Array& rhs) const
{
    if (this == &rhs) {
        // self comparison
        return true;
    }

    // if the array current sizes do not match
    if (cur_size_ != rhs.cur_size_) {
        return false;
    }

    // if the data points do not match accordingly
    for (size_t i = 0; i < cur_size_; i++) {
        if (data_[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

bool Array::operator != (const Array& rhs) const
{
    return !(*this == rhs);
}

void Array::fill(char ch)
{
    for (size_t i = 0; i < cur_size_; i++){
        data_[i] = ch;
    }
}

void Array::shrink(void)
{
    // reclaim unused space.
    *this = slice(0);
}

void Array::reverse(void)
{
    // if the current size is 0 or 1, then there is nothing to reverse.
    if (cur_size_ == 0 || cur_size_ == 1) {
        return;
    }

    size_t lower_index = 0;
    size_t higher_index = cur_size_ - 1;

    bool keep_going = true;
    while (keep_going) {
        char temp_char = data_[lower_index];  // holds the char temporarily.
        data_[lower_index] = data_[higher_index];
        data_[higher_index] = temp_char;
        
        lower_index++;
        higher_index--;
        if (lower_index == higher_index || lower_index > higher_index) {
            keep_going = false;
        }
    }
}

Array Array::slice(size_t begin) const
{
    return slice(begin, cur_size_);
}

Array Array::slice(size_t begin, size_t end) const
{
    check_out_of_range(begin);  // check for issue with begin input
    check_out_of_range(end - 1);  // check for issue with end input
    Array copied_array = Array(end - begin);
    size_t new_array_index = 0;
    for (size_t i = begin; i < end; i++) {
        copied_array[new_array_index] = data_[i];
        new_array_index++;
    }
    return copied_array;
}

void Array::check_out_of_range(size_t index) const {
    if (index >= this->cur_size_ || index < 0) {
        throw std::out_of_range("Array Index is out of range.");
    }
}

char& Array::get_char_from_index(size_t index) const {
    check_out_of_range(index);
    return data_[index];
}


void Array::copy_and_replace_existing_data(size_t length) {
    char* temp_data = new char[length];
    // Data should be initialized to 0 (AKA NULL) if debugging through Visual Studio 2019.
    // or receiving valgrind uninitialised data errors.
    if (using_visual_studio_or_valgrind_errors){
        initialize_data(temp_data, length);
    }

    // copy data
    for (size_t i = 0; i < max_size_; i++) {
        // expected IDE buffer overrun is invalid because it is filtered.
        // we do not use the get method to properly retrieve ghosted elements
        // without causing an out of range error
        temp_data[i] = data_[i];
    }

    destroy_data();

    cur_size_ = length;
    if (cur_size_ > max_size_) {
        max_size_ = cur_size_;
    }

    data_ = temp_data; // pointing to temp_data 
}

void Array::destroy_data() {
    delete[] data_;
    data_ = nullptr;
}


void Array::initialize_data(char* my_data, size_t max_size) {
    for (size_t i = 0; i < max_size; i++) {
        my_data[i] = 0;
    }
}

int Array::get_index_from_char(char ch, size_t start) const {
    for (size_t i = start; i < cur_size_; i++) {
        if (data_[i] == ch) {
            return i;
        }
    }
    return -1; // no char found.
}