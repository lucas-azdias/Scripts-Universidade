#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
#include "portmacro.h" 
#include "basic_io.h"

// Definindo o protótipo das tarefas 
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex);


/* Função para implementar a corrotina
   A função para criação da corrotina deve retornar um void.
   Esta função recebe dois parâmetros:
   - O primeiro é um identificador para corrotina (CoRoutineHandle_t), obtido automaticamente ao criar a corrotina. 
   - O segundo é uma variável que permite efetuar a passagem de parâmetros para corrotina. 
*/
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex)
{
	// Variável criada para receber os valores passado por parâmetro.
	char* msgCorrotina = uxIndex;

	// A função crSTART () permite inicializar a corrotina, esta função recebe como parâmetro o handler da corrotina.
	crSTART(xHandle);

	// Uma corrotina semelhante a uma tarefa implementa internamente um loop infinito. 
	for (;; )
	{	
		//Esta corrotina imprime a mensagem passada por parâmetro.
		vPrintString(msgCorrotina);
		
	}
	// A função crEND() permite encerrar explicitamente a corrotina.
	crEND(); 
}

int main_(void)
{
	
	/* 
		A função xCoRoutineCreate() é utilizada para criar uma corrotina.
	    Esta função recebe três parâmetros:
		- O primeiro parâmetro é o nome da função que implementa a corrotina
		- O segundo parâmetro corresponde a prioridade da corrotina
		- O terceiro parâmetro permite fornecer um valor de entrada para função.
	*/
	xCoRoutineCreate(vCoRoutine, 1,"Corrotina\n");	
	
	// Inicializa o escalonador de corrotinas.
	vCoRoutineSchedule();

	for (;; );
	return 0;
}

