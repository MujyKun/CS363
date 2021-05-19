//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	check_stack_empty();
	return arr_[size_ - 1];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return size_ == 0;
}
