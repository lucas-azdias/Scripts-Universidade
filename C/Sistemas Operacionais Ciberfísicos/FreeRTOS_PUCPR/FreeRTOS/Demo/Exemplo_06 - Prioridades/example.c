
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

#define DELAY_LOOP_COUNT		( 0xffffff )

void vTask(void *pvParameters);

void vTask(void *pvParameters)
{
	char* msg = (char*)pvParameters;
	volatile unsigned long i;
	for (;; )
	{
		vPrintString(msg);

		for (i = 0; i < DELAY_LOOP_COUNT; i++) {}

		// Isso já consegue liberar tempo para outra tarefa de menor prioridade executar
		// vTaskDelay(5);
	}

	vTaskDelete(NULL);
}

int main_(void)
{
	static const char* msg1 = "Tarefa - Instancia 1\n";
	static const char* msg2 = "Tarefa - Instancia 2\n";

	xTaskCreate(vTask, "Task 1", 1000, (void*) msg1, 1, NULL);
	xTaskCreate(vTask, "Task 2", 1000, (void*) msg2, 2, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}
