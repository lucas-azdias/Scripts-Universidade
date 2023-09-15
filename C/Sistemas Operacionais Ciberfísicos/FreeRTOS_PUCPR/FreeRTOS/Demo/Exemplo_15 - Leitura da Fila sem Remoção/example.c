#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "basic_io.h"

static void vSenderTask(void *pvParameters);
static void vReceiverTask(void* pvParameters);

xQueueHandle fila;

int main_(void)
{			
		fila = xQueueCreate(5, sizeof(long));

		//Cria Tarefa Sender, instância 1 com prioridade UM (1) no core (0)
		xTaskCreate(vSenderTask, "Tarefa Enviar 1", 1000, (void*)100, 1, NULL, 0);
		//Cria Tarefa Sender, instância 2 com prioridade UM (1) no core (1)
		xTaskCreate(vSenderTask, "Tarefa Enviar 2", 1000, (void*)200, 1, NULL, 1);

		//Tarefa Receiver com prioridade 2
		xTaskCreate(vReceiverTask, "Tarefa Receber", 1000, NULL, 2, NULL);

		/* Start the scheduler so the created tasks start executing. */
		vTaskStartScheduler();
	for (;; );

	return 0;
}

static void vSenderTask(void *pvParameters)
{
	long lValueToSend;
	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	lValueToSend = (long)pvParameters;

	for (;; )
	{
		xStatus = xQueueSendToBack(fila, &lValueToSend, xTicksToWait);

		if (xStatus != pdPASS)
		{
			vPrintString("Could not send to the queue.\r\n");
		}

		taskYIELD();
	}
}

static void vReceiverTask(void *pvParameters)
{
	long lendoValor;
	long recebendoValor;

	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 200 / portTICK_RATE_MS;

	for (;; )
	{

		if (uxQueueMessagesWaiting(fila) != 0)
		{
			vPrintString("Queue should have been empty!\r\n");
		}
		// A função xQueuePeek() permite ler uma valor da fila sem remover. 
		xQueuePeek(fila, &lendoValor, xTicksToWait);
		xStatus = xQueueReceive(fila, &recebendoValor, xTicksToWait);
		
		if (xStatus == pdPASS)
		{
			vPrintStringAndNumber("Apenas lendo um valor da fila = ", lendoValor);
			vPrintStringAndNumber("Recebendo valor = ", recebendoValor);
		}
		else
		{
			vPrintString("Could not receive from the queue.\r\n");
		}
	}
}
