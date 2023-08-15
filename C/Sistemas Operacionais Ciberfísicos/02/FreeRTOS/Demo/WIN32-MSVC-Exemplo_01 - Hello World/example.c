
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 1 - O prot�tipo da fun��o de uma tarefa deve sempre retornar void, ou seja, a tarefa n�o possui retorno.
 2 - A fun��o de uma tarefa deve receber um par�metro de ponteiro void. 
*/
void myTask(void *pvParameters);
void myTask2(void* pvParameters);
void myTask3(void* pvParameters);

/*
 Deni��o da estrutura da fun��o
*/
void myTask(void *pvParameters)
{

	const char *hello = "Hello World!!!\n";

	printf("Esta linha sera executada uma unica vez!!\n");

	for (;; )
	{
		vPrintString(hello);
		vTaskDelay(1000);
		
	}

	// Quando uma tarefa n�o for mais necess�ria, ela dever� ser exclu�da explicitamente.
	vTaskDelete(NULL);
}

void myTask2(void* pvParameters)
{
	vPrintString("TASK 2 STARTED!\n");

	for (;;)
	{
		vPrintString("TASK 2 RUNNING...\n");
		vTaskDelay(1000);
	}

	vTaskDelete(NULL);
}

void myTask3(void* pvParameters)
{
	vPrintString("TASK 3 STARTED!\n");

	for (;;)
	{
		vPrintString("TASK 3 RUNNING...\n");
		vTaskDelay(1000);
	}

	vTaskDelete(NULL);
}

int main_(void)
{

	xTaskCreate(myTask, "Task Hello", 1000, NULL, 1, NULL);
	xTaskCreate(myTask2, "Task 2", 1000, NULL, 1, NULL);
	xTaskCreate(myTask3, "Task 3", 1000, NULL, 1, NULL);

	// Inicia o escalonador de tarefas
	vTaskStartScheduler();

	for (;; );
	return 0;
}
