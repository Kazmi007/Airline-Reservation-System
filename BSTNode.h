#ifndef BSTNODE_H
#define BSTNODE_H

#include <ostream>

template<class T>
class BSTNode {  // Class definition for the BST nodes.
public:
    T data;  // Public data members give easy access to BST.h 
    BSTNode<T> *left;
    BSTNode<T> *right;

    BSTNode() {  // Default constructor.
        this->left = NULL;
        this->right = NULL;
    }

    BSTNode(T data, BSTNode<T> *left, BSTNode<T> *right) {  // Custom constructor.
        this->data = data;
        this->left = left;
        this->right = right;
    }

    friend std::ostream &operator<<(std::ostream &os, const BSTNode &node) {  // Overloaded << operator to print node to output stream.
        os << node.data;
        return os;
    }
};

#endif //BSTNODE_H
