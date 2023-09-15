#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 Defin��o do prot�tipo das tarefas
*/
void vExampleISR(void);
void vTask1(void* pvParameters);
void vTask2(void* pvParameters);

/*
 Identificador Handler para as Tarefas 1 e 2.
*/
TaskHandle_t taskHandle1 = NULL;
TaskHandle_t taskHandle2 = NULL;

void vTask1(void* pvParameters)
{
	for (;; )
	{
		vPrintString("Task 1 - Begin\n");

		// Gerando a simula��o de uma interrup��o
		vPortGenerateSimulatedInterrupt(3);
		
		vPrintString("Task 1 - End\n");
		printf("\n");
		
		// Criando um delay de 1000ms
		vTaskDelay(1000);
	}
}

void vTask2(void* pvParameters) 
{
	for (;; )
	{
		// A tarefa se suspende
		vTaskSuspend(NULL);
		// A tarefa agora est� suspensa, ent�o dever� chegar neste ponto apenas quando a ISR (rotina de servi�o de interrup��o) retornar.
		vPrintString("Task 2 - Interruption\n");
	}
}

void vExampleISR(void) {

	BaseType_t checkIfYieldRequired;
	// Retoma a tarefa suspensa. 
	checkIfYieldRequired = xTaskResumeFromISR(taskHandle2);

	if (checkIfYieldRequired == pdTRUE)
	{
		// A fun��o portYIELD_FROM_ISR() permite mudar de contexto para que o ISR retorne para uma tarefa diferente.
		portYIELD_FROM_ISR(checkIfYieldRequired);
	}
}


int main_(void)
{
	/*
		Criando duas tarefas, cada tarefa possui seu pr�prio identificador handler 
	*/
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, &taskHandle1);
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, &taskHandle2);

	/* A fun��o vPortSetInterruptHandler() permite setar uma interrup��o.
	   - O primeiro par�metro corresponde ao identificador da interrup��o, esta faixa de valores pode ser configurado de 3 a 31 sendo poss�vel simular um total de 29 interrup��es.
	   - O segundo par�metro manipula a fun��o que gera a interrup��o. 
	*/
	vPortSetInterruptHandler(3, vExampleISR);

	// Inicializa o escalonador 
	vTaskStartScheduler();

	for (;; );
}