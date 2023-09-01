#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask(void *pvParameters);

const char *msgTask1 = "Tarefa - Instancia 1\n";
const char *msgTask2 = "Tarefa - Instancia 2\n";

void vTask(void* pvParameters)
{
	char* msgTask;

	msgTask = (char*)pvParameters;

	for (;; )
	{
		vPrintString(msgTask);

		/*
		 - Atraso por um per�odo.
		 - A chamada da fun��o vTaskDelay () coloca a tarefa no estado bloqueado at� que o per�odo de atraso expire.
		 - O per�odo de atraso � especificado em 'ticks  */
		vTaskDelay(250 / portTICK_RATE_MS);
	}
}

int main_(void)
{

	xTaskCreate(vTask, "Task 1", 1000, (void*)msgTask1, 1, NULL);
	xTaskCreate(vTask, "Task 2", 1000, (void*)msgTask2, 2, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}


