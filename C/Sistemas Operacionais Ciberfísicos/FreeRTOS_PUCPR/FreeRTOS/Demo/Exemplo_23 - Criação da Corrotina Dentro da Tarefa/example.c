#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
#include "portmacro.h" 
#include "basic_io.h"

// Definindo o protótipo da tarefa
void vTask(void *pvParameters);
// Definindo o protótipo da Corrotina
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex);

// Criando a função da corrotina
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex)
{
	
	// A função crSTART () permite inicializar a corrotina, esta função recebe como parâmetro o handler da corrotina.
	crSTART(xHandle);

	for (;; )
	{
		//Imprime a mensagem das corrotina - está utilizando o indice passado por parâmetro para identificar a corrotina 
		printf("Corrotina - %d\n", uxIndex);

		/* 
			A função crDelay() é utilizada para gerar um delay de 500ms
			As corrotinas devem ser cooperativas (são não preemptivas) 
			Ao executar a função crDelay() outra corrotina poderá ser executada.
		*/
		crDELAY(xHandle,500);
		/*
			Foi observado um bug (C2051) na execução da função crDELAY(), então foi necessário desabilitar uma função no Visual Studio.
			Em Propridades do Projeto >> C/C++ >> Geral >> Formato de Informação de Depuração
			 - Modifiquei essa opção para Nenhum.
		*/

	}

	// A função crEND() permite encerrar explicitamente a corrotina.
	crEND();
}

void vTask(void* pvParameters)
{

	volatile int indice = 0;


	for (;; )
	{
		// Imprimindo a mensagem da tarefa - mensagem 1
		vPrintString("Task\n");

		// Serão criadas 10 instâncias da corrotina, executando concorrentemente.
		if (indice < 10) {
			
			// Criando as corrotinas dentro da tarefa
			xCoRoutineCreate(vCoRoutine, 1, indice);

		}
		
		// Inicializa o escalonamento das corrotinas
		vCoRoutineSchedule();

		// incrementando variável indice
		indice++;

		// Efetua uma quebra de linha
		vPrintString("\n");

		// Estabelece um período de atraso de um tick a cada 500 milisegundos 
		vTaskDelay(portTICK_RATE_MS * 500);

	}
	// Libera a tarefa explicitamente
	vTaskDelete(NULL);
}


int main_(void)
{
		// Criando uma tarefa
		xTaskCreate(vTask,"Task", 1000, NULL, 1, NULL);
		
		// Inicializando o escalonador de tarefas
		vTaskStartScheduler();
		
	for (;; );
	return 0;
}

