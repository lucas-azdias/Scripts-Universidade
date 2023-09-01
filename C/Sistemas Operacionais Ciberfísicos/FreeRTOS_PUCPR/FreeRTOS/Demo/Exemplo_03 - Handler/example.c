
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 1 - O prot�tipo da fun��o de uma tarefa deve sempre retornar void, ou seja, a tarefa n�o possui retorno.
 2 - A fun��o de uma tarefa deve receber um par�metro de ponteiro void. 
*/
void vTask(void *pvParameters);
xTaskHandle taskHandle1;
xTaskHandle taskHandle2;

/*
 Deni��o da estrutura da fun��o
*/
void vTask(void *pvParameters)
{

	volatile int cont = 0;

	/* 
		Cada tarefa � um pequeno programa espec�fico, possui seu pr�prio direito de execu��o.
		Geralmente uma tarefa ir� rodar indefinidamente em loop infinito e n�o sair�.
	*/
	for (;; )
	{
		printf("Contador - %d\n",cont);
		cont = cont + 1;
		vTaskDelay(100);
		
		// Quando a condi��o for satisfeita o identificador de taskHandle2 ser� excluido
		if (cont == 10) {

			vTaskDelete(taskHandle2);
		
		}
	}

	// Quando uma tarefa n�o for mais necess�ria, ela dever� ser exclu�da explicitamente.
	vTaskDelete(NULL);
}

int main_(void)
{

	/*
		Sintaxe:

		xTaskCreate(myTask, "Task Hello", 1000, NULL, 1, NULL);

		xTaskCreate(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);

		pxCreatedTask - Permite passar um identificador para a tarefa que est� sendo criada - este identificador pode ser usado para referenciar a tarefa na chamada de API que, por exemplo, alterar a prioridade da tarefa ou excluir a tarefa 
	
	*/


	xTaskCreate(vTask, "Task Hello", 1000, NULL, 1, &taskHandle1);
	xTaskCreate(vTask, "Task Hello 2", 1000, NULL, 1, &taskHandle2);

	// Inicia o escalonador de tarefas
	vTaskStartScheduler();

	for (;; );
	return 0;
}
