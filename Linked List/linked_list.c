#include "linked_list.h"node peek_front(linkedlist l){
node peek_front(linkedlist l){
	return l->start; //Start of linked list
}
node peek_back(linkedlist l){
	return l->end; //End of linked list
}
node make_node(int value){
	node n = (node)malloc(sizeof(struct NODE)); //Allocate memory
	n->value = value;
	n->error_code = 0;
	return n;
}
linkedlist make_linkedlist(){
	linkedlist l = (linkedlist)malloc(sizeof(struct LINKEDLIST)); //Allocate memory
	return l;
