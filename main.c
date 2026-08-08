#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <errno.h>
#include "linked_list.h"
#include "list_permanency.h"
#include "my_strlib.h"

#define MAKE_DIR(path) mkdir(path, 0777)


int main(void) {
  const char dir_name[] = ".lists";
  int choice;
  struct Node *current_list;
  char list_name[256] = "";
  char *file_path;
  FILE *fptr;
  char task[256];
  do{
    printf("--- Terminal TODO List ---\n");
    printf("Current List: %s\n\n\n", list_name);
    printf("1. Select List\n");
    printf("2. Create List\n");
    printf("3. Add Task\n");
    printf("4. Delete Task\n");
    printf("5. Show Selected List\n");
    printf("6. Delete Selected List\n");
    printf("7. Save and Exit\n");
    printf("8. Exit\n");
    

    if (scanf("%d", &choice) != 1 || choice > 8 || choice < 1) {
      printf("Incorrect Input expected int from 1 to 8");
      continue;
    }
    switch(choice) {
    case 1:
      printf("Write The List name: ");

      if (scanf("%255s", list_name) != 1) {
	printf("List name too long");
	continue;
      }
      if (errno != EEXIST && MAKE_DIR(dir_name) != 0) {
	printf("Error making the .lists directory");
	return 1;
      }

      file_path = my_join(my_join(dir_name, "/"), list_name);

      current_list = load_list(file_path);
      
      break;
    case 2:
     printf("Write The List name: ");

      if (scanf("%255s", list_name) != 1) {
	printf("List name too long");
	continue;
      }
      if (errno != EEXIST && MAKE_DIR(dir_name) != 0) {
	printf("Error making the .lists directory");
	return 1;
      }
      
      create_list(list_name);

      file_path = my_join(my_join(dir_name, "/"), list_name);

      current_list = load_list(file_path);
      
      break;
    case 3:
      printf("Write the task:\n");

      if (scanf("%255s", task) != 1) {
        printf("Task too long.\n");
        continue;
      }
      current_list = add_node(current_list, task);
      break;
    case 4:
      printf("Write the task:\n");

      if (scanf("%255s", task) != 1) {
        printf("Task too long.\n");
        continue;
      }
      current_list = delete_node(current_list, task);
      break;
    case 5:
      list_nodes(current_list);
      break;
    case 6:
      if (remove(file_path) != 0) {
        printf("Failed to remove the file.\n");
        continue;
      }
      free_list(current_list);
      break;
    case 7:
      if (flush_to_file(fptr, current_list) != 0) {
        printf("Failed to Flush the list to file.\n");
	continue;
      }
      free_list(current_list);
      return 0;
      break;
    case 8:
      free_list(current_list);
      return 0;
      break;
    }
  } while(true);
  return 0;
}
