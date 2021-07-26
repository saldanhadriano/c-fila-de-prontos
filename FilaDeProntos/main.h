#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

//includes
/////////////////////////////////////////
#include "event.h"

//public variables
/////////////////////////////////////////
int clock = 0;

//prototypes
/////////////////////////////////////////
void create_event_list();
void simulate();
void event_new_process(Event_struct *event);
void event_end_cpu(Event_struct *event);
void event_end_io(Event_struct *event);
void clock_print(Event_struct *event);

#endif // MAIN_H_INCLUDED
