#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "basic_io.h"
#include <time.h>
#include <stdlib.h>

// Definindo o protótipo das tarefas 
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

// Criando a variável para o semáforo
xSemaphoreHandle xSemaphore = NULL;

// Criando uma variável buffer para ma
char buffer[7];

int main_(void)
{
		// Função para criar um semáforo binário
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
		// Verificando se o semáforo foi criado antes de utilizá-lo
		if (xSemaphore != NULL) {

			/* A função xSemaphoreTake() verifica se o semáforo está disponível, caso o semáforo esteja  disponível ele obtém o semáforo
			   Caso o semáforo estiver sendo utilizado este aguarde 10 ticks para ver o semáforo é liberado.
			   A função xSemaphoreTake() recebe dois parâmetros:
			   - O primeiro parâmetro corresponde ao semáforo
			   - O segundo parâmetro corresponde o tempo que a função deve aguardar caso o semáforo já esteja sendo utilizado.
			*/
			if (xSemaphoreTake(xSemaphore, (portTickType)10) == pdTRUE) {
				
				sprintf(buffer, "Task 1\n");
				vPrintString(buffer);
				
				/*
				A função xSemaphoreGive() permite liberar o uso do semáforo
				*/
				xSemaphoreGive(xSemaphore);
			}
		}
		else
		{
			// imprime a mensagem caso o semáforo não tenha sido criado
			printf("O semáforo não foi criado\n");
		}
		// Efetua um delay na tarefa a cada 100 ticks
		vTaskDelay(portTICK_RATE_MS * 100);
	}

	// A função vTaskDelete() permite liberar explicitamente a tarefa
	vTaskDelete(NULL);
}

void vTask2(void* pvParameters)
{

	for (;; )
	{
		
		if (xSemaphore != NULL) {

			/* A função xSemaphoreTake() verifica se o semáforo está disponível, caso o semáforo esteja  disponível ele obtém o semáforo 
			   Caso o semáforo estiver sendo utilizado este aguarde 10 ticks para ver o semáforo é liberado.
			   A função xSemaphoreTake() recebe dois parâmetros:
			   - O primeiro parâmetro corresponde ao semáforo
			   - O segundo parâmetro corresponde o tempo que a função deve aguardar caso o semáforo já esteja sendo utilizado.
			*/
			if (xSemaphoreTake(xSemaphore, (portTickType)10) == pdTRUE) {

				sprintf(buffer, "Task 2\n");
				vPrintString(buffer);
				/*
				A função xSemaphoreGive() permite liberar o uso do semáforo
				*/
				xSemaphoreGive(xSemaphore);
			}
		}
		else
		{
			// imprime a mensagem caso o semáforo não tenha sido criado
			printf("O semáforo não foi criado\n");
		}
		// Efetua um delay na tarefa a cada 100 ticks
		vTaskDelay(portTICK_RATE_MS * 100);
	}
	// A função vTaskDelete() permite liberar explicitamente a tarefa
	vTaskDelete(NULL);
}
