/**
 * OBJECTIVE: Find all duplicates in a list of numbers.
 *     We have a list like:
 *         [6,0,1,5,2,3,4,4,3,6,1,7,3,7,5,6,6,3,3,5,1,7,9,0,4,5,3,9,0,7]
 *     We want to find all 2s. We could compare number by number, or we could
 *     build a tree to reduce the number of comparisons.
 *     
 *     The first number must be placed in the root node. Each succesive number
 *     in the list is compared with root. If it matches, we have a duplicate.
 *     If it is smaller, we examine the left subtree, and if it is larger, we
 *     examine the right subtree. If subtree is empty, the number is not a
 *     duplicate and is placed into a new node at that position in the tree.
 *     If the subtree is nonempty, we compare the number to the contents of the
 *     root of the subtree and the entire process is repeated with the subtree.-96+
 */
#include <stdio.h>
#include "linked_tree.h"

#define LENGTH 16

int main() {

    int input_list[LENGTH] = {14,15,4,9,7,18,3,5,16,5,4,20,17,9,14,5};

    // Read first number
    int number;
    number = input_list[0];

    printf("Writing input_list[%d] = %d\n",0, number);
    node_t * root = make_tree(number);

    int counter = 1;
    while(counter < LENGTH) { // Go through list
        
        number = input_list[counter]; // Get element
        printf("Reading input_list[%d] = %d\n",counter, number);

        // Initialize aux pointers
        node_t * current_node = root; // Start the search in the root node
        node_t * next_node = root;

        // Search loop
        while(number != info(current_node).number) { // While we havent found a duplicate
            if(number > info(current_node).number) { // If the current number is greater than the current node number 
                next_node = right(current_node); // Get the right node
                if(next_node == NULL) { // If right node does not exist
                    current_node = set_right(current_node, number, counter); // Create rigth node with the current number
                    break; // Exit search
                }
                else // If left node does exist
                    current_node = next_node; // Travel to retrieved node
            } else { // If the current number is less than the current node number
                next_node = left(current_node); // Get the left node
                if(next_node == NULL) { // If left node does not exist
                    current_node = set_left(current_node, number, counter); // Create left node with the current number
                    break; // Exit search
                }
                else // If left node does exist
                    current_node = next_node; // Travel to retrieved node
            }
        }

        /**
         * At this point, the search may have been interrupted for two reasons.
         *     1: Because a new node has been created.
         *     2: Because we found a duplicate.
         * In the first case, we would have next_node==NULL.
         * In the second case, next_node will have the value of current node
         */
        if(next_node != NULL) {
            printf("\t%d %s [%d]\n", number, "has already appeared in position", info(current_node).original_position);
        }

        counter++;
    }

    return 0;
}