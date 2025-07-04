#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<string>
#include<functional>
#include<iostream>
#include<assert.h>
#include"bstnode.h"

template<typename Type>
class BinarySearchTree {
public:
    // Public Interface Functions: All of these are implemented
    BinarySearchTree();

    ~BinarySearchTree();

    void printInorder();

    void printPostorder();

    void printPreorder();

    void insert(Type value);

    void remove(Type value);

    Type min() const;

    Type max() const;

    int height() const;

    bool search(Type value) const;

    bool empty() const;

    void printTree() const;

    void report() const;

private:
    // Member variable root
    Node<Type> *root;

    //Auxillary recursive bst functions
    //public interface functions call these
    //You will implement these functions.

    // Tree traversal, second parameter is a "function" with
    // return type void and parameter Node*, i.e:
    //					void process(Node* )
    void inorder(Node<Type> *node, std::function<void(Node<Type> *)> proc);

    void preorder(Node<Type> *node, std::function<void(Node<Type> *)> proc);

    void postorder(Node<Type> *node, std::function<void(Node<Type> *)> proc);

    Node<Type> *min(Node<Type> *node) const;

    Node<Type> *max(Node<Type> *node) const;

    int height(Node<Type> *node) const;

    Node<Type> *insert(Node<Type> *node, Type value);

    bool search(Node<Type> *node, Type value) const;

    Node<Type> *remove(Node<Type> *node, Type value);

    void printTree(Node<Type> *node, int space) const;
};


//----------------------------------------------------------
//-------------- Binary Search Tree Function Implementations
//
//  Public Interface functions
// 		Completley Implemented, nothing to do.  These functions
//      call the recursive helper functions you will implement
//		below.

// Constructor
template<typename Type>
BinarySearchTree<Type>::BinarySearchTree() : root(nullptr) {
}

// Destructor
template<typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {
    //Use the post order traversal to delete the nodes.
    //lambda function to delete a node n:
    //				[](Node* n) {delete n; }
    postorder(root, [](Node<Type> *n) { delete n; });
}

template<typename Type>
void BinarySearchTree<Type>::printInorder() {
    //Use inorder traversal to print items in a node in the tree.
    //lambda function to print the value in a node:
    //lambda to print->	"[](Node* n) {std::cout << n->value() << std::endl; }"
    inorder(root, [](Node<Type> *n) { std::cout << n->value() << " "; });

    std::cout << std::endl;
}

template<typename Type>
void BinarySearchTree<Type>::printPreorder() {
    //Use pre order traversal to print items in a node in the tree.
    //lambda function to print the value in a node:
    //lambda to print->	"[](Node* n) {std::cout << n->value() << std::endl; }"
    preorder(root, [](Node<Type> *n) { std::cout << n->value() << " "; });
    std::cout << std::endl;
}

template<typename Type>
void BinarySearchTree<Type>::printPostorder() {
    //Use post order traversal to print items in a node in the tree.
    //lambda function to print the value in a node:
    //lambda to print->	"[](Node* n) {std::cout << n->value() << std::endl; }"
    postorder(root, [](Node<Type> *n) { std::cout << n->value() << " "; });
    std::cout << std::endl;
}

template<typename Type>
void BinarySearchTree<Type>::insert(Type value) {
    root = insert(root, value);
}

template<typename Type>
void BinarySearchTree<Type>::remove(Type value) {
    root = remove(root, value);
}

template<typename Type>
Type BinarySearchTree<Type>::min() const {
    assert(root != nullptr);

    Node<Type> *node = min(root);
    return node->value();
}

template<typename Type>
Type BinarySearchTree<Type>::max() const {
    assert(root != nullptr);

    Node<Type> *node = max(root);
    return node->value();
}

template<typename Type>
int BinarySearchTree<Type>::height() const {
    return height(root);
}

template<typename Type>
bool BinarySearchTree<Type>::search(Type value) const {
    return search(root, value);
}

template<typename Type>
bool BinarySearchTree<Type>::empty() const {
    return (root == nullptr);
}

template<typename Type>
void BinarySearchTree<Type>::printTree() const {
    printTree(root, 0);
}

//----------------------------------------------------------
//
// Private Recursive Functions: You Implement These.
//

// Inorder Traversal: Implemented so you can see how passing a function into
// another function works, other traversals remain for you to implement.  the second
// parameter, proc, is a function and we see that its return type is void and it
// has a Node* as a parameter.  Any function of that form passed into inorder will be
// called as seen below.
// If we assume that we use the printing lambda defined above you can imagine that proc
// is defined as:
//		void proc(Node<Type> * n){std::cout << n->value << " "; }
template<typename Type>
void BinarySearchTree<Type>::inorder(Node<Type> *node, std::function<void(Node<Type> *)> proc) {
    if (node == nullptr)
        return;

    inorder(node->left(), proc);
    proc(node);
    inorder(node->right(), proc);
}

template<typename Type>
void BinarySearchTree<Type>::postorder(Node<Type> *node, std::function<void(Node<Type> *)> proc) {
    if (node == nullptr)
        return;

    postorder(node->left(), proc);
    postorder(node->right(), proc);
    proc(node);
}

template<typename Type>
void BinarySearchTree<Type>::preorder(Node<Type> *node, std::function<void(Node<Type> *)> proc) {
    if (node == nullptr)
        return;

    proc(node);
    preorder(node->left(), proc);
    preorder(node->right(), proc);
}

// BinarySearchTree::insert recursively inserts into the BST according
// to the rules of the BST.
template<typename Type>
Node<Type> *BinarySearchTree<Type>::insert(Node<Type> *node, Type value) {
    if (node == nullptr)
        return new Node<Type>(value, nullptr, nullptr);
    else if (value == node->value())
        return node;
    else if (value < node->value())
        node->left(insert(node->left(), value));
    else
        node->right(insert(node->right(), value));

    return node;
}

// BinarySearchTree<Type>::search recursively searches the tree for value.
template<typename Type>
bool BinarySearchTree<Type>::search(Node<Type> *node, Type value) const {
    if (node == nullptr)
        return false;
    else if (value == node->value())
        return true;
    else if (value < node->value())
        return search(node->left(), value);
    else
        return search(node->right(), value);
}

// BinarySearchTree<Type>::height
// Height of a binary tree is the height of the largest subtree + 1
// An empty tree has height 0;
template<typename Type>
int BinarySearchTree<Type>::height(Node<Type> *node) const {
    if (node == nullptr)
        return 0;
    return std::max(height(node->left()), height(node->right())) + 1;
}

// BinarySearchTree<Type>::min recursively obtain the node with the minimum value
template<typename Type>
Node<Type> *BinarySearchTree<Type>::min(Node<Type> *node) const {
    if (node->left() == nullptr)
        return node;
    return min(node->left());
}

// BinarySearchTree<Type>::max recursively obtain the node with the minimum value
template<typename Type>
Node<Type> *BinarySearchTree<Type>::max(Node<Type> *node) const {
    if (node->right() == nullptr)
        return node;
    return max(node->right());
}

// BinarySearchTree<Type>::printTree
// Prints the BST in a tree format rotated -90 degrees.  Uses space to
// signify the space between levels of the tree. Uses the inorder
// traversal but traverses right first, rather than left. Cannot use
// any of the other travel functions because of this.
//
// parameter space determines the number of spaces needed for each level.
// Example binary shows 5 spaces between levels.
//
// i.e. traverse right
//		print appropriate number of spaces
//		print value
//		traverse left
template<typename Type>
void BinarySearchTree<Type>::printTree(Node<Type> *node, int space) const {
    if (node == nullptr)
        return;
    printTree(node->right(), space + 5);
    for (int i = 0; i < space; i++)
        std::cout << " ";
    std::cout << node->value() << std::endl;
    printTree(node->left(), space + 5);
}


//BinarySearchTree<Type>::remove
//
// Make sure you're comfortable with the iterative solution seen in the lecture slides
// before thinking about how to do it recursively.
//
// Recursively removes a node in the binary tree.  The recursive algorithm will
// be different than the iterative algorithm.  The iterative algorithm conisted
// of first finding the node using two pointers so that we know how to rearrange
// the children of the deleted node. In recursion we are passing in the sub trees
// each recursive step, so by definition we already have a handle on each subtrees'
// parents (it is the node that is passed into the previous recursive step).
// After we search the node to remove (if it is in the tree) everything else is the same, we
// handle the three cases: leaf, one child (which consist of two cases: left vs right),
// and two children.  With iterative algorithm there were subcases regardling if the
// node was root or not, with recursion we get that for free.
//
// In the iterative algorithm discussed in class, in dealing with a node with two children
// We swapped items from one of the nodes in either subtree.  For the recursive algorithm
// We just want to write the subtree node's value into the node to be deleted, not actually
// swap. This way subtree remains a valid bst, so we can recurse on that subtree and
// recursively call _deleteNode on that value (not the original) to remove that node.
//
// It takes a bit to wrap your head around this, use the 6 steps, draw lots of pictures.
//
template<typename Type>
Node<Type> *BinarySearchTree<Type>::remove(Node<Type> *node, Type value) {

    if (node == nullptr)
        return nullptr;

    if (value < node->value()) {
        node->left(remove(node->left(), value));
        return node;
    } else if (value > node->value()) {
        node->right(remove(node->right(), value));
        return node;
    } else {
        if (node->value() == value) {

            bool leaf = node->left() == nullptr && node->right() == nullptr;
            bool leftChild = node->left() != nullptr;
            bool rightChild = node->right() != nullptr;
            bool twoChildren = leftChild && rightChild;

            if (leaf) {
                delete node;
                return nullptr;
            }else if(twoChildren){
                Node<Type>* leftMax = max(node->left());
                node->value(leftMax->value());
                node->left(remove(node->left(),leftMax->value()));
                return node;

            }else if (leftChild) {
                Node<Type>* leftSubTree = node->left();
                delete node;
                return leftSubTree;
            }else {
                Node<Type>* rightSubTree = node->right();
                delete node;
                return rightSubTree;
            }


        }

    }
}

// BinarySearchTree<Type>::report
template<typename Type>
void BinarySearchTree<Type>::report() const {

    std::string msg = "When the input data was random, my_bst performed slightly faster than std::set, though the gap between their performances shrank as the test size increased. While my_bst's performance was faster, it is highly dependent on the order of the input data; stl::set's performance is consistent and predictable regardless of the input pattern. This is because std::set is typically implemented as a self-balancing binary search tree. A self-balancing tree is slightly slower because after every insertion it needs to rebalance. Rebalancing increases the overhead of the algorithm but manages to keep the time complexity close to O(log N) for all data. ";
    std::cout << msg << std::endl;
}


// MMX


#endif//BINARYSEARCHTREE_H_MMX
