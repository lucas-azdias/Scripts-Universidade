#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTaskFunction(void *pvParameters);

/* Esta vari�vel � incrementada dentro da fun��o de hook. */
static uint32_t contador;

const char *msgTask1 = "Tarefa 1 executando";
const char *msgTask2 = "Tarefa 2 executando";

int main_(void)
{

	xTaskCreate(vTaskFunction, "Task 1", 1000, (void*)msgTask1, 1, NULL);
	xTaskCreate(vTaskFunction, "Task 2", 1000, (void*)msgTask2, 1, NULL);

	vTaskStartScheduler();

	for (;; );
	return 0;
}

void vTaskFunction(void *pvParameters)
{
	char * msgTask;

	msgTask = (char *)pvParameters;

	for (;; )
	{
		/* Imprime a string contendo a identifica��o da tarefa e o valor da vari�vel contador. */
		vPrintStringAndNumber(msgTask, contador);
		printf("Contador: %u\n", contador);
		
		/*  
		A chamada da fun��o vTaskDelay () coloca a tarefa no estado bloqueado at� que o per�odo de atraso expire. 
		O per�odo de atraso � especificado em ticks.
		*/
		vTaskDelay(250 / portTICK_RATE_MS);

	}
	vTaskDelete(NULL);
}

/* 
A fun��o de hook deve ser chamadas de vApplicationIdleHook () - intercepta a tarefa enquanto est�o ociosas. 
Esta fun��o n�o aceitam par�metros e deve retornar um void.
*/
void vApplicationIdleHook(void)
{
	/* Esta fun��o hook incrementa um contador*/
	contador++;
	
	// Descomentar para mostrar que a fun��o printf n�o � uma fun��o reentrante.
	// printf("Hook: %u\n", contador);
	
	/*
	A fun��o vTaskSuspendAll() permite suspender o escalonador. 
	Evitado que ocorra uma mudan�a de contexto, as interrup��es permaneceram ainda ativadas. 
	Se uma interrup��o solicitar uma mudan�a de contexto enquanto o escalonador estiver suspenso, 
	a solicita��o � mantida pendente e realizada quando o escalonador for retomado (deixar o estado de suspenso).
	*/
	vTaskSuspendAll(); 
	{
		printf("Hook: %u\n", contador);

	}
	xTaskResumeAll();
	/* A fun��o abaixo captura se alguma tecla foi pressionada, na sequ�ncia � interrompido a execu��o do aplicativo.
	   Em uma aplica��o RTOS real o valor da chave deve proteger o acesso � entrada do teclado.
	 */
	if (kbhit())
	{
	/*
		A fun��o vTaskEndScheduler() encerra o escalonador.
	*/
		vTaskEndScheduler();
	}

}



