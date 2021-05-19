//==============================================================================
/**
 * @file       Fixed_Array.cpp
 *
 * IMPORTANT NOTE: This file was given by the professor, but did not include 
 * any logic for the methods.
 */
 //==============================================================================

//
// Fixed_Array
//

template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	:Array_Base<T>(N)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array(const Fixed_Array <T, N>& arr)
	:Array_Base<T>(N)
{
	// copy data of the passed in array.
	*this = arr;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	:Array_Base<T>(N, fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	// parent destructor takes care of it.
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (this != &rhs) {
		for (size_t i = 0; i < N; i++) {
			(*this)[i] = rhs[i];
		}
	}
	return *this;
}
