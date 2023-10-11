#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"
#include "croutine.h"

// Definição do protótipo da tarefa
void vTask(void* pvParemeters);

// Definição do protótipo das corrotinas
void vCoRoutine1(xCoRoutineHandle xHandle, unsigned portBASE_TYPE uxIndex);
void vCoRoutine2(xCoRoutineHandle xHandle, unsigned portBASE_TYPE uxIndex);

// Definição do protótipo da função de hook
void vApplicationIdleHook(void);

int main_(void)
{
	//Criando duas corrotinas diferentes ambas com a mesma prioridade
	xCoRoutineCreate(vCoRoutine1, 1, "Corrotina 1\n");
	xCoRoutineCreate(vCoRoutine2, 1, "Corrotina 2\n");

	//Criando uma tarefa com maior prioridade que as corrotinas
	xTaskCreate(vTask, "Task", 1000, NULL, 2, NULL);

	//Inicializando o escalonador de tarefas 
	vTaskStartScheduler();

	for (;; );
	return 0;
}

void vTask(void* pvParemeters)
{

	for (;; )
	{	
		// Imprimindo uma quebra de linha
		vPrintString("\n");
		
		// Imprimindo uma mensagem para tarefa
		vPrintString("Task\n");

		// Gerando um delay de 10ms
		vTaskDelay(100);
	}
	// Excluindo explicitamente a tarefa
	vTaskDelete(NULL);
}


void vCoRoutine1(xCoRoutineHandle xHandle, unsigned portBASE_TYPE uxIndex)
{
	// Inicializando a corrotina
	crSTART(xHandle);

	for (;; )
	{
		// Imprime o valor passado por parametro na criação da corrotina
		vPrintString(uxIndex);

		// Liberando o processador para exeecução de outras corrotinas - delay de 100ms.
		crDELAY(xHandle, 100);
	}

	// Encerrando explicitamente uma corrotina
	crEND();
}

void vCoRoutine2(xCoRoutineHandle xHandle, unsigned portBASE_TYPE uxIndex)
{

	// Inicializando a corrotina
	crSTART(xHandle);

	for (;; )
	{
		// Imprime o valor passado por parametro na criação da corrotina
		vPrintString(uxIndex);

		// Liberando o processador para exeecução de outras corrotinas - delay de 100ms.
		crDELAY(xHandle, 100);
	}

	// Encerrando explicitamente uma corrotina
	crEND();
}

/* 
A função de hook deve ser chamadas de vApplicationIdleHook () - intercepta a tarefa e corrotinas enquanto estão ociosas. 
Esta função não aceitam parâmetros e deve retornar um void.
*/
void vApplicationIdleHook(void)
{
	// Estamos utilizando a função de hook para chamar o escalonador
	vCoRoutineSchedule();
}



