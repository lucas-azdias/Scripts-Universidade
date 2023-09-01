#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

/* Definição do identificador (handle) para tarefa 2. */
xTaskHandle xTask2Handle;

int main_(void)
{
	/* 
	- Criando a tarefa 1 com prioridade 2 
	- Não é passado nenhum parametros para esta função, definido com NULL
	- O identificador (handle) de tarefa também não é usado, definido como NULL 
	*/
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 2, NULL);

	/* 
	 - Criando a tarefa 2 com prioridade 1, tendo menor prioridade que a tarefa 1
	 - Não é passado parametros para esta função, definido com NULL
	 - Para identificar a tarefa é passado o endereço da variável xTask2Handle
	 */
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, &xTask2Handle);
	
	vTaskStartScheduler();

	for (;; );
	return 0;
}
/*-----------------------------------------------------------*/

void vTask1(void *pvParameters)
{
	unsigned portBASE_TYPE uxPriority;

	/*
	A tarefa 1 será executada antes da tarefa 2, pois possui maior prioridade.
	As Tarefas 1  e 2 não bloqueiam (não fazem a chamada para função delay), 
	então estarão ou no estado	executando ou de pronto.

	A função uxTaskPriorityGet() permite verificar a prioridade da tarefa em execução.
	A passagem do parametro NULL devolve a prioridade da própria tarefa."	
	*/
	uxPriority = uxTaskPriorityGet(NULL);

	for (;; )
	{
	
		vPrintString("Tarefa 1 executando\n");

		/* 
		A função vTaskPrioritySet() permite aumentar a prioridade da tarefa 2,
		Ao definir a prioridade da tarefa 2 acima da prioridade da tarefa 1 a tarefa 2 passará imediatamente a ser executada.	
		*/
		vTaskPrioritySet(xTask2Handle, (uxPriority + 1));
		/* A Tarefa1 só será executada  novamente quando tiver uma prioridade maior que a Tarefa 2.*/
	}
}

void vTask2(void *pvParameters)
{
	unsigned portBASE_TYPE uxPriority;

	/*
	A função uxTaskPriorityGet() permite verificar a prioridade da tarefa em execução.
	A passagem do parametro NULL devolve a prioridade da própria tarefa." 
	
	*/
	uxPriority = uxTaskPriorityGet(NULL);

	for (;; )
	{
		
		vPrintString("Tarefa 2 executando\n");

		/* 
		A função vTaskPrioritySet() permite retornar o valor da prioridade original da tarefa 2. 
		Ao passar o parametro NULL como o identificador da tarefa ela altera sua própria prioridade". 
		Configurando a prioridade abaixo da Tarefa1 fará com que a mesma passe imediatamente a ser executada. 
		*/
		vTaskPrioritySet(NULL, (uxPriority - 2));
	}
}
