#ifndef PERMANENT_LISTS
#define PERMANENT_LISTS
#include "linked_list.h"
#include <stdio.h>

FILE* create_list(char* file_name);

struct Node* load_list(char* file_name);

int flush_to_file(FILE* fptr, struct Node* head); 

#endif
