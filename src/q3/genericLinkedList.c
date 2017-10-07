#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Returns the number of elements in a linked list
int length(genericListElement *list) {
    //create a pointer curr that points to current position in list
    genericListElement *curr = list; 
    int length  = 0;
    
    //while curr != null pointer increment length
    //also get the member next from the struct that curr points to 
    //and store in curr 
    while (curr != NULL) {
        length++;
        curr = curr->next; 
    }
    
    return printf("Number of elements in linked list: %d \n", length);
}

//Pushes a new element onto the head of a list 
//Updates the list reference using side effects
void push(genericListElement **list, void *data, size_t size, printSomething printFunc) {
    //create a new element and assign it to a 
    //pointer then get the member next from the 
    //struct the newEl points to and assign it to //list pointer and let list pointer = newEl
    genericListElement *newEl = createEl(data, size, printFunc);
    newEl->next = *list;
    *list = newEl;
}

//Pops an element from the head of the list
//Updates the list reference using side effects 
genericListElement *pop(genericListElement **list) {
    genericListElement *head = *list;
    //if head of the pointer list, list = the member  
    //next from struct that head points to 
    if (head) {
        *list = head->next; 
    }
    return head;
}

//Enqueues a new element onto the head of the list
//Updates the list reference using side effects
void enqueue(genericListElement **list, void *data, size_t size, printSomething printFunc) {
    //create a new element and assign it to a 
    //pointer then get the member next from the 
    //struct the newEl points to and assign it to //list pointer and let list pointer = newEl
    genericListElement *newEl = createEl(data, size, printFunc);
    newEl->next = *list;
    *list = newEl;
}

//Dequeues an element from the tail of the list
genericListElement *dequeue(genericListElement *list) {
    genericListElement *temp = list;
    
    while((temp->next)->next != NULL) {
       temp = temp->next;
    }
    genericListElement *tail = temp->next;
    temp->next = NULL;
    return tail;
}

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement *createEl(void *data, size_t size, printSomething printFunc){
  genericListElement* e = malloc(sizeof(genericListElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void *dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e->print = printFunc; //dumb moment - don't forget
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(genericListElement *start){
  genericListElement *current = start;

  while(current != NULL){
    current->print(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* el, void *data, size_t size, printSomething printFunc){
  genericListElement* newEl = createEl(data, size, printFunc);
  genericListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(genericListElement* after){
  genericListElement* delete = after->next;
  genericListElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
