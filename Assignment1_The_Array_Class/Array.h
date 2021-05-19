//==============================================================================
/**
 * @file       Array.h
 *
 * IMPORTANT NOTE: Majority of this file was included by the professor 
 * in order to follow the intended design.
 * Majority of the comments added by the professor were removed.
 * Declaration comments made by the professor will remain.
 */
 //==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include <iostream>         // for cout.
#include <stdexcept>        // for out_of_range exception.


/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
class Array
{
public:
    /// Default constructor.
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
    Array(size_t length, char fill);

    /**
     * Copy constructor
     *
     * @param[in]     arr         The source array.
     */
    Array(const Array& arr);

    /// Destructor.
    ~Array(void);

    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    const Array& operator = (const Array& rhs);

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

    /**
     * Get the character at the specified index. If the index is not
     * within the range of the array, then std::out_of_range exception
     * is thrown.
     *
     * @param[in]       index               Zero-based location
     * @return          Character at \index
     * @exception       std::out_of_range   Invalid \a index value
     */
    char& operator [] (size_t index);

    /**
     * @overload
     *
     * The returned character is not modifiable.
     */
    const char& operator [] (size_t index) const;

    /**
     * Get the character at the specified index. If the \a index is not within
     * the range of the array, then std::out_of_range exception is thrown.
     *
     * @param[in]       index                 Zero-based location
     * @return          Character at \index
     * @exception       std::out_of_range     Invalid index value
     */
    char get(size_t index) const;

    /**
     * Set the character at the specified \a index. If the \a index is not
     * within range of the array, then std::out_of_range exception is
     * thrown.
     *
     * @param[in]       index                 Zero-based location
     * @param[in]       value                 New value for character
     * @exception       std::out_of_range     Invalid \a index value
     */
    void set(size_t index, char value);

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
     * Locate the specified character in the array. The index of the first
     * occurrence of the character is returned. If the character is not
     * found in the array, then -1 is returned.
     *
     * @param[in]        ch        Character to search for
     * @return           Index value of the character
     * @retval           -1        Character not found
     */
    int find(char ch) const;

    /**
     * @overload
     *
     * This version allows you to specify the start index of the search. If
     * the start index is not within the range of the array, then the
     * std::out_of_range exception is thrown.
     *
     * @param[in]       ch                   Character to search for
     * @param[in]       start                Index to begin search
     * @return          Index value of first occurrence
     * @retval          -1                   Character not found
     * @exception       std::out_of_range    Invalid index
     */
    int find(char ch, size_t start) const;

    /**
     * Test the array for equality.
     *
     * @param[in]       rhs                  Right hand side of equal to sign
     * @retval          true                 Left side is equal to right side
     * @retval          false                Left side is not equal to right side
     */
    bool operator == (const Array& rhs) const;

    /**
     * Test the array for inequality.
     *
     * @param[in]       rhs                  Right-hand size of not equal to sign
     * @retval          true                 Left side is not equal to right side
     * @retval          false                Left size is equal to right side
     */
    bool operator != (const Array& rhs) const;

    /**
     * Fill the contents of the array.
     *
     * @param[in]       ch                   Fill character
     */
    void fill(char ch);

    /// Reverse the contents of the array such that the first element is now
    /// the last element and the last element is the first element.
    void reverse(void);

    /**
     * The slice() method returns a shallow copy of a portion of an array into
     * a new array object selected from begin to end (end not included). The original
     * array will not be modified.
     *
     * @param[in]       begin           The starting index
     * @return          A new Array object
     * @exception       std::out_of_range     Invalid index value
     */
    Array slice(size_t begin) const;

    /**
     * @overload
     *
     * @param[in]       begin           The starting index
     * @param[in]       end             The ending index
     * @return          A new Array object
     * @exception       std::out_of_range     Invalid index value
     */
    Array slice(size_t begin, size_t end) const;

private:
    //////////////////////////////////////////////////////////////////////////////
    /// DEFINE ANY HELPER METHODS HERE

    /**
     * @overload
     *
     * Get the index of the first occurring char.
     *
     * @param[in]       ch                   Character to search for
     * @param[in]       start                Index to begin search
     * @return          Index value of first occurrence
     * @retval          -1                   Character not found
     */
    int get_index_from_char(char ch, size_t start) const;

    /*
    * Initializes all data values to 0.
    * This is to be used after allocating memory to data.
    * This pointer has params to allow memory relocation when resizing.
    * Since this is technically a backend input, no out of range errors should occur.
    * @param[in]       my_data              pointer to actual data (char*) 
    * @param[in]       max_size             Maximum size of the data
    */
    void initialize_data(char* my_data, size_t max_size);

    /*
    * Method for resetting data values, equivalent to calling destructor 
    * without actually destroying the Array object.
    */
    void destroy_data();

    /*
    * Copies the current array data, deletes the current data, then allocates memory accordingly.
    * Will also set the new max size to the input value.
    * Raises an exception if the input value is out of range.
    * @param[in]       length                 Size of Array
    * @exception       std::out_of_range     Invalid index value
    */
    void copy_and_replace_existing_data(size_t length);

    /*
    * Raises an exception if the input value is out of range.
    * @param[in]       index                 Zero-based location
    * @exception       std::out_of_range     Invalid index value
    */
    void check_out_of_range(size_t index) const;
    
    /*
    * Gets the character based on the index. 
    * Raises an exception if the input value is out of range.
    * @param[in]       index                 Zero-based location
    * @return          Character at \index
    * @exception       std::out_of_range     Invalid index value
    */
    char& get_char_from_index(size_t index) const;

    // If the developer is using Visual Studio 2019, set this to true for debugging.
    // This allows data to be initialized to 0 (AKA NULL) appropriately as 
    // Visual Studio 2019 uses a special unicode character instead. 
    // If valgrind report gives errors on uninitialised data, set this to true.
    bool using_visual_studio_or_valgrind_errors = true;

    //////////////////////////////////////////////////////////////////////////////

    /// Pointer to the actual data.
    char* data_;

    /// Current size of the array. (Slots being used from the Maximum Size)
    size_t cur_size_;

    /// Maximum size of the array.
    size_t max_size_;

};

#include "Array.inl"

#endif   // !defined _ARRAY_H_
