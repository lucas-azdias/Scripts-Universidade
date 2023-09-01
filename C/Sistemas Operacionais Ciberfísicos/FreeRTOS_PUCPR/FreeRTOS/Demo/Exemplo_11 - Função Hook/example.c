#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTaskFunction(void *pvParameters);

/* Esta variável é incrementada dentro da função de hook. */
static uint32_t contador;

/* Define the strings that will be passed in as the task parameters.  These are
defined const and off the stack to ensure they remain valid when the tasks are
executing. */
const char *msgTask1 = "Tarefa 1 executando";
const char *msgTask2 = "Tarefa 2 executando";

/*-----------------------------------------------------------*/

int main_(void)
{

	xTaskCreate(&vTaskFunction, "Task 1", 1000, (void*)msgTask1, 1, NULL);
	xTaskCreate(&vTaskFunction, "Task 2", 1000, (void*)msgTask2, 1, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}
/*-----------------------------------------------------------*/

void vTaskFunction(void *pvParameters)
{
	char * msgTask;

	msgTask = (char *)pvParameters;

	for (;; )
	{
		/* Imprime a string contendo a identificação da tarefa e o valor da variável contador. */
		vPrintStringAndNumber(msgTask, contador);
		//printf("Contador: %u\n", contador);
		
		/*  
		A chamada da função vTaskDelay () coloca a tarefa no estado bloqueado até que o período de atraso expire. 
		O período de atraso é especificado em ticks.
		*/
		vTaskDelay(250 / portTICK_RATE_MS);

	}
}
/*-----------------------------------------------------------*/

/* 
A função de hook deve ser chamadas de vApplicationIdleHook () - intercepta a tarefa enquanto estão ociosas. 
Esta função não aceitam parâmetros e deve retornar um void.
*/
void vApplicationIdleHook(void)
{
	/* Esta função hook incrementa um contador*/
	contador++;
	
	// Descomentar para mostrar que a função vApplicationIdleHook(), roda enquanto a tarefa está ocioso
	//vPrintStringAndNumber("Hook",contador);
	
	// Descomentar para mostrar que a função printf não é uma função reentrante.
	//printf("Hook: %u\n", contador);

}



