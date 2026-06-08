# Red-Black Insertion Tracer

## Project Overview

This project implements a Red-Black Tree from scratch in C++17. The program supports insertion operations and automatically maintains the Red-Black Tree properties through recoloring and tree rotations.

After each insertion, the program:

1. Prints the complete tree structure.
2. Displays the color of every node.
3. Verifies that the tree satisfies the black-height property.
4. Reports whether the tree remains valid.

The implementation does not use any STL tree structures and was developed specifically to demonstrate understanding of self-balancing binary search trees and algorithm analysis.

---

## Learning Objectives

This project demonstrates:

* Binary Search Tree insertion
* Self-balancing tree algorithms
* Left and right rotations
* Recoloring operations
* Recursive tree traversal
* Time and space complexity analysis
* Unit testing in C++

---

## Project Structure

```text
red-black-tracer/
│
├── include/
│   ├── Node.h
│   └── RedBlackTree.h
│
├── src/
│   ├── Node.cpp
│   ├── RedBlackTree.cpp
│   └── main.cpp
│
├── tests/
│   └── test_redblack.cpp
│
├── report/
│   └── report.pdf
│
├── README.md
└── Makefile
```

### File Descriptions

#### Node.h

Defines the Node class and Color enumeration used by the Red-Black Tree.

#### Node.cpp

Implements the Node constructor.

#### RedBlackTree.h

Contains the RedBlackTree class declaration and function prototypes.

#### RedBlackTree.cpp

Implements:

* Tree insertion
* Rotation algorithms
* Recoloring logic
* Black-height verification
* Tree printing

#### main.cpp

Demonstration application that inserts values into the tree and displays the resulting structure.

#### test_redblack.cpp

Contains unit tests using assert statements to verify correctness.

#### Makefile

Provides build and test commands.

---

## Compilation

This project requires:

* Linux
* g++ compiler
* C++17 standard

Compile the project:

```bash
make
```

---

## Running the Program

```bash
./tracer
```

Example output:

```text
Inserted: 10

10(B)

Black Height Valid: YES

Inserted: 20

        20(R)

10(B)

Black Height Valid: YES
```

---

## Running Tests

Compile and execute tests:

```bash
make test
```

Successful execution indicates that all assertions passed.

---

## Red-Black Tree Properties

The implementation enforces the following rules:

1. Every node is either red or black.
2. The root is always black.
3. Red nodes cannot have red children.
4. Every path from the root to a null leaf contains the same number of black nodes.
5. New nodes are initially inserted as red.

Violations are corrected using recoloring and rotations.

---

## Complexity Analysis

| Operation                 | Time Complexity |
| ------------------------- | --------------- |
| Search                    | O(log n)        |
| Insert                    | O(log n)        |
| Rotation                  | O(1)            |
| Recoloring                | O(1)            |
| Tree Printing             | O(n)            |
| Black Height Verification | O(n)            |

### Space Complexity

The tree stores one node per element:

```text
O(n)
```

where n is the number of inserted elements.

---

## Author

Name: __FEE3/2851/2025____________________

Course: Data Structures and Algorithms

Project: Red-Black Insertion Tracer
