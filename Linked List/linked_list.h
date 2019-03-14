#ifndef LINKED_LIST
#define LINKED_LIST
typedef struct NODE *node;
struct NODE{ //Node data type
	int value;
	struct NODE *left;
	struct NODE *right;
	bool error_code; //0 means no error, 1 means error
};
struct LINKEDLIST{ //Linked list template
	node start;
	node end;
};
typedef struct LINKEDLIST *linkedlist;
void insert(linkedlist l, node n, int index); //Inserts a node at an index
void push_front(linkedlist l, node n); //Pushes a node in the beginning of a linked list
void push_back(linkedlist l, node n); //Pushes a node at the back of a linked list
node pop_front(linkedlist l); //Removes a node in the beginning of a linked list and returns it
node pop_back(linkedlist l); //Removes a node at the back of a linked list and returns it
node peek_front(linkedlist l); //Returns the node in the beginning of a linked list
node peek_back(linkedlist l); //Returns the node at the back of a linked list
node get(linkedlist l, int index); //Gets the node at a specific index of a linked list
node make_node(int value); //Returns a node
void display(linkedlist l); //Displays contents of a linked list
linkedlist make_linkedlist(); //Returns a blank linked list
#endif