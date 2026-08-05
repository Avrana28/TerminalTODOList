#include "linked_list.h"
#include "my_strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node* add_node(struct Node* head, char task[256]){
  if (head == NULL){
    return create_node(task);
  }
  if (head->next == NULL) {
    head->next = create_node(task);
    return head;
  }
  return add_node(head->next, task);
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

struct Node* create_node(char* task){
  struct Node* new = calloc(1, sizeof(struct Node));
  if (new == NULL){
    printf("Failed to allocate memory");
    return NULL;
  }
  my_strcpy(new->task, task);

  return new;
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

void free_list(struct Node* head){
  if (head == NULL){
    return;
  }
  struct Node* next = head->next;

  free(head);

  free_list(next);
}
