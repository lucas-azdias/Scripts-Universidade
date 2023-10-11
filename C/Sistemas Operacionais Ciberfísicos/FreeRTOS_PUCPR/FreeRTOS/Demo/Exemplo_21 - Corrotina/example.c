#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
#include "portmacro.h" 
#include "basic_io.h"

// Definindo o prot�tipo das tarefas 
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex);


/* Fun��o para implementar a corrotina
   A fun��o para cria��o da corrotina deve retornar um void.
   Esta fun��o recebe dois par�metros:
   - O primeiro � um identificador para corrotina (CoRoutineHandle_t), obtido automaticamente ao criar a corrotina. 
   - O segundo � uma vari�vel que permite efetuar a passagem de par�metros para corrotina. 
*/
void vCoRoutine(CoRoutineHandle_t xHandle, UBaseType_t uxIndex)
{
	// Vari�vel criada para receber os valores passado por par�metro.
	char* msgCorrotina = uxIndex;

	// A fun��o crSTART () permite inicializar a corrotina, esta fun��o recebe como par�metro o handler da corrotina.
	crSTART(xHandle);

	// Uma corrotina semelhante a uma tarefa implementa internamente um loop infinito. 
	for (;; )
	{	
		//Esta corrotina imprime a mensagem passada por par�metro.
		vPrintString(msgCorrotina);
		
	}
	// A fun��o crEND() permite encerrar explicitamente a corrotina.
	crEND(); 
}

int main_(void)
{
	
	/* 
		A fun��o xCoRoutineCreate() � utilizada para criar uma corrotina.
	    Esta fun��o recebe tr�s par�metros:
		- O primeiro par�metro � o nome da fun��o que implementa a corrotina
		- O segundo par�metro corresponde a prioridade da corrotina
		- O terceiro par�metro permite fornecer um valor de entrada para fun��o.
	*/
	xCoRoutineCreate(vCoRoutine, 1,"Corrotina\n");	
	
	// Inicializa o escalonador de corrotinas.
	vCoRoutineSchedule();

	for (;; );
	return 0;
}

