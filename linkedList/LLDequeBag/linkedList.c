#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  assert(lst != NULL);
	lst->firstLink = malloc(sizeof(struct DLink));
	assert(lst->firstLink != 0);
	lst->lastLink = malloc(sizeof(struct DLink));
	assert(lst->lastLink);
	lst->firstLink->next = lst->lastLink;
	lst->firstLink->prev = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
	lst->lastLink->next = lst->firstLink;
	lst->size = 0;

}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList() {

	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
//	newList->size = 0;

	return(newList);

}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
		assert(lst != NULL);
		assert(l != NULL);
		struct DLink *newL = malloc(sizeof(struct DLink));
		newL->value = v;
		l->prev->next = newL;
		l->prev = newL;
		newL->next = l;
		lst->size++;
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
	assert(lst != NULL);
	_addLinkBefore(lst, lst->firstLink, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	_addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {

	return lst->firstLink->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	return lst->lastLink->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
	l->next->prev = l->prev;
	l->prev->next = l->next;
	lst->size--;
	free(l);
}

/*
	removeFrontList
	param: lst the linkedList

	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
	assert(! isEmptyList(lst));
   _removeLink (lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
	assert(! isEmptyList(lst));
	_removeLink (lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
	return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	assert(lst != NULL);
	struct DLink *tempPtr = lst->firstLink->next;
	for(int i = 0; i < lst->size; i++){
			printf("%d\n", tempPtr->value);
			tempPtr=tempPtr->next;
		}
}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	assert(lst != NULL);
	addFrontList(lst,v);

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {


		assert(lst != NULL && lst->size != 0);
	 struct DLink *tempPtr = lst->firstLink->next;
	 for(int i = 0; i < lst->size; i++){

	 	if(tempPtr->value != e){
		 		tempPtr = tempPtr->next;
		}else{
				return 1;
		}
	}
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {

		assert(lst != NULL && lst->size != 0);
		struct DLink *tempPtr = lst->firstLink->next;
		for(int i = 0; i < lst->size; i++){

			if(tempPtr->value != e){
				tempPtr=tempPtr->next;
			}
			else{
				tempPtr->next->prev = tempPtr->prev;
				tempPtr->prev->next = tempPtr->next;
				lst->size--;
				free(tempPtr);
			}
	}
}
