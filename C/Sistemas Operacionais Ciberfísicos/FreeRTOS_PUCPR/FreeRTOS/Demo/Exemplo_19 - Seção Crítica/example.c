#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"
#include <time.h>
#include <stdlib.h>

// Definindo o protótipo das tarefas 
void vTask1(void *pvParameters);
void vTask2(void* pvParameters);

void vPrintStringAndFloat(const portCHAR* pcString, const float);

float max = 41.0;
float min = 34.0;

void vPrintStringAndFloat(const portCHAR* pcString, const float pcFloat)
{
	/* 
	   A função taskENTER_CRITICAL() é utilizado para definir o acesso a uma seção crítica.
	*/
	taskENTER_CRITICAL();
	{
		printf("%s %.2f\n", pcString,pcFloat);
		fflush(stdout);
	}
	/*
	   A função taskEXIT_CRITICAL() é utilizado para encerrar o acesso a uma seção crítica.
	*/
	taskEXIT_CRITICAL();
	
	/* A função abaixo captura se alguma tecla foi pressionada, na sequência é interrompido a execução do aplicativo. 
	   Em uma aplicação RTOS real o valor da chave deve proteger o acesso à entrada do teclado. 
	 */
	if (kbhit())
	{
	/*
		A função vTaskEndScheduler() encerra o escalonador.
	*/
		vTaskEndScheduler();
	}
}

int main_(void)
{
	
		xTaskCreate(vTask1,"Task 1", 1000, NULL, 1, NULL);
		xTaskCreate(vTask2,"Task 2", 1000, NULL, 1, NULL);

		vTaskStartScheduler();

	for (;; );
	return 0;
}

void vTask1(void* pvParameters)
{
	
	for (;; )
	{
		// Abaixo um exemplo como gerar um número do tipo float aleatório entre uma faixa de valores.
		float temperatura = (((float)rand() / (float)(RAND_MAX)) * (max - min)) + min;

		// Definido uma função segura para ímprimir a saída no console - imprime uma string e um float. 
		vPrintStringAndFloat("Task 1 - Temperatura: ",temperatura);

		vTaskDelay(portTICK_RATE_MS * 100);
	}
	vTaskDelete(NULL);
}

void vTask2(void* pvParameters)
{

	for (;; )
	{
		// Abaixo um exemplo como gerar um número do tipo float aleatório entre uma faixa de valores.
		float temperatura = (((float)rand() / (float)(RAND_MAX)) * (max - min)) + min;

		// Definido uma função segura para ímprimir a saída no console - imprime uma string e um float. 
		vPrintStringAndFloat("Task 2 - Temperatura: ", temperatura);

		vTaskDelay(portTICK_RATE_MS * 100);
	}
	vTaskDelete(NULL);
}
