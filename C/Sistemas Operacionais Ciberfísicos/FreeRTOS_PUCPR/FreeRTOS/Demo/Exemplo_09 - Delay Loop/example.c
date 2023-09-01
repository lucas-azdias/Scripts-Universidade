
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

// Definição da constante DELAY_LOOP_COUNT para o 
#define DELAY_LOOP_COUNT		( 0xffffff )

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);


int main_(void)
{
	
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}
/*-----------------------------------------------------------*/

void vTask1(void *pvParameters)
{
	const char *msg = "Tarefa 1 executando!!!\n";
	volatile unsigned long i;

	for (;; )
	{
		vPrintString(msg);

		// Definição de um delay por um periodo
		for (i = 0; i < DELAY_LOOP_COUNT; i++)
		{
			/*
			Este loop é apenas uma implementação de atraso alternativa para uma implementação da função de atraso.
			Dentro do loop não se espera nenhuma ação.
			*/
		}
	}
}

void vTask2(void *pvParameters)
{
	const char *msg = "Tarefa 2 executando!!!\n";
	volatile unsigned long i;

	for (;; )
	{
		vPrintString(msg);

		// Definição de um delay por um periodo
		for (i = 0; i < DELAY_LOOP_COUNT; i++)
		{
			/* 
			Este loop é apenas uma implementação de atraso alternativa para uma implementação da função de atraso.
			Dentro do loop não se espera nenhuma ação.
			*/
		}
	}
}


