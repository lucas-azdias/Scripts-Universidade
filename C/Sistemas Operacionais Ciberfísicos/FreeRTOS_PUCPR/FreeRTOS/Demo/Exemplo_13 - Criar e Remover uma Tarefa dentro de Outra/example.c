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
	Não está sendo passado nenhum parâmetros para tarefa 1, setado como NULL
	Para tarefa 1 não foi criado um identificador handle, setado como NULL
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
		A tarefa 2 é criada no escopo da tarefa 1, a tarefa 2 foi definida com maior prioridade que a tarefa 1.
	    Não está sendo passado nenhum parametros para tarefa 2, setado como NULL.
	    A tarefa 2 foi passado como identificador o endereço da variável xTask2Handle. 
		*/
		xTaskCreate(vTask2, "Task 2", 1000, NULL, 2, &xTask2Handle);
		
		/* 
		A Tarefa2 tem maior prioridade que a Tarefa 1, passando a executar 
		Ao chegar nesse ponto a tarefa 2 já deve ter sido executada e excluída
		Na sequencia é adicionado um delay (atraso) de 100 milissegundos
		*/
		vTaskDelay(xDelay100ms);
	}
}

void vTask2(void *pvParameters)
{
	/*
	A Tarefa 2 imprime a mensagem e faz uma chamada para função vTaskDelete()
	A função vTaskDelete() é utilizada para excluir uma tarefa 
	Ao utilizar o parâmetro NULL na chamada da função a Tarefa 2 está passando o seu próprio identificador.
	Desta forma a Tarefa 2 será excluida.
	*/
	vPrintString("A Tarefa 2 foi executada e será excluida\n");
	vTaskDelete(xTask2Handle);
}
