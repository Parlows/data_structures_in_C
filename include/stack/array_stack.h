#ifndef STACK_H
#define STACK_H


/**
 * Stack data structure:
 *     top: index to the top item.
 *     size: maximum number of items the stack can store.
 *     items: pointer to the items array.
 */
struct array_stack {
    int top;
    unsigned int size;
    unsigned int * items;
};

/**
 * Initializes new stack
 * @param size maximum number of items the stack new stack will be able to store.
 * @returns a pointer to the new stack.
 */
struct array_stack * new_stack(unsigned int size);

/**
 * Frees stack from memory.
 * @param s pointer to the stack to be freed.
 */
void free_stack(struct array_stack * s);

/**
 * Check if the stack is empty.
 * @param s the stack to insepct.
 * @returns 1 if the stack is empty, 0 otherwise.
 */
char is_empty(struct array_stack s);

/**
 * Stores the top of the stack in the address pointed by e, and decrements the
 * stack index.
 * @param s the address of the stack.
 * @param e address where the popped element will be stored.
 * @returns 0 if the item was popped, -1 if the stack is empty.
 */
int pop(struct array_stack * s, unsigned int * e);

/**
 * Stores the item pointed by e in the top of the stack, and increments the
 * stack index.
 * @param s the address of the stack.
 * @param e the item to be pushed into the stack.
 * @returns 0 if the item was pushed, -1 if the stack is full.
 */
int push(struct array_stack * s, unsigned int e);

/**
 * Stores the top of the stack in the address pointed by e, but without
 * decrementing the stack index.
 * @param s the stack.
 * @param e address where the peeked element will be stored.
 * @returns 0 if the item was peeked, -1 if the stack is empty.
 */
int peek(struct array_stack s, unsigned int * e);

/**
 * Prints the elements of the stack to stdout.
 * @param s stack to be printed
 */
void print_stack(struct array_stack s);

#endif
