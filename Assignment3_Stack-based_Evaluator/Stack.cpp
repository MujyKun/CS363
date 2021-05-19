//
// Stack
//

template <typename T>
Stack <T>::Stack (void)
	:arr_ (Array<T>()),
	size_(0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	:arr_(Array<T>()),
	size_(0)
{
	*this = stack;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	// parent destructor takes care of it.
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	// if there are not enough slots, resize the array.
	if (arr_.size() <= size_) {
		arr_.resize(size_ + amt_to_increment_arr);
	}

	arr_[size_] = element;
	size_++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	check_stack_empty();
	// the top object doesn't need to be removed 
	// as it will be overwritten 
	// therefore, we only need to decrement the stack size
	size_--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this != &rhs) {
		// we can not simply slice the array class because 
		// we are storing our array on the heap.

		clear();
		size_t src_array_size = rhs.size();
		arr_.resize(src_array_size);  // allocate in advance.

		if (!rhs.is_empty()) {
			for (size_t i = src_array_size - 1; i >= 0; i--) {
				// push(rhs.arr_->get(i));
				push(rhs.arr_[i]);

				// size_t does not have negative numbers, meaning this for loop
				// goes on for an infinite amount of time. check for 0 and break.
				if (i == 0) {
					break;
				}
			}
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	// the objects do not need to be removed 
	// as it will be overwritten 
	// therefore, we only need to reduce the stack size
	// however, for memory allocation purposes, 
	// we will also resize the array to 0 and shrink it.

	// this is equivalent to creating an empty array.
	arr_.resize(0);
    
    // PROF COMMENT
    // COMMENT There is no need to shrink the array since you
    // will just request the space later. If you want to shrink
    // the array, then you should expose a shrink() method on the
    // Stack, which delegates its call to the array.

	// RESPONSE The reason for shrinking the array is for scalability.
	// In the case you have a billion elements in the queue and you 
	// do not shrink the array after clearing it, you have a lot of unneeded 
	// memory allocated.
	// However, I'll make it optional and expose a shrink method and not make it automatic.
	size_ = 0;
}

template <typename T>
void Stack <T>::shrink(void)
{
	arr_.shrink();
}

//
// raise exception if the stack is empty
//
template <typename T>
void Stack <T>::check_stack_empty() const {
	if (size_ == 0) {
		throw empty_exception();
	}
}
