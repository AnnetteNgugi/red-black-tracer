#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"

class RedBlackTree
{
private:
    Node* root;

    void rotateLeft(Node* node);
    void rotateRight(Node* node);

    void fixInsertion(Node* node);

    void printTree(Node* node, int space);

    int blackHeight(Node* node);

public:
    RedBlackTree();

    void insert(int value);

    void print();

    bool verifyBlackHeight();
};

#endif