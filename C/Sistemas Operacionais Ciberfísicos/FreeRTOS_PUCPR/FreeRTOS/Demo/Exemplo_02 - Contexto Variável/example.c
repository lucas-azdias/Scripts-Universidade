#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"

/*
 1 - O prot�tipo da fun��o de uma tarefa deve sempre retornar void, ou seja, a tarefa n�o possui retorno.
 2 - A fun��o de uma tarefa deve receber um par�metro de ponteiro void. 
*/
void vTask(void *pvParameters);
xTaskHandle taskHandle2;

/*
 Deni��o da estrutura da fun��o
*/
void vTask(void *pvParameters)
{


	/*
		Ao definir a vari�vel com o qualificador volatile, obrigatoriamente 
		o valor da vari�vel na mem�ria RAM � armazenado em um registrador;
	*/
	volatile int cont = 0;

	/* 
		Cada tarefa � um pequeno programa espec�fico, possui seu pr�prio direito de execu��o.
		Geralmente uma tarefa ir� rodar indefinidamente em loop infinito e n�o sair�.
	*/
	for (;; )
	{
		printf("contador: %d\n",cont);
		cont = cont + 1;
		vTaskDelay(500);

	}

	// Quando uma tarefa n�o for mais necess�ria, ela dever� ser exclu�da explicitamente.
	vTaskDelete(NULL);
}

int main_(void)
{
	// Criando duas inst�ncias de uma mesma tarefa
	xTaskCreate(vTask, "Task 1", 1000, NULL, 1, NULL);
	// Cada inst�ncia da tarefa possui sua pr�pria pilha e contexto, armazena suas var�aveis em lugares diferentes.
	xTaskCreate(vTask, "Task 2", 1000, NULL, 1, NULL);

	// Inicia o escalonador de tarefas
	vTaskStartScheduler();

	for (;; );
	return 0;
}
