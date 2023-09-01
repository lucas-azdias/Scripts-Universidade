#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 1 - O protótipo da função de uma tarefa deve sempre retornar void, ou seja, a tarefa não possui retorno.
 2 - A função de uma tarefa deve receber um parâmetro de ponteiro void. 
*/
void vTask(void *pvParameters);
xTaskHandle taskHandle2;

/*
 Denição da estrutura da função
*/
void vTask(void *pvParameters)
{


	/*
		Ao definir a variável com o qualificador volatile, obrigatoriamente 
		o valor da variável na memória RAM é armazenado em um registrador;
	*/
	volatile int cont = 0;

	/* 
		Cada tarefa é um pequeno programa específico, possui seu próprio direito de execução.
		Geralmente uma tarefa irá rodar indefinidamente em loop infinito e não sairá.
	*/
	for (;; )
	{
		printf("contador: %d\n",cont);
		cont = cont + 1;
		vTaskDelay(500);

	}

	// Quando uma tarefa não for mais necessária, ela deverá ser excluída explicitamente.
	vTaskDelete(NULL);
}

int main_(void)
{
	// Criando duas instâncias de uma mesma tarefa
	xTaskCreate(vTask, "Task 1", 1000, NULL, 1, NULL);
	// Cada instância da tarefa possui sua própria pilha e contexto, armazena suas varíaveis em lugares diferentes.
	xTaskCreate(vTask, "Task 2", 1000, NULL, 1, NULL);

	// Inicia o escalonador de tarefas
	vTaskStartScheduler();

	for (;; );
	return 0;
}
