#include <stdio.h>
#include <stdlib.h>
#include "my_strlib.h"
#include "linked_list.h"

int main(void) {
  char list[256];
  int choice;
  struct Node* current_list;
  do{
    printf("--- Terminal TODO List ---\n");
    printf("Current List: %s\n\n\n", list);
    printf("1. Select/Create List");
    printf("2. Add Task");
    printf("3. Delete Task");
    printf("4. Delete Selected List");
    printf("5. Save and Exit");
    printf("6. Exit");
    

    if (scanf("%d", &choice) != 1 || choice > 6 || choice < 1) {
      printf("Incorrect Input expected int from 1 to 6");
      continue;
    }
    switch(choice) {
    case 1:
      // Select/Create List
      break;
    case 2:
      // Add task
      // add_node()
      break;
    case 3:
      // Delete task
      // delete_node()
      break;
    case 4:
      // free_all()
      // Delete permanent file
      // TODO: delete_list()
      break;
    case 5:
      // Exit (Save Lists on Exit)
      return 0;
      break;
    case 6:
      return 0;
      break;
    }
  } while(true);
  return 0;
}
