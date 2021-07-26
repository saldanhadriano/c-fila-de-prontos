//includes
/////////////////////////////////////////
#include "main.h"
#include "utilities.h"
#include "ready_list.h"
#include "event_list.h"

//main program
/////////////////////////////////////////
int main()
{
	srand(time(NULL));

    if(!EventList_Init())
    {
        printf("error\n");
        exit(1);
    }
    else
    {
		create_event_list();

		simulate();
    }
	
    return 0;
}

void simulate()
{
	Event_struct *current_event;

	ReadyList_Init();

	while (!EventList_isEmpty()) 
	{
		current_event = event_list->next;
		clock = current_event->time;

		clock_print(current_event);

		switch (current_event->event_type) 
		{
			case NEW_PROCESS:
				event_new_process(current_event);
				break;
			case END_CPU:
				event_end_cpu(current_event);
				break;
			case END_IO:
				event_end_io(current_event);
				break;
		}

		EventList_remove_first();
	}

	printf("simulação executada\n");
	//show_results();
}


void event_end_cpu(Event_struct *event)
{
	//Se o numero de ciclos ja executados e maior ou igual ao numero de ciclos necessarios (ultimo ciclo)
	if (event->process->cycles >= event->process->num_cycles)
	{
		//Contabiliza
		//ReadyList_remove_first();
		event->process = NULL;
		free(event->process);
	}
	else
	{
		//Gera evento FIM_ES
		Event_struct *new_event = (Event_struct*)malloc(sizeof(Event_struct));
		
		if (!event->process->type) //CPU-BOUND
			new_event->time = event->time + rand() % 200 + 50; //Between 50 and 200 
		else //IO-BOUND
			new_event->time = event->time + rand() % 600 + 200; //Between 200 and 600 

		new_event->event_type = END_IO;
		new_event->process = event->process;
		new_event->next = NULL;

		EventList_insert(new_event);

		//Retira processo da fila de prontos
		ReadyList_remove_first();

		if (!ReadyList_isEmpty())
		{
			//Gera evento FIM_CPU
			Event_struct *n_event = (Event_struct*)malloc(sizeof(Event_struct));
			n_event->time = new_event->time + event->process->timeslice;
			n_event->event_type = END_CPU;
			n_event->process = event->process;
			n_event->next = NULL;

			EventList_insert(n_event);
		}
		else
		{
			return;
		}
	}
}


void clock_print(Event_struct *event)
{
	printf("Clock: %d\n", clock);
	printf("Evento: %d ", event->time);
	switch (event->event_type)
	{
	case NEW_PROCESS:
		printf("NOVO_PROCESSO\n");
		break;
	case END_CPU:
		printf("FIM_CPU\n");
		break;
	case END_IO:
		printf("FIM_IO\n");
		break;
	}
	printf("Processo: %u %u %u %u/%u\n", event->process->num, event->process->timeslice, event->process->type, event->process->cycles, event->process->num_cycles);
}


