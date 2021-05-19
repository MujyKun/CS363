//
// Queue
//

template <typename T>
Queue <T>::Queue (void)
	:arr_ (Array<T>()),
	size_(0),
	front_of_queue(0)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue& queue)
	:arr_(Array<T>()),
	size_(0),
	front_of_queue(0)
{
	*this = queue;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue(void)
{
	// parent destructor takes care of everything.
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	// if there are not enough slots, resize the array.
	if (arr_.size() <= size_) {
		arr_.resize(size_ + amt_to_increment_arr);
	}
	arr_[size_] = element;
	size_++;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue(void)
{
	// make sure to call front() at the start of the method as we alter data.
	T value_in_front = front();  // will also raise an exception if empty.

	// case for if the element being removed is the last in the queue.
	if (size_ == 1) {
		clear();  
	}
	else {
		front_of_queue++;
		size_--;
	}
	return value_in_front;
}

//
// operator =
//
template <typename T>
const Queue <T>& Queue <T>::operator = (const Queue& rhs)
{
	if (this != &rhs) {
		clear();
		size_t src_array_size = rhs.size();
		arr_.resize(src_array_size);  // allocate in advance.

		if (!rhs.is_empty()) {
			// unlike the stack, we start incrementing the queue from the 0th index.
			for (size_t i = 0; i < src_array_size; i++) {
				enqueue(rhs.arr_[i + rhs.front_of_queue]);
			}
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{

	// this is equivalent to creating an empty array.
	arr_.resize(0);
	
	size_ = 0;
	front_of_queue = 0;
}

template <typename T>
void Queue <T>::shrink(void)
{
	arr_.shrink();
}

//
// raise exception if the queue is empty
//
template <typename T>
void Queue <T>::check_queue_empty() const {
	if (size_ == 0) {
		throw empty_exception();
	}
}
