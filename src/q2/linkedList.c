#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

//Returns the number of elements in a linked list
int length(listElement *list) {
    //create a pointer curr that points to current position in list
    listElement *curr = list; 
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
void push(listElement **list, char *data, size_t size) {
    //create a new element and assign it to a 
    //pointer then get the member next from the 
    //struct the newEl points to and assign it to //list pointer and let list pointer = newEl
    listElement *newEl = createEl(data, size);
    newEl->next = *list;
    *list = newEl;
}

//Pops an element from the head of the list
//Updates the list reference using side effects 
listElement *pop(listElement **list) {
    listElement *head = *list;
    //if head of the pointer list, list = the member  
    //next from struct that head points to 
    if (head) {
        *list = head->next; 
    }
    return head;
}

//Enqueues a new element onto the head of the list
//Updates the list reference using side effects
void enqueue(listElement **list, char *data, size_t   size) {
    //create a new element and assign it to a 
    //pointer then get the member next from the 
    //struct the newEl points to and assign it to //list pointer and let list pointer = newEl
    listElement *newEl = createEl(data, size);
    newEl->next = *list;
    *list = newEl;
}

//Dequeues an element from the tail of the list
listElement *dequeue(listElement *list) {
    listElement *temp = list;
    
    while((temp->next)->next != NULL) {
       temp = temp->next;
    }
    listElement *tail = temp->next;
    temp->next = NULL;
    return tail;
}

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
