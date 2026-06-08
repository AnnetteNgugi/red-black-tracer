//Constructor
#include "../include/RedBlackTree.h"
#include <iostream>

RedBlackTree::RedBlackTree()
{
    root = nullptr;
}

//Left Rotation
void RedBlackTree::rotateLeft(Node* x)
{
    Node* y = x->right;

    x->right = y->left;

    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

//Right Rotation
void RedBlackTree::rotateRight(Node* y)
{
    Node* x = y->left;

    y->left = x->right;

    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;

    if (!y->parent)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

//Insert
void RedBlackTree::insert(int value)
{
    Node* node = new Node(value);

    Node* parent = nullptr;
    Node* current = root;

    while (current)
    {
        parent = current;

        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    node->parent = parent;

    if (!parent)
        root = node;
    else if (value < parent->data)
        parent->left = node;
    else
        parent->right = node;

    fixInsertion(node);

    std::cout << "\nInserted: "
              << value
              << std::endl;

    print();

    std::cout
        << "Black Height Valid: "
        << (verifyBlackHeight() ? "YES" : "NO")
        << std::endl;
}

//Fix Insertion
void RedBlackTree::fixInsertion(Node* node)
{
    while (node != root &&
           node->parent->color == RED)
    {
        Node* parent = node->parent;
        Node* grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            Node* uncle = grandparent->right;

            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                node = grandparent;
            }
            else
            {
                if (node == parent->right)
                {
                    node = parent;
                    rotateLeft(node);
                }

                parent->color = BLACK;
                grandparent->color = RED;

                rotateRight(grandparent);
            }
        }
        else
        {
            Node* uncle = grandparent->left;

            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                node = grandparent;
            }
            else
            {
                if (node == parent->left)
                {
                    node = parent;
                    rotateRight(node);
                }

                parent->color = BLACK;
                grandparent->color = RED;

                rotateLeft(grandparent);
            }
        }
    }

    root->color = BLACK;
}

//Print Tree
void RedBlackTree::printTree(Node* root, int space)
{
    if (!root)
        return;

    space += 8;

    printTree(root->right, space);

    std::cout << std::endl;

    for (int i = 8; i < space; i++)
        std::cout << " ";

    std::cout
        << root->data
        << "("
        << (root->color == RED ? "R" : "B")
        << ")"
        << std::endl;

    printTree(root->left, space);
}

//Print Wrapper
void RedBlackTree::print()
{
    printTree(root, 0);
}

//Black Height Checker
int RedBlackTree::blackHeight(Node* node)
{
    if (!node)
        return 1;

    int left =
        blackHeight(node->left);

    int right =
        blackHeight(node->right);

    if (left != right)
        return 0;

    return left +
        (node->color == BLACK);
}

//Verification
bool RedBlackTree::verifyBlackHeight()
{
    return blackHeight(root) != 0;
}