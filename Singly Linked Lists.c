// Filename: Singly Linked Lists.c
//
// These are notes and sandbox code for the CS50 2018 Week 4 short video
// entitled "Singly Linked Lists".
//
// Date: 08/19/2018
//
// Name: Ian Hutcheson
//
// IDE: Microsoft Visual Studio 2017



#include <stdio.h>
#include <cs50.h>

int main(void) {
	int item = malloc(sizeof(int), 1);
	printf("item is %d\n", item);
	// Collections of like values?
	// Arrays, for example

	// Arrays are great for element lookup, but bad for insertion
	// Easy to insert at the very end of the array, but between elements
	//     becomes very costly
	// Arrays are inflexible for resizing, what if you need a larger array than you thought?

	// ***(Singly) Linked Lists***
	// clever use of pointers, dynamic memory allocation, and structs...
	// put these together to develop a new kind of data structure called linked lists
	// grow and shrink values without any wasted space
	// a linked list node is a special kind of struct with two members:
	//     1. data (int, char, float, etc...)
	//     2. a pointer to another node of the same type
	//     think of it as a chain of nodes
	// first node -> second node -> third node -> ... nth node

	// Create a node structure and call it (typedef) sllnode
	typedef struct sllist
	{
		int val; // can use any data type, not just ints obviously
		struct sllist* next;
	}
	sllnode;
	// self referential structure (we define a node that points to another node), 
	//     so need to use the temporary name 'sllist' within the definition
	// This structure contains a value and a pointer to another node

	// What do we need to understand to use linked lists?
	//     1. Create a linked list when it doesn't already exist
	//     2. Search through a list to find an element
	//     3. Insert a new node
	//     4. Delete a node
	//     5. Delete an entire linked list

	// 1. Create a linked list
	// sllnode* create(int val);
	// this function returns a pointer to a singly-linked list node
	// how do we accomplish this?
	//     a. dynamically allocate space for a new sllnode
	//     b. check to make sure we didn't run out of memory (NULL)
	//     c. initialize val and next field
	//     d. return a pointer to the newly created node
	// a. malloc
	// b. malloc != null
	// c. ex. sllnode* new = create(6);
	// c. continued -- initalize next pointer
	// d. return a pointer to the newly created sllnode (call it new)

	// 2. Search through a linked list to find an element
	// example function prototype
	// bool find(sllnode* head, int val);
	// two arguments, a pointer to the head of the linked list and the item being searched
	// put the first element (the head element) in a global variable
	// only need to keep track of first element if they're chained
	// a. create a traversal pointer pointing to the list's head
	//    create a duplicate pointer rather than using the list's head
	// b. if the current node's val field is what we're looking for, report success
	// c. if not, set the traversal pointer to the next pointer in the list and
	//    go back to step b
	// d. if you've reached the end of the list, report failure

	// trav = trav->next;

	// Linked lists? don't need to keep the elements in order, since there's
	//     no index associated with them
	// But because there's no index, you can't directly access individual elements,
	//     always have to traverse the array until you reach the node you want

	// 3. Insert a new node into the linked list
	// example function prototype
	// sllnode* insert(sllnode* head, int val);
	// a. dynamically allocate space for a new sllnode
	// b. check to make sure you didn't run out of memory (since you're using malloc)
	// c. Populate and insert the node AT THE BEGINNING OF THE LINKED LIST
	//    why? so you don't need to traverse all the way to the end of the list before you add to it
	//    adds O(n) complexity
	// d. Return a pointer to the NEW head of the linked list
	//    be careful of the order in which you move the pointers to the new head!
	//    don't just move the pointer to the old head to the node of the new head!
	//    set the new head's 'next' pointer to the old head of the list, then move
	//        the head of the list to point to the newly created node
	//    FUNDAMENTAL

	// 4. Delete an entire linked list
	// ex. function prototype
	// void destroy(sllnode* head);
	// a. if you've reached the null pointer, stop
	// b. delete the rest of the rest of the list
	// recursion
	// base case, when the node points to null
	// c. free the current node
	// destroy(list); list is the pointer to the head of the list we're passing in
	// the head of list points to != NULL, 
	//     so call destroy(pointer to whatever the head node was pointing to);
	// if the second node was not a null pointer, calls destroy again
	// if the third node was not a null pointer, calls destroy again
	// etc....
	// until you reach the final node which points to NULL
	// now you can stop. and free the current node!
	// call stack logic, now that the call at the top of the stack is complete,
	// the next item at the top of the stack resolves (it frees the current node),
	// then the next item resolves (it frees the current node),
	// then the next item resolves (it frees the current node),
	// etc.
	// recursion!
	// if you don't delete all the items and you end up orphaning some of the
	// items in the list, you get a memory leak.

	// 5. Delete a single element from a linked list
	// kind of tricky
	// if you just delete the node, you break the chain
	// once you find the node you want to delete,
	// you need to step back one step, have the previous node skip over
	// the node to be deleted and point to the next node,
	// then you can safely delete the node
	// One problem? no way to step back through a singly linked list
	// need to create two pointers, the usual traversal pointer to travel
	// through the list, and a second temp pointer that retains a pointer
	// to the previous node in the list
	// 


	return;
}