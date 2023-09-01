
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask1(void *pvParameters);
void vTask2(void* pvParameters);


void vTask1(void *pvParameters)
{
	for (;; )
	{
		vPrintString("Task 1\n");

		vTaskDelay(500);
		
	}

	vTaskDelete(NULL);
}

void vTask2(void* pvParameters)
{
	for (;; )
	{
		vPrintString("Task 2\n");

		vTaskDelay(500);

	}

	vTaskDelete(NULL);
}

int main_(void)
{

	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}
