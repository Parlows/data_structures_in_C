#include "linked_tree.h"

// To build the tree
node_t * make_tree(int number) {

    node_t * root = (node_t*) malloc(sizeof(node_t));

    root->data.number = number;
    root->data.original_position = 0;
    root->father = NULL;
    root->left = NULL;
    root->right = NULL;

    return root;
}

// To get the contents of a node
struct data info(node_t * node) {
    return node->data;
}

// To get info about the nature of a node

bool is_left(node_t * node) {
    node_t * f = father(node);
    if (f == NULL)
        return false;
    else if (left(f) == node)
        return true;
    else
        return false;
}

bool is_right(node_t * node) {
    node_t * f = father(node);
    if (f == NULL)
        return false;
    else if (left(f) == node)
        return false;
    else
        return true;
}

// To get nodes realted to current node
node_t * left(node_t * node) {
    return node->left;
}

node_t * right(node_t * node) {
    return node->right;
}

node_t * brother(node_t * node) {
    node_t * f = father(node);
    if (f == NULL)
        return NULL;
    else if (is_left(node))
        return right(f);
    else
        return left(f);
}

node_t * father(node_t * node) {
    return node->father;
}

// To set contents of node
node_t * set_left(node_t * node, int number, int index) {
    
    node_t * new_node = (node_t*) malloc(sizeof(node_t));

    new_node->data.number = number;
    new_node->data.original_position = index;
    new_node->father = node;
    new_node->left = NULL;
    new_node->right = NULL;

    node->left = new_node;

    return new_node;
}

node_t * set_right(node_t * node, int number, int index) {
    
    node_t * new_node = (node_t*) malloc(sizeof(node_t));

    new_node->data.number = number;
    new_node->data.original_position = index;
    new_node->father = node;
    new_node->left = NULL;
    new_node->right = NULL;


    node->right = new_node;

    return new_node;
}

void delete(node_t * root) {
    
}
