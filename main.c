#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <errno.h>
#include "my_strlib.h"
#include "linked_list.h"

#define MAKE_DIR(path) mkdir(path, 0777)


int main(void) {
  const char dir_name[6] = ".lists";
  int choice;
  struct Node* current_list;
  do{
    printf("--- Terminal TODO List ---\n");
    printf("Current List: %s\n\n\n", list);
    printf("1. Select List\n");
    printf("2. Create List\n");
    printf("3. Add Task\n");
    printf("4. Delete Task\n");
    printf("5. Delete Selected List\n");
    printf("6. Save and Exit\n");
    printf("7. Exit\n");
    

    if (scanf("%d", &choice) != 1 || choice > 6 || choice < 1) {
      printf("Incorrect Input expected int from 1 to 6");
      continue;
    }
    switch(choice) {
    case 1:
      char* list_name[256]; 
      printf("Write The List name: ");

      if (scanf("%255s", list_name) != 1) {
	printf("List name too long");
	continue;
      }
      if (errno != EEXIST && MAKE_DIR(dir_name) != 0) {
	printf("Error making the .lists directory");
	return 1;
      }
      //TODO continue this, all the other comments are outdated
      
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
      
    case 7:
      return 0;
      break;
    }
  } while(true);
  return 0;
}
