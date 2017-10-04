#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef void (*printSomething) (void *data);

//Moved from linkedList.c
typedef struct genericListElementStruct{
  void *data;
  size_t size;
  printSomething print;
  struct genericListElementStruct *next;
} genericListElement;

//Returns the number of elements in a linked list
int length(genericListElement *list);

//Pushes a new element onto the head of a list 
//Updates the list reference using side effects
void push(genericListElement **list, void *data, size_t size, printSomething);

//Pops an element from the head of the list
//Updates the list reference using side effects 
genericListElement *pop(genericListElement **list);

//Enqueues a new element onto the head of the list
//Updates the list reference using side effects
void enqueue(genericListElement **list, void *data, size_t size, printSomething);

//Dequeues an element from the tail of the list
genericListElement *dequeue(genericListElement *list);

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericListElement *createEl(void *data, size_t size, printSomething);

//Prints out each element in the list
void traverse(genericListElement *start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* after, void *data, size_t size, printSomething);

//Delete the element after the given el
void deleteAfter(genericListElement* after);


#endif
