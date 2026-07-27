#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

struct Node {
  char task[256];
  struct Node* next;
};

struct Node* add_node(struct Node* head, char task[256]);

struct Node* delete_node(struct Node* head, char task[256]);

void list_nodes(struct Node* head);

#endif // MY_LINKED_LIST_H
