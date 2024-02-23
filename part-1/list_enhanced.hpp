
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    // WRITE YOUR CODE HERE
    assert(node);
    if (node->next){
        node->next = std::move(node->next->next);
    }
}

#endif // __list_enhanced__