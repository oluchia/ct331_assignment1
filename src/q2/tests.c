#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");

  listElement *l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  
  length(l);
  // Test push with value of pointer to pointer address
  push(&l, "Test String (x).", 30);
  // Test enqueue with value of pointer to pointer address 
  enqueue(&l, "Test String (y).", 30);
  // Test length
 
  traverse(l);
  length(l);

  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  traverse(l);
  length(l);
    
  //Test pop
  pop(&l);
  traverse(l);
  length(l);
    
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  // Test length
  length(l);
  printf("\n");

  // Test dequeue - note
  dequeue(l);
  traverse(l);
  length(l); 
    
  // Test delete after
  deleteAfter(l);
  traverse(l);

  // Test length
  length(l);
    
  printf("\n");

  printf("\nTests complete.\n");
}
