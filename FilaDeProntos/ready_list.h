#ifndef READY_LIST_H_INCLUDED
#define READY_LIST_H_INCLUDED

//includes
/////////////////////////////////////////
#include "pcb.h"

//public variables
/////////////////////////////////////////
PCB_struct *ready_list;


//prototypes
/////////////////////////////////////////
int ReadyList_Init();
int ReadyList_isEmpty();
void ReadyList_append(PCB_struct *item);
void ReadyList_remove_first();
int ReadyList_count();
void ReadyList_print();

#endif // READY_LIST_H_INCLUDED
