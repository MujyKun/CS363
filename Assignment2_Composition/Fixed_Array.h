//==============================================================================
/**
 * @file       Fixed_Array.h
 *
 * IMPORTANT NOTE: Majority of this file was included by the professor 
 * but for this file specifically, the design was altered to inherit
 * from the Array_Base instead of the Array.

 * Majority of the comments added by the professor were removed.
 * Declaration comments made by the professor will remain.
 */
 //==============================================================================

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

#include "Array_Base.h"

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Array_Base <T>
{
public:
  /// Default constructor.
  Fixed_Array (void);

	/**
	 * Copy constructor.
	 *
	 * @param[in]      arr        Source array
	 */
  Fixed_Array (const Fixed_Array <T, N> & arr);
	
    // COMMENT You are to remove this method.
    // RESPONSE Removed.

  /**
   * Initializing constructor. Fills the contents of the 
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  Fixed_Array (T fill);

  /// Destructor.
  ~Fixed_Array (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  const Fixed_Array & operator = (const Fixed_Array <T, N> & rhs);
};

// include the inline files
#include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_
