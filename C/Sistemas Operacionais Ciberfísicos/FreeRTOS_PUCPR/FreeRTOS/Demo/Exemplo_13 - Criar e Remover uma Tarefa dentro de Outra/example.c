#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

/* Utilizado como identificador (handle) para Tarefa 2 */
xTaskHandle xTask2Handle;

int main_(void)
{
	/* 
	Criando a Tarefa 1 com prioridade 1
	N�o est� sendo passado nenhum par�metros para tarefa 1, setado como NULL
	Para tarefa 1 n�o foi criado um identificador handle, setado como NULL
	*/
	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);
	
	vTaskStartScheduler();

	for (;; );
	return 0;
}

void vTask1(void *pvParameters)
{
	const portTickType xDelay100ms = 100 / portTICK_RATE_MS;

	for (;; )
	{
		vPrintString("Tarefa 1 executando\n");

		/*
		A tarefa 2 � criada no escopo da tarefa 1, a tarefa 2 foi definida com maior prioridade que a tarefa 1.
	    N�o est� sendo passado nenhum parametros para tarefa 2, setado como NULL.
	    A tarefa 2 foi passado como identificador o endere�o da vari�vel xTask2Handle. 
		*/
		xTaskCreate(vTask2, "Task 2", 1000, NULL, 2, &xTask2Handle);
		
		/* 
		A Tarefa2 tem maior prioridade que a Tarefa 1, passando a executar 
		Ao chegar nesse ponto a tarefa 2 j� deve ter sido executada e exclu�da
		Na sequencia � adicionado um delay (atraso) de 100 milissegundos
		*/
		vTaskDelay(xDelay100ms);
	}
}

void vTask2(void *pvParameters)
{
	/*
	A Tarefa 2 imprime a mensagem e faz uma chamada para fun��o vTaskDelete()
	A fun��o vTaskDelete() � utilizada para excluir uma tarefa 
	Ao utilizar o par�metro NULL na chamada da fun��o a Tarefa 2 est� passando o seu pr�prio identificador.
	Desta forma a Tarefa 2 ser� excluida.
	*/
	vPrintString("A Tarefa 2 foi executada e ser� excluida\n");
	vTaskDelete(xTask2Handle);
}
