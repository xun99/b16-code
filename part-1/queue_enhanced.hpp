#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        // WRITE YOUR CODE HERE
        return this->_storage[this->_tail]
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        // WRITE YOUR CODE HERE
        return this->_storage[this->_tail]
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        // WRITE YOUR CODE HERE
        assert(this->_size < this->_storage.size());
        this->_size++;
        this->_storage[this->_head()] = value; 
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE
    }

    // Remove all elements from the queue
    void clear() { 
        // WRITE YOUR CODE HERE
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE
        assert(this->_size >= 0);

    }
};

#endif // __queue_enhanced__