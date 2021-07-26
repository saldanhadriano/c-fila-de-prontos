#ifndef EVENT_LIST_H_INCLUDED
#define EVENT_LIST_H_INCLUDED

//includes
/////////////////////////////////////////
#include "event.h"

//public variables
/////////////////////////////////////////
Event_struct *event_list;

//prototypes
/////////////////////////////////////////
int EventList_Init();
int EventList_isEmpty();
void EventList_remove_first();
void EventList_append(Event_struct *item);
void EventList_add(Event_struct *item);
void EventList_add_after(Event_struct *item, int location);
void EventList_insert(Event_struct *item);
int EventList_count();
void Event_print(Event_struct *item);
void EventList_print();

#endif // EVENT_LIST_H_INCLUDED
