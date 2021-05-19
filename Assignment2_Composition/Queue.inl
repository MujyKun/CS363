//==============================================================================
/**
 * @file       Queue.inl
 *
 * IMPORTANT NOTE: This file is not included in the assignment by the professor.
 */
 //==============================================================================

//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
	return size_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return size_ == 0;
}

//
// front
//
template <typename T>
inline
T Queue <T>::front(void) const
{
	check_queue_empty();
	return arr_[front_of_queue];
}