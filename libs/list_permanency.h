#ifndef PERMANENT_LISTS
#define PERMANENT_LISTS
#include "linked_ist.h"

FILE* create_list(char* file_name);

struct Node* load_list(char* file_name);

int flush_to_file(FILE* fptr, struct Node* head); 

#endif
