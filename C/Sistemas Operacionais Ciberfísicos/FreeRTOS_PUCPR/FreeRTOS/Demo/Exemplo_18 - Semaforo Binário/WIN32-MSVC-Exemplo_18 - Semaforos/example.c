#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "basic_io.h"
#include <time.h>
#include <stdlib.h>

// Definindo o prot�tipo das tarefas 
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

// Criando a vari�vel para o sem�foro
xSemaphoreHandle xSemaphore = NULL;

// Criando uma vari�vel buffer para ma
char buffer[7];

int main_(void)
{
		// Fun��o para criar um sem�foro bin�rio
	    vSemaphoreCreateBinary(xSemaphore);

		// Criando duas tarefas 
		xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
		xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, NULL);

		// Inicializa o escalonador
		vTaskStartScheduler();

	for (;; );
	return 0;
}

void vTask1(void* pvParameters)
{

	for (;; )
	{
		// Verificando se o sem�foro foi criado antes de utiliz�-lo
		if (xSemaphore != NULL) {

			/* A fun��o xSemaphoreTake() verifica se o sem�foro est� dispon�vel, caso o sem�foro esteja  dispon�vel ele obt�m o sem�foro
			   Caso o sem�foro estiver sendo utilizado este aguarde 10 ticks para ver o sem�foro � liberado.
			   A fun��o xSemaphoreTake() recebe dois par�metros:
			   - O primeiro par�metro corresponde ao sem�foro
			   - O segundo par�metro corresponde o tempo que a fun��o deve aguardar caso o sem�foro j� esteja sendo utilizado.
			*/
			if (xSemaphoreTake(xSemaphore, (portTickType)10) == pdTRUE) {
				
				sprintf(buffer, "Task 1\n");
				vPrintString(buffer);
				
				/*
				A fun��o xSemaphoreGive() permite liberar o uso do sem�foro
				*/
				xSemaphoreGive(xSemaphore);
			}
		}
		else
		{
			// imprime a mensagem caso o sem�foro n�o tenha sido criado
			printf("O sem�foro n�o foi criado\n");
		}
		// Efetua um delay na tarefa a cada 100 ticks
		vTaskDelay(portTICK_RATE_MS * 100);
	}

	// A fun��o vTaskDelete() permite liberar explicitamente a tarefa
	vTaskDelete(NULL);
}

void vTask2(void* pvParameters)
{

	for (;; )
	{
		
		if (xSemaphore != NULL) {

			/* A fun��o xSemaphoreTake() verifica se o sem�foro est� dispon�vel, caso o sem�foro esteja  dispon�vel ele obt�m o sem�foro 
			   Caso o sem�foro estiver sendo utilizado este aguarde 10 ticks para ver o sem�foro � liberado.
			   A fun��o xSemaphoreTake() recebe dois par�metros:
			   - O primeiro par�metro corresponde ao sem�foro
			   - O segundo par�metro corresponde o tempo que a fun��o deve aguardar caso o sem�foro j� esteja sendo utilizado.
			*/
			if (xSemaphoreTake(xSemaphore, (portTickType)10) == pdTRUE) {

				sprintf(buffer, "Task 2\n");
				vPrintString(buffer);
				/*
				A fun��o xSemaphoreGive() permite liberar o uso do sem�foro
				*/
				xSemaphoreGive(xSemaphore);
			}
		}
		else
		{
			// imprime a mensagem caso o sem�foro n�o tenha sido criado
			printf("O sem�foro n�o foi criado\n");
		}
		// Efetua um delay na tarefa a cada 100 ticks
		vTaskDelay(portTICK_RATE_MS * 100);
	}
	// A fun��o vTaskDelete() permite liberar explicitamente a tarefa
	vTaskDelete(NULL);
}
