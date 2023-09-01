
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask(void *pvParameters);

void vTask(void *pvParameters)
{
	char* msg = (char*)pvParameters;
	for (;; )
	{
		vPrintString(msg);

		vTaskDelay(500);
		
	}

	vTaskDelete(NULL);
}

int main_(void)
{
	static const char* msg1 = "Tarefa - Instancia 1\n";
	static const char* msg2 = "Tarefa - Instancia 2\n";

	xTaskCreate(vTask, "Task 1", 1000, (void*) msg1, 1, NULL);
	xTaskCreate(vTask, "Task 2", 1000, (void*) msg2, 1, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}
