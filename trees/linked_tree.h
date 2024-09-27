#ifndef LINKED_TREE_H
#define LINKED_TREE_H
#include <stdbool.h>
#include <stdlib.h>

/* Data model */
struct data {
    int number;
    int original_position;
};

/* Node model */
struct node {
    struct data data;
    struct node * father;
    struct node * left;
    struct node * right;
};

// Define nodetype
typedef struct node node_t;

/**
 * Creates the root node and populates it with the number passed as parameter.
 */
node_t * make_tree(int number);

/**
 * Returns contents of the node passed as parameter.
 */
struct data info(node_t * node);

/**
 * Returns true if the node passed as parameter is the left son of his father.
 */
bool is_left(node_t * node);

/**
 * Returns true if the node passed as parameter is the right son of his father.
 */
bool is_right(node_t * node);

/**
 * Returns the left son of the node passed as parameter.
 */
node_t * left(node_t * node);

/**
 * Returns the right node of the node passed as parameter.
 */
node_t * right(node_t * node);

/**
 * Returns the father node of the node passed as parameter.
 */
node_t * father(node_t * node);

/**
 * Returns the brother of the node passed as parameter.
 */
node_t * brother(node_t * node);

/**
 * Creates a left son of the node with the data passed as parameters.
 */
node_t * set_left(node_t * node, int number, int index);

/**
 * Creates a right son of the node with the data passed as parameters.
 */
node_t * set_right(node_t * node, int number, int index);

/**
 * Deletes the tree which spawnes from the node passed as parameter, and the node
 * itself.
 */
void delete(node_t * root);

#endif