#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"

FILE* create_list(char* file_name) {
  char* file_path[263];
  snprintf(file_path, sizeof(file_path), ".lists/[%s]", file_name);
  FILE* fptr = fopen(file_path, "wb");
  if (fptr == NULL) {
    fprintf(stderr, "Unable to open the file");
    return NULL;
  }
  return fptr;
}
  
struct Node* load_list(char* file_name){
  FILE* fptr = fopen(file_name, "rb");
  if (fptr == NULL) {
    fprintf(stderr, "Unable to open the file");
    return NULL;
  }
  struct Node* head;
  struct Node* start;
  struct Node* temp;
  while (fread(temp, sizeof(struct Node), 1, fptr)) {
    if (head == NULL) {
      head = temp;
      start = head;
      continue;
    }
    head->next = temp;
    head = head->next;
  }
  fclose(fptr);
  return start;
}



int flush_to_file(FILE* fptr, struct Node* head) {
  if (head == NULL) {
    printf("Tryed to flush an empty list");
    return 1;
  }
  size_t check = fwrite(head, sizeof(struct Node), 1, fptr);
  if (!check) {
    printf("Failed to flush task %s", head->task);
    return 1;
  }
  if (head->next == NULL) {
    return 0;
  }

  return flush_to_file(fptr, head->next);
}
