#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
#include "portmacro.h" 
#include "basic_io.h"

// Definindo o prot�tipo da tarefa
void vTask(void *pvParameters);
// Definindo o prot�tipo da Corrotina
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex);

// Criando a fun��o da corrotina
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex)
{
	
	// A fun��o crSTART () permite inicializar a corrotina, esta fun��o recebe como par�metro o handler da corrotina.
	crSTART(xHandle);

	for (;; )
	{
		//Imprime a mensagem das corrotina - est� utilizando o indice passado por par�metro para identificar a corrotina 
		printf("Corrotina - %d\n", uxIndex);

		/* 
			A fun��o crDelay() � utilizada para gerar um delay de 500ms
			As corrotinas devem ser cooperativas (s�o n�o preemptivas) 
			Ao executar a fun��o crDelay() outra corrotina poder� ser executada.
		*/
		crDELAY(xHandle,500);
		/*
			Foi observado um bug (C2051) na execu��o da fun��o crDELAY(), ent�o foi necess�rio desabilitar uma fun��o no Visual Studio.
			Em Propridades do Projeto >> C/C++ >> Geral >> Formato de Informa��o de Depura��o
			 - Modifiquei essa op��o para Nenhum.
		*/

	}

	// A fun��o crEND() permite encerrar explicitamente a corrotina.
	crEND();
}

void vTask(void* pvParameters)
{

	volatile int indice = 0;


	for (;; )
	{
		// Imprimindo a mensagem da tarefa - mensagem 1
		vPrintString("Task\n");

		// Ser�o criadas 10 inst�ncias da corrotina, executando concorrentemente.
		if (indice < 10) {
			
			// Criando as corrotinas dentro da tarefa
			xCoRoutineCreate(vCoRoutine, 1, indice);

		}
		
		// Inicializa o escalonamento das corrotinas
		vCoRoutineSchedule();

		// incrementando vari�vel indice
		indice++;

		// Efetua uma quebra de linha
		vPrintString("\n");

		// Estabelece um per�odo de atraso de um tick a cada 500 milisegundos 
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

