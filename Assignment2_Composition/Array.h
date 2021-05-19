//==============================================================================
/**
 * @file       Array.h
 *
 * IMPORTANT NOTE: Majority of this file was included by the professor 
 * in order to follow the intended design for this assignment.
 * Majority of the comments added by the professor were removed.
 * Declaration comments made by the professor will remain.
 */
 //==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include <iostream>         // for cout.
#include <stdexcept>        // for out_of_range exception.
#include "Array_Base.h"

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Array_Base <T> 
{
public:
    // default constructor 
    Array(void); 

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     */
    Array(size_t length);

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     * @param[in]      fill          Initial value for each element
     */
    Array(size_t length, T fill);

    /**
     * Copy constructor
     *
     * @param[in]     arr         The source array.
     */
    Array(const Array<T>& arr);

    /// Destructor.
    ~Array(void);

    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    const Array<T>& operator = (const Array<T>& rhs);

     /**
     * Set a new size for the array. If \a new_size is less than the current
     * size, then the array is truncated. If \a new_size if greater then the
     * current size, then the array is made larger and the new elements are
     * not initialized to anything. If \a new_size is the same as the current
     * size, then nothing happens.
     *
     * The array's original contents are preserved regardless of whether the
     * array's size is either increased or decreased.
     *
     * @param[in]       new_size              New size of the array
     */
    void resize(size_t new_size);


    /// Shrink the array to reclaim unused space.
    void shrink();

    /**
     * The slice() method returns a shallow copy of a portion of an array into
     * a new array object selected from begin to end (end not included). The original
     * array will not be modified.
     *
     * @param[in]       begin           The starting index
     * @return          A new Array object
     * @exception       std::out_of_range     Invalid index value
     */
    Array<T> slice(size_t begin) const;

    /**
     * @overload
     *
     * @param[in]       begin           The starting index
     * @param[in]       end             The ending index
     * @return          A new Array object
     * @exception       std::out_of_range     Invalid index value
     */
    Array<T> slice(size_t begin, size_t end) const;

    /**
     * Retrieve the current size of the array.
     *
     * @return          The current size
     */
    size_t size(void) const;

    /**
     * Retrieve the maximum size of the array.
     *
     * @return          The maximum size
     */
    size_t max_size(void) const;

private:
    /*
    * Copies the current array data, deletes the current data, then allocates memory accordingly.
    * Will also set the new max size to the input value.
    * Raises an exception if the input value is out of range.
    * @param[in]       length                 Size of Array
    * @exception       std::out_of_range     Invalid index value
    */
    void copy_and_replace_existing_data(size_t length);

    /// Current size of the array. (Slots being used from the Maximum Size)
    size_t cur_size_;

    /// Maximum size of the array.
    size_t max_size_;
};

#include "Array.inl"

// include the source file since template class
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
