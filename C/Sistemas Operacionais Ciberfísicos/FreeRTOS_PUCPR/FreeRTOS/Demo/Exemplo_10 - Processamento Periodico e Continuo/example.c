#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);


const char *msgTask1 = "Tarefa continua 1!\n";
const char *msgTask2 = "Tarefa continua 2!\n";

const char *msgPeriodicTask = "### Tarefa periodica! ###\n";

// Tarefa de processamento continuo
void vTask1(void* pvParameters)
{
	char* msgTask;

	msgTask = (char*)pvParameters;

	for (;;)
	{
		vPrintString(msgTask);
	}
	vTaskDelete(NULL);
}
/*-----------------------------------------------------------*/

//Tarefa com processamento periódico
void vTask2(void* pvParameters)
{

	char* msgTask = (char*)pvParameters;

	portTickType xLastWakeTime;

	/* 
	   - A variável xLastWakeTime deve ser inicializada com o tick atual;
       - Observe que esta é a única vez que acessamos esta variável; 
	   - Posteriormente a variável xLastWakeTime é gerenciado automaticamente pela função vTaskDelayUntil().
	*/
	xLastWakeTime = xTaskGetTickCount();

	printf("%f ", (float)xLastWakeTime);

	for (;;)
	{
		vPrintString(msgTask);

		/* Esta tarefa será executada exatamente a cada 10 milissegundos. */
		vTaskDelayUntil(&xLastWakeTime, (10 / portTICK_RATE_MS));
	}
}

int main_(void)
{
	/* Criando duas instâncias de uma tarefa contínua com prioridade 1. */
	xTaskCreate(vTask1, "Instancia Tarefa 1", 1000, (void*) msgTask1, 1, NULL);
	xTaskCreate(vTask1, "Instancia Tarefa 2", 1000, (void*) msgTask2, 1, NULL);

	/* Criando uma instância de uma tarefa periódica com prioridade 2. */
	xTaskCreate(vTask2, "Instancia Tarefa 3", 1000, (void*)msgPeriodicTask, 2, NULL);

	/* Iniciando o escalonador */
	vTaskStartScheduler();

	for (;;);
	return 0;
}





