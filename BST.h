#ifndef BST_H
#define BST_H

#include <iostream>

#include "BSTNode.h"

enum TraversalPlan {preorder, inorder, postorder};

template<class T>
class BST {  // Class definition for the BST itself.
public: 
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot() const;
    bool isEmpty() const;
    bool contains(BSTNode<T> *node) const;

    void insert(const T &data);

    void remove(const T &data);
    void removeAllNodes();

    BSTNode<T> *search(const T &data) const;
    BSTNode<T> *getSuccessor(BSTNode<T> *node, TraversalPlan tp) const;

    void print(TraversalPlan tp=inorder) const;

    BST<T> &operator=(const BST<T> &rhs);

private:  // Utility methods.
    void print(BSTNode<T> *node, TraversalPlan tp) const;
    void construct(BSTNode<T> *&r, BSTNode<T> *ref);
    void destruct(BSTNode<T> *&r);
    bool contains(BSTNode<T> *r, BSTNode<T> *node) const;
    void insert(BSTNode<T> *&r, const T &data);
    void remove(BSTNode<T> *&r, const T &data);
    BSTNode<T> *search(BSTNode<T> *r, const T &data) const;
    BSTNode<T> *inordSucc(BSTNode<T> *r, BSTNode<T> *node) const;
    BSTNode<T> *minNode(BSTNode<T> *r) const;
    BSTNode<T> *preordSucc(BSTNode<T> *r, BSTNode<T> *node) const;
    BSTNode<T> *postordSucc(BSTNode<T> *r, BSTNode<T> *node) const;

private: 
    BSTNode<T> *root;
};

#endif //BST_H

template<class T>
BST<T>::BST() {  // Default Constructor.
    root = NULL;
}

template<class T>
BST<T>::BST(const BST<T> &obj) {  // Copy Constructor.
    construct(root, obj.root);
}

template<class T>
BST<T>::~BST() {  // Destructor.
    destruct(root);
}

template<class T>
BSTNode<T> *BST<T>::getRoot() const {  // Returns root node of the BST.
    return root;
}

template<class T>
bool BST<T>::isEmpty() const {  // Returns whether the BST is empty. 
    return root == NULL;
}

template<class T>
bool BST<T>::contains(BSTNode<T> *node) const {  // Returns whether the BST contains the given node.
    return contains(root, node);
}

template<class T>
void BST<T>::insert(const T &data) {  // Inserts a new node to the BST with the given data value.
    insert(root, data);
}

template<class T>
void BST<T>::remove(const T &data) {  // Removes the node with the given data value.
    remove(root, data);
}

template<class T>
void BST<T>::removeAllNodes() {  // Removes all the nodes in the BST.
    this->~BST();
    root = NULL;
}

template<class T>
BSTNode<T> *BST<T>::search(const T &data) const {  // Returns the node with the given data value in the BST.
    return search(root, data);
}

template<class T>
BSTNode<T> *BST<T>::getSuccessor(BSTNode<T> *node, TraversalPlan tp) const {  // Returns the successor of the given node with respect to the given traversal plan.
    if (tp == inorder) 
        return inordSucc(root, node);
    else if (tp == preorder) {
        if (node->left)
            return node->left;
        if (node->right)
            return node->right;
        if (node == root)
            return NULL;
        return preordSucc(root, node);
    } 
    else if (tp == postorder)
        return postordSucc(root, node);
}

template<class T>
void BST<T>::print(TraversalPlan tp) const {  // Prints the BST with the according to the given traversal plan.

    if (tp == inorder) {
        // check if the tree is empty?
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_inorder{}" << std::endl;
            return;
        }

        // the tree is not empty.

        // recursively output the tree.
        std::cout << "BST_inorder{" << std::endl;
        print(root, inorder);
        std::cout << std::endl << "}" << std::endl;
    } else if (tp == preorder) {
        if (isEmpty()) {
            std::cout << "BST_preorder{}" << std::endl;
            return;
        }
        std::cout << "BST_preorder{" << std::endl;
        print(root, preorder);
        std::cout << std::endl << "}" << std::endl;
    } else if (tp == postorder) {
        if (isEmpty()) {
            std::cout << "BST_postorder{}" << std::endl;
            return;
        }
        std::cout << "BST_postorder{" << std::endl;
        print(root, postorder);
        std::cout << std::endl << "}" << std::endl;
    }
}

template<class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {  // Overloaded assignment operator.
    if (this->root == rhs.root) 
        return *this;
    destruct(root);
    construct(root, rhs.root);
    return *this;
}

template<class T>
void BST<T>::print(BSTNode<T> *node, TraversalPlan tp) const {   // Print helper.

    // check if the node is NULL?
    if (node == NULL)
        return;

    if (tp == inorder) {
        // first, output left subtree and comma (if needed).
        print(node->left, inorder);
        if (node->left) {
            std::cout << "," << std::endl;
        }

        // then, output the node.
        std::cout << "\t" << node->data;

        // finally, output comma (if needed) and the right subtree.
        if (node->right) {
            std::cout << "," << std::endl;
        }
        print(node->right, inorder);
    } else if (tp == preorder) {
        std::cout << "\t" << node->data;
        if (node->left) {
            std::cout << "," << std::endl;
        }
        print(node->left, preorder);
        if (node->right) {
            std::cout << "," << std::endl;
        }
        print(node->right, preorder);
    } else if (tp == postorder) {
        print(node->left, postorder);
        if (node->left) {
            std::cout << "," << std::endl;
        }
        print(node->right, postorder);
        if (node->right) {
            std::cout << "," << std::endl;
        }
        std::cout << "\t" << node->data;
    }
}


template<class T>
void BST<T>::construct(BSTNode<T> *&r, BSTNode<T> *ref) {  // Utility to construct a BST with the given root node and reference nodes.
    if (!ref)
        return;
    r = new BSTNode<T>(ref->data, NULL, NULL);
    construct(r->left, ref->left);
    construct(r->right, ref->right);
}

template<class T>
void BST<T>::destruct(BSTNode<T> *&r) {  // Utility to destruct a BST with the given root node. 
    if (!r)
        return;
    destruct(r->left);
    destruct(r->right);
    delete r;
    r = NULL;
}

template<class T>
bool BST<T>::contains(BSTNode<T> *r, BSTNode<T> *node) const {  // Utility to check whether a BST contains a given node.
    if (!r)
        return false;
    if (r == node)
        return true;
    if (node->data < r->data)
        contains(r->left, node);
    else if (node->data > r->data)
        contains(r->right, node);
}

template<class T>
void BST<T>::insert(BSTNode<T> *&r, const T &data) {  // Utility to insert a new node to the BST with the given data value.
    if (!r)
        r = new BSTNode<T>(data, NULL, NULL);
    if (data < r->data)
        insert(r->left, data);
    if (data > r->data)
        insert(r->right, data);
}

template<class T>
void BST<T>::remove(BSTNode<T> *&r, const T &data) {  // Utility to remove the node with the given data value from a BST.
    if (!r)
        return;
    else if (data < r->data)
        remove(r->left, data);
    else if (data > r->data)
        remove(r->right, data);
    else {
        if (r->left && r->right) {
            r->data = minNode(r->right)->data;
            remove(r->right, r->data);
        }
        else {
            BSTNode<T> *node = r;
            r = (r->left != NULL) ? r->left : r->right;
            delete node; 
        }
    }  
}

template<class T>
BSTNode<T> *BST<T>::search(BSTNode<T> *r, const T &data) const {  // Utility to return the node with the given data value in a BST.
    if (!r)
        return NULL;
    if (r->data == data)
        return r;
    if (data < r->data)
        search(r->left, data);
    else if (data > r->data)
        search(r->right, data);
}

template<class T>
BSTNode<T> *BST<T>::inordSucc(BSTNode<T> *r, BSTNode<T> *node) const {  // Utility to return the in-order successor of a given node in a BST.
    if (node->right) 
        return minNode(node->right);
    BSTNode<T> *succ = NULL;
    while (r) {
        if (node->data < r->data) {
            succ = r;
            r =  r->left;
        }
        else if (node->data > r->data) 
            r = r->right;
        else 
            break;
    }
    return succ;
}

template<class T>
BSTNode<T> *BST<T>::minNode(BSTNode<T> *r) const {  // Utility to return the node with the minimum data value.
    BSTNode<T> *curr = r;
    while (curr->left) 
        curr = curr->left;
    return curr;
}

template<class T>
BSTNode<T> *BST<T>::preordSucc(BSTNode<T> *r, BSTNode<T> *node) const {  // Utility to return the pre-order successor of a given node in a BST.
    BSTNode<T> *parent = r;
    while (!(node == parent->left || node == parent->right)) {
        if (node->data < parent->data) 
            parent = parent->left;
        else 
            parent = parent->right;
    }
    if (node == parent->left) {
        if (parent->right)
            return parent->right;
        else if (parent == r)
            return NULL;
        else 
            return preordSucc(r, parent);
    }
    else {
        if (parent == r)
            return NULL;
        else    
            return preordSucc(r, parent);
    }
}

template<class T>
BSTNode<T> *BST<T>::postordSucc(BSTNode<T> *r, BSTNode<T> *node) const {  // Utility to return the post-order successor of a given node in a BST.
    if (node == r) 
        return NULL; 
    else {
        BSTNode<T> *parent = r;
        while (!(node == parent->left || node == parent->right)) {
            if (node->data < parent->data) 
                parent = parent->left;
            else 
                parent = parent->right;
        }
        if (parent->right == NULL || parent->right == node)
            return parent;
        BSTNode<T> *curr = parent->right;
        while (curr->left || curr->right)
            if (curr->left)
                curr = curr->left;
            else 
                curr = curr->right;
        return curr;
    }
}