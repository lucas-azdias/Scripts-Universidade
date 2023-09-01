
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 1 - O protótipo da função de uma tarefa deve sempre retornar void, ou seja, a tarefa não possui retorno.
 2 - A função de uma tarefa deve receber um parâmetro de ponteiro void. 
*/
void vTask(void *pvParameters);
xTaskHandle taskHandle1;
xTaskHandle taskHandle2;

/*
 Denição da estrutura da função
*/
void vTask(void *pvParameters)
{

	volatile int cont = 0;

	/* 
		Cada tarefa é um pequeno programa específico, possui seu próprio direito de execução.
		Geralmente uma tarefa irá rodar indefinidamente em loop infinito e não sairá.
	*/
	for (;; )
	{
		printf("Contador - %d\n",cont);
		cont = cont + 1;
		vTaskDelay(100);
		
		// Quando a condição for satisfeita o identificador de taskHandle2 será excluido
		if (cont == 10) {

			vTaskDelete(taskHandle2);
		
		}
	}

	// Quando uma tarefa não for mais necessária, ela deverá ser excluída explicitamente.
	vTaskDelete(NULL);
}

int main_(void)
{

	/*
		Sintaxe:

		xTaskCreate(myTask, "Task Hello", 1000, NULL, 1, NULL);

		xTaskCreate(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);

		pxCreatedTask - Permite passar um identificador para a tarefa que está sendo criada - este identificador pode ser usado para referenciar a tarefa na chamada de API que, por exemplo, alterar a prioridade da tarefa ou excluir a tarefa 
	
	*/


	xTaskCreate(vTask, "Task Hello", 1000, NULL, 1, &taskHandle1);
	xTaskCreate(vTask, "Task Hello 2", 1000, NULL, 1, &taskHandle2);

	// Inicia o escalonador de tarefas
	vTaskStartScheduler();

	for (;; );
	return 0;
}
