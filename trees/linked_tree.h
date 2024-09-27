#ifndef LINKED_TREE_H
#define LINKED_TREE_H
#include <stdbool.h>
#include <stdlib.h>

struct data {
    int number;
    int original_position;
};

struct node {
    struct data data;
    struct node * father;
    struct node * left;
    struct node * right;
};

// Define nodetype
typedef struct node node_t;

// To build the tree
node_t * make_tree(int number);

// To get the contents of a node
struct data info(node_t * node);

// To get info about the nature of a node
bool is_left(node_t * node);
bool is_right(node_t * node);

// To get nodes realted to current node
node_t * left(node_t * node);
node_t * right(node_t * node);
node_t * father(node_t * node);
node_t * brother(node_t * node);

// To set contents of node
node_t * set_left(node_t * node, int number, int index);
node_t * set_right(node_t * node, int number, int index);

// To delete the tree and free the memory
void delete(node_t * root);

#endif