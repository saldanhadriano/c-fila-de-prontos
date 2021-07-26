#ifndef PCB_H_INCLUDED
#define PCB_H_INCLUDED

//special data type
/////////////////////////////////////////
typedef struct PCB_struct{
	unsigned num;
	unsigned timeslice;
	unsigned type;
	unsigned num_cycles;
	unsigned cycles;
	unsigned long arrival_time;
	unsigned long queue_time;
	unsigned long waiting_time;
	struct PCB_struct *next;
}PCB_struct;


#endif // PCB_H_INCLUDED
