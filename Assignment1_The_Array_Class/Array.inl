//==============================================================================
/**
 * @file       Array.inl
 *
 * IMPORTANT NOTE: This file was given by the professor, but did not include 
 * any logic for the methods.
 */
 //==============================================================================

inline
size_t Array::size(void) const
{
    return this->cur_size_;
}

inline
size_t Array::max_size(void) const
{
    return this->max_size_;
}
