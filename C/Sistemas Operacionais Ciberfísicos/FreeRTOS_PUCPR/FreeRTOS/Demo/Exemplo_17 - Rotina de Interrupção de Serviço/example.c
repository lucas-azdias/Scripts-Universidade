#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 Definção do protótipo das tarefas
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

		// Gerando a simulação de uma interrupção
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
		// A tarefa agora está suspensa, então deverá chegar neste ponto apenas quando a ISR (rotina de serviço de interrupção) retornar.
		vPrintString("Task 2 - Interruption\n");
	}
}

void vExampleISR(void) {

	BaseType_t checkIfYieldRequired;
	// Retoma a tarefa suspensa. 
	checkIfYieldRequired = xTaskResumeFromISR(taskHandle2);

	if (checkIfYieldRequired == pdTRUE)
	{
		// A função portYIELD_FROM_ISR() permite mudar de contexto para que o ISR retorne para uma tarefa diferente.
		portYIELD_FROM_ISR(checkIfYieldRequired);
	}
}


int main_(void)
{
	/*
		Criando duas tarefas, cada tarefa possui seu próprio identificador handler 
	*/
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, &taskHandle1);
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, &taskHandle2);

	/* A função vPortSetInterruptHandler() permite setar uma interrupção.
	   - O primeiro parâmetro corresponde ao identificador da interrupção, esta faixa de valores pode ser configurado de 3 a 31 sendo possível simular um total de 29 interrupções.
	   - O segundo parâmetro manipula a função que gera a interrupção. 
	*/
	vPortSetInterruptHandler(3, vExampleISR);

	// Inicializa o escalonador 
	vTaskStartScheduler();

	for (;; );
}