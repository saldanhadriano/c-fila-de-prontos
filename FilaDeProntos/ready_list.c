//includes
/////////////////////////////////////////
#include "ready_list.h"
#include "utilities.h"


//verify if the ready_list is empty
/////////////////////////////////////////
int ReadyList_isEmpty()
{
	if(ready_list->next == NULL)
		return TRUE;
	else
		return FALSE;
}


//remove the first item on the ready_list
/////////////////////////////////////////
void ReadyList_remove_first()
{
	if (ready_list->next == NULL) {
		printf("Lista ja esta vazia\n");
		return NULL;
	}
	else {
		PCB_struct *tmp = ready_list->next;
		ready_list->next = tmp->next;
	}
}

//count the number of pcbs on the ready_list
/////////////////////////////////////////
int ReadyList_count()
{
	int c = 0;

	PCB_struct *tmp;
	tmp = ready_list->next;

	while (tmp != NULL)
	{
		printf("temp: %u\n", tmp->num);
		tmp = tmp->next;
		c++;
	}

	return c;
}
