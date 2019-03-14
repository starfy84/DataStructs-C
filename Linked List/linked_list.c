#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
node node_error(int code){
	node n = make_node(0);
	n->error_code = code;
	return n;
}
void insert(linkedlist l, node n, int index){
	int i = 0; //Current index
	node prev = l->start; //Previous node (should tail curr)
	node curr = l->start; //Current node
	
	while(curr != NULL && i < index){
		prev = curr; 
		curr = curr->right; //Traverses through linked list
	}

	/*
	WIP CODE (I haven't fully tested if it works yet)
	*/
	if(curr != NULL){
		n->right = curr;
		curr->left = n;
		if(prev == NULL)
			l->start = n;
	}
	if(prev != NULL){
		n->left = prev;
		prev->right = n;
		if(curr == NULL)
			l->end = n;
	}
	if(curr == NULL && prev == NULL)
		l->start = l->end = n;
}
void push_front(linkedlist l, node n){
	if(l->start != NULL){
		//Linking nodes
		l->start->left = n;
		n->right = l->start;
		l->start = n;
	}
	else{ //If linked list is empty
		l->start = l->end = n;
	}
}
void push_back(linkedlist l, node n){
	if(l->end != NULL){
		//Linking nodes
		l->end->right = n;
		n->left = l->end;
		l->end = n;
	}
	else{ //If linked list is empty
		l->start = l->end = n;
	}
}
node pop_front(linkedlist l){
	node n = l->start; //Store value being popped
	if(l->start != NULL){
		l->start = l->start->right; //Change start node
		if(l->start != NULL)
			l->start->left = NULL; //Remove connection to popped node
	}
	n->right = NULL; //Remove connection to popped node
	return n;
}
node pop_back(linkedlist l){
	node n = l->end; //Store value being popped
	if(l->end != NULL){
		l->end = l->end->left; //Change end node
		if(l->end != NULL){
			l->end->right = NULL; //Remove connection to popped node
		}
	}
	n->left = NULL; //Remove connection to popped node
	return n;
}
node peek_front(linkedlist l){
	return l->start; //Start of linked list
}
node peek_back(linkedlist l){
	return l->end; //End of linked list
}
node get(linkedlist l, int index){
	int i = 0; //Current index
	node curr = l->start; //Current node
	
	while(curr != NULL && i < index){
		curr = curr->right; //Traverses through linked list
	}
	if(curr == NULL) //Index out of bounds
		return node_error(1);
	return curr;

}
node make_node(int value){
	node n = (node)malloc(sizeof(struct NODE)); //Allocate memory
	n->value = value;
	n->error_code = 0;
	return n;
}
void display(linkedlist l){
	node curr = l->start;
	while(curr != NULL){
		printf("%d -> ",curr->value);
		curr = curr->right;
	}
	printf("END\n");
}

linkedlist make_linkedlist(){
	linkedlist l = (linkedlist)malloc(sizeof(struct LINKEDLIST)); //Allocate memory
	return l;
}