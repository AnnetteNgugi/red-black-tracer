#include "../include/Node.h"

Node::Node(int value)
{
    data = value;

    color = RED;

    left = nullptr;
    right = nullptr;
    parent = nullptr;
}