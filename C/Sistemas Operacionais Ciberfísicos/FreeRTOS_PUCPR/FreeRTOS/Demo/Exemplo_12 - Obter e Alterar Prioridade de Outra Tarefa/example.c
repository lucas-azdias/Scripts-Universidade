#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

/* Defini��o do identificador (handle) para tarefa 2. */
xTaskHandle xTask2Handle;

int main_(void)
{
	/* 
	- Criando a tarefa 1 com prioridade 2 
	- N�o � passado nenhum parametros para esta fun��o, definido com NULL
	- O identificador (handle) de tarefa tamb�m n�o � usado, definido como NULL 
	*/
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 2, NULL);

	/* 
	 - Criando a tarefa 2 com prioridade 1, tendo menor prioridade que a tarefa 1
	 - N�o � passado parametros para esta fun��o, definido com NULL
	 - Para identificar a tarefa � passado o endere�o da vari�vel xTask2Handle
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
	A tarefa 1 ser� executada antes da tarefa 2, pois possui maior prioridade.
	As Tarefas 1  e 2 n�o bloqueiam (n�o fazem a chamada para fun��o delay), 
	ent�o estar�o ou no estado	executando ou de pronto.

	A fun��o uxTaskPriorityGet() permite verificar a prioridade da tarefa em execu��o.
	A passagem do parametro NULL devolve a prioridade da pr�pria tarefa."	
	*/
	uxPriority = uxTaskPriorityGet(NULL);

	for (;; )
	{
	
		vPrintString("Tarefa 1 executando\n");

		/* 
		A fun��o vTaskPrioritySet() permite aumentar a prioridade da tarefa 2,
		Ao definir a prioridade da tarefa 2 acima da prioridade da tarefa 1 a tarefa 2 passar� imediatamente a ser executada.	
		*/
		vTaskPrioritySet(xTask2Handle, (uxPriority + 1));
		/* A Tarefa1 s� ser� executada  novamente quando tiver uma prioridade maior que a Tarefa 2.*/
	}
}

void vTask2(void *pvParameters)
{
	unsigned portBASE_TYPE uxPriority;

	/*
	A fun��o uxTaskPriorityGet() permite verificar a prioridade da tarefa em execu��o.
	A passagem do parametro NULL devolve a prioridade da pr�pria tarefa." 
	
	*/
	uxPriority = uxTaskPriorityGet(NULL);

	for (;; )
	{
		
		vPrintString("Tarefa 2 executando\n");

		/* 
		A fun��o vTaskPrioritySet() permite retornar o valor da prioridade original da tarefa 2. 
		Ao passar o parametro NULL como o identificador da tarefa ela altera sua pr�pria prioridade". 
		Configurando a prioridade abaixo da Tarefa1 far� com que a mesma passe imediatamente a ser executada. 
		*/
		vTaskPrioritySet(NULL, (uxPriority - 2));
	}
}
