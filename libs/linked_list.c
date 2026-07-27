#include "linked_list.h"
#include "my_strlib.h"
#include <stdio.h>
#include <stdbool.h>

struct Node* add_node(struct Node* head, char task[256]){
  if (head == NULL){
    printf("You passed an empty List");
    return NULL;
  }
  if (head->next == NULL) {
    struct Node* new = malloc(sizeof(struct Node));
    if (new == NULL){
      printf("Failed to allocate memory");
      return NULL;
    }
    head->next = new;
    return head;
  }
  add_node(head->next, task);
}

struct Node* delete_node(struct Node* head, char task[256]){
  if (head == NULL){
    printf("You passed an empty List");
    return NULL;
  }
  struct Node* previews = NULL;
  struct Node* current = head;
  if (previews == NULL && my_strcmp(current->task, task) == 0){
    struct Node* tmp = head->next;
    free(head);
    return tmp;
  }
  while(true) {
    previews = current;
    current = previews->next;
    if (current == NULL) {
      printf("Task not found");
      return head;
    }
    if (my_strcmp(current->task, task) == 0) {
      previews->next = current->next;
      free(current);
      return head;
    }
  }
}


void list_nodes(struct Node* head){
  if (head == NULL){
    printf("You passed an empty List");
    return;
  }
  printf("Task: %s\n", head->task);
  if (head->next == NULL){
    return;
  }
  list_nodes(head->next);
}
