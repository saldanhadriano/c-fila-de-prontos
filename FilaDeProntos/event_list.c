//includes
/////////////////////////////////////////
#include "event_list.h"
#include "utilities.h"

//initiate the event_list with header
/////////////////////////////////////////
//verify if the event_list is empty
/////////////////////////////////////////
int EventList_isEmpty()
{
	if(event_list->next == NULL)
		return TRUE;
	else
		return FALSE;
}

//add an event to the end of the event_list
//////////////////////////////////////////
void EventList_append(Event_struct *item)
{
	Event_struct *tmp = event_list->next;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = item;
	tmp = item;
	tmp->next = NULL;
}

//add an event to the beginning of the event_list
//////////////////////////////////////////
void EventList_add(Event_struct *item)
{
	if (EventList_isEmpty())
	{
		event_list->next = item;
		item->next = NULL;
	}
	else
	{
		item->next = event_list->next;
		event_list->next = item;
	}
}

//add an event to the middle of the event_list at specified location
void EventList_add_after(Event_struct *item, int location)
{
	int i;
	Event_struct *left = NULL, *right = NULL;

	right = event_list->next;

	for (i = 1; i < location; i++)
	{
		left = right;
		right = right->next;
	}

	left->next = item;
	left = item;
	left->next = right;
}

//insert a single event into the event_list
/////////////////////////////////////////
void EventList_insert(Event_struct *item)
{
	int c = 0;

	if (EventList_isEmpty())
	{
		EventList_add(item);
	}
	else 
	{
		Event_struct *tmp = event_list->next;

		while (tmp != NULL)
		{
			if (tmp->time < item->time)
				c++;
			tmp = tmp->next;
		}

		if (c == 0)
			EventList_add(item);
		else if (c < EventList_count())
			EventList_add_after(item, ++c);
		else
			EventList_append(item);
	}
}


//count the number of events on the event_list
/////////////////////////////////////////
int EventList_count()
{
	int c = 0;

	Event_struct *tmp;
	tmp = event_list->next;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		c++;
	}

	return c;
}

//print a single event
/////////////////////////////////////////
void Event_print(Event_struct *item)
{
	printf("Evento:\n");
	printf("Tempo: %lu\n", item->time);
	printf("Tipo: %u\n", item->event_type);
	printf("Processo: %u\n", item->process->num);
}
