#ifndef STACK_H
#define STACK_H

/**
 * Stack element.
 *     prev: address of the previous stack element
 *     data: stored item.
 */
struct stack_element {
    struct stack_element * prev;
    int data;
};

/**
 * Stack data structure:
 *     top: address to the top element
 */
struct linked_stack {
    struct stack_element * top;
};

/**
 * Initializes new stack.
 * @returns a pointer to the new stack.
 */
struct linked_stack * new_stack();

/**
 * Frees stack from memory.
 * @param s pointer to the stack to be freed.
 */
void free_stack(struct linked_stack * s);

/**
 * Check if the stack is empty.
 * @param s the stack to insepct.
 * @returns 1 if the stack is empty, 0 otherwise.
 */
char is_empty(struct linked_stack s);

/**
 * Stores the top of the stack in the address pointed by e, and decrements the
 * stack index.
 * @param s the address of the stack.
 * @param e address where the popped element will be stored.
 * @returns 0 if the item was popped, -1 if the stack is empty.
 */
int pop(struct linked_stack * s, unsigned int * e);

/**
 * Stores the item pointed by e in the top of the stack, and increments the
 * stack index.
 * @param s the address of the stack.
 * @param e the item to be pushed into the stack.
 * @returns 0 if the item was pushed, -1 if the stack is full.
 */
int push(struct linked_stack * s, unsigned int e);

/**
 * Stores the top of the stack in the address pointed by e, but without
 * decrementing the stack index.
 * @param s the stack.
 * @param e address where the peeked element will be stored.
 * @returns 0 if the item was peeked, -1 if the stack is empty.
 */
int peek(struct linked_stack s, unsigned int * e);

/**
 * Prints the elements of the stack to stdout.
 * @param s stack to be printed
 */
void print_stack(struct linked_stack s);

#endif
