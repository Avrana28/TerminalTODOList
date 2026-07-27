#include <stdio.h>
#include "linked_list.h"

int main(){

  struct Node* head = NULL;

  head = add_node(head, "Buy milk");
  head = add_node(head, "Learn C pointers");
  head = add_node(head, "Build a project");
  
  plist_nodes(head);
  return 0;
}
