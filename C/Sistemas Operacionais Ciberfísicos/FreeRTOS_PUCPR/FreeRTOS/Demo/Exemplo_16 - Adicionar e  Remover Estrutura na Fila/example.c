#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "basic_io.h"

#define SENDER1 "Remetente 1:"
#define SENDER2 "Remetente 2:"

/* Defini��o do prot�tipo das Tarefas (enviar e receber) */
static void vSenderTask(void *pvParameters);
static void vReceiverTask(void *pvParameters);

/* Declara��o da vari�vel do tipo xQueueHandle, correspondente a fila que ir� armazenar as tarefas */
xQueueHandle xQueue;

/* Definindo um estrutura para ser passada para fila. */
typedef struct
{
	unsigned int value;
	unsigned char* labelID;
} xData;

/* Declarando duas var�aveis do tipo xData contendo os dados que ser�o passados para fila. */
static const xData structSend[2] = {
	{ 100, SENDER1 }, //utilizado para sender 1
	{ 200, SENDER2 }  //utilizado para sender 2
};

int main_(void)
{
	/* A fila est� sendo criada para conter no m�ximo 3 estruturas do tipo xData.*/
	xQueue = xQueueCreate(3, sizeof(xData));

	if (xQueue != NULL)
	{
		/* Criando duas inst�ncias das tarefas que gravam dados na fila.
		Na cria��o das tarefas vSenderTask est� sendo passado a estrutura structSend como par�metro.
		A Tarefa enviar� continuamente structSend[0] para a fila, enquanto a outra tarefa enviar� continuamente structSend[1]
		Ambos as tarefas foram criadas com prioridade 2, prioridade superior ao tarefa Receiver.*/
		xTaskCreate(vSenderTask, "Sender1", 1000, &(structSend[0]), 2, NULL);
		xTaskCreate(vSenderTask, "Sender2", 1000, &(structSend[1]), 2, NULL);

		/* Criando a tarefa que efetua a leitura na fila. 
		Tarefa criada com prioridade 1 que as tarefas Sender.*/
		xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 1, NULL);

		// Inicializa o escalonador de Tarefas
		vTaskStartScheduler();
	}
	else
	{
		printf("A fila n�o pode ser criada.");
	}
	
	for (;; );
}


static void vSenderTask(void* pvParameters)
{
	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;
	
	for (;; )
	{
		/*
		A fun��o xQueueSendToBack() permite enviar dados para fila. 
		 - O primeiro par�metro corresponde a fila.
		 - O segundo parametro correspodne aos dados que ser�o gravados na fila
		 - Neste caso estamos passando o endere�o da estrutura structSend disposto em pvParameters, observe que � poss�vel passar diretamente.
		 - O terceiro par�metro � a especifica��o do tempo que ua tarefa deve ser mantida em estado do bloqueado se a fila estiver cheia.
		Obs.: Como as inst�ncias da tarefa Sender tem uma prioridade maior que a tarefa Receiver a fila dever�  ficar cheia.
		Assim a tarefa Receiver ser� executada removendo itens da fila quando ambas as tarefas de Sender estiverem no estado bloqueado.
		*/
		xStatus = xQueueSendToBack(xQueue, pvParameters, xTicksToWait);
		if (xStatus != pdPASS)
		{
			/* A opera��o de envio n�o pode ser concluida, mesmo ap�s esperar por 100ms
			   N�o foi liberado espa�o na fila
			*/
			vPrintString("N�o foi poss�vel enviar dados para a fila.\n");
		}
		/* Permite que a outra tarefa Sender seja executada . */
		taskYIELD();
	}
}

static void vReceiverTask(void* pvParameters)
{
	//Declarando uma estrutura para receber os dados que foram adicionados na fila.
	xData structReceiver;
	portBASE_TYPE xStatus;
	
	for (;; )
	{
		/* Por ter a prioridade mais baixa, essa tarefa s� ser� executada quando o as tarefas de Sender estiverem no estado Bloqueado. 
		As inst�ncias da Tarefa Sender s� entrar�o no estado Bloqueado quando a fila estiver cheia, 
		Deste modo a tarefa sempre espera o n�mero de itens na fila ser igual ao comprimento da fila (Neste caso, tamanho 3).
		*/
		if (uxQueueMessagesWaiting(xQueue) != 3)
		{
			vPrintString("A fila deveria estar cheia !\n");
		}
		/* A fun��o xQueueReceive() permite receber itens da fila.
		   - O primeiro par�metro recebe a fila.
		   - O segundo par�metro corresponde ao buffer onde ser�o armazenados os dados recebidos da fila, no caso o  endere�ao da estrutura structReceiver 
		   - O terceiro parametro � a quantidade de tempo que a tarefa dever� permanecer no estado de bloqueado caso a fila esteja vazia.
		   - Neste caso foi definido como zero, o bloqueio n�o ser� necess�rio porque a fila deve estar sempre cheia.
		*/
		xStatus = xQueueReceive(xQueue, &structReceiver, 0);
		if (xStatus == pdPASS)
		{
			/*  
			Os dados foram recebidos com sucesso da fila. 
			A condi��o abaixo verifica qual das inst�ncias Sender est� sendo recebida.   			
			*/
			if (structReceiver.labelID == SENDER1)
			{
				// Imprime os dados fornecidos na estrutura structSend - Sender 1
				vPrintStringAndNumber(structReceiver.labelID, structReceiver.value);
			}
			else
			{
				// Imprime os dados fornecidos na estrutura structSend - Sender 2
				vPrintStringAndNumber(structReceiver.labelID, structReceiver.value);
			}
		}
		else
		{
			/* 
			Nada foi recebido da fila, esta tarefa deveria ser executada apenas quando a fila estivesse cheia.
			*/
			vPrintString("N�o foi poss�vel receber nenhum dado da fila!\n");
		}
	}
}
