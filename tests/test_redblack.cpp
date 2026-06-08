#include <cassert>
#include "../include/RedBlackTree.h"

int main()
{
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    assert(tree.verifyBlackHeight());

    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    assert(tree.verifyBlackHeight());

    return 0;
}