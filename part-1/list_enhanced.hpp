
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    // WRITE YOUR CODE HERE


    assert(node);
    if (node->next){
        std::unique_ptr<Node<T>>& nextNodePtr = node->next; // Get a reference to the unique_ptr holding the next node
        std::unique_ptr<Node<T>> removedNode = std::move(nextNodePtr); // Move ownership of the next node to a local unique_ptr
        node->next = std::move(removedNode->next); // Update the next pointer of the given node to skip over the removed node
        // or we can use 
        // node->next = std::move(node->next->next);
    }
}

#endif // __list_enhanced__