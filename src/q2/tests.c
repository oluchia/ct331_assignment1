#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void testStack() {
  listElement *l = createEl("Test String (a).", 30);
  traverse(l);
  length(l);
    
  push(&l, "Test String (c).", 30);
  insertAfter(l, "Test String (b).", 30);
  push(&l, "Test String (d).", 30);
  traverse(l);
  length(l);
    
  pop(&l);
  traverse(l);
  length(l);

  deleteAfter(l);
  traverse(l);
  length(l);
}

void testQueue() {
  listElement *l = createEl("Test String (w).", 30);
  traverse(l);
  length(l);
    
  enqueue(&l, "Test String (y).", 30);
  insertAfter(l, "Test String (x).", 30);
  enqueue(&l, "Test String (z).", 30);
  traverse(l);
  length(l);
    
  dequeue(l);
  traverse(l);
  length(l);
  
  deleteAfter(l);
  traverse(l);
  length(l);
    
}

void runTests(){
  printf("Tests running...\n");

  testStack();
    
  printf("\n");
  
  testQueue();

  printf("\nTests complete.\n");
}

