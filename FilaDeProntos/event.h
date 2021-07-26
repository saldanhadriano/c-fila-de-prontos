#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

//includes
/////////////////////////////////////////
#include "pcb.h"

//special data type
/////////////////////////////////////////
typedef enum Event_Type {
	NEW_PROCESS,
	END_CPU,
	END_IO
}Event_Type;


typedef struct Event_struct{
	unsigned long time;
	unsigned event_type;
	PCB_struct *process;
	struct Event_struct *next;
}Event_struct;

#endif // EVENT_H_INCLUDED
