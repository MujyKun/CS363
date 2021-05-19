//==============================================================================
/**
 * @file       Queue.h
 *
 * IMPORTANT NOTE: This file is not included in the assignment by the professor.
 */
 //==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"  // Using Array to build Queue

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Push a new \a element onto the queue. The element is inserted
   * after all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Get And Remove the element in the front of the queue. 
   *
   * @return         Element in the front of the queue.
   * @exception      empty_exception    The queue is empty.
   */
  T dequeue (void);

  /**
   * Get the first element in the queue. If there are no elements 
   * on the queue, then the queue_is_empty exception is thrown.
   *
   * @return         Element in the front of the queue.
   * @exception      empty_exception    The queue is empty
   */
  T front (void) const;

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

  // Shrink the Queue
  void shrink(void);

private:

    /*
    * Raises an exception if the queue is empty
    * @exception      empty_exception    The queue is empty
    */
    void check_queue_empty() const;

    // PROF COMMENT
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.
    
    // RESPONSE Allocated the array on the stack instead.

    // add member variable here
    Array<T> arr_;  // array to structure the queue
    size_t front_of_queue; // shows what index is the front of the queue. useful for dequeuing
    size_t size_; // size of the queue
    size_t amt_to_increment_arr = 5; // the amount to allocate to the array when resizing.

};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
