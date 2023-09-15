#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "basic_io.h"

#define SENDER1 "Remetente 1:"
#define SENDER2 "Remetente 2:"

/* Definição do protótipo das Tarefas (enviar e receber) */
static void vSenderTask(void *pvParameters);
static void vReceiverTask(void *pvParameters);

/* Declaração da variável do tipo xQueueHandle, correspondente a fila que irá armazenar as tarefas */
xQueueHandle xQueue;

/* Definindo um estrutura para ser passada para fila. */
typedef struct
{
	unsigned int value;
	unsigned char* labelID;
} xData;

/* Declarando duas varíaveis do tipo xData contendo os dados que serão passados para fila. */
static const xData structSend[2] = {
	{ 100, SENDER1 }, //utilizado para sender 1
	{ 200, SENDER2 }  //utilizado para sender 2
};

int main_(void)
{
	/* A fila está sendo criada para conter no máximo 3 estruturas do tipo xData.*/
	xQueue = xQueueCreate(3, sizeof(xData));

	if (xQueue != NULL)
	{
		/* Criando duas instâncias das tarefas que gravam dados na fila.
		Na criação das tarefas vSenderTask está sendo passado a estrutura structSend como parâmetro.
		A Tarefa enviará continuamente structSend[0] para a fila, enquanto a outra tarefa enviará continuamente structSend[1]
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
		printf("A fila não pode ser criada.");
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
		A função xQueueSendToBack() permite enviar dados para fila. 
		 - O primeiro parâmetro corresponde a fila.
		 - O segundo parametro correspodne aos dados que serão gravados na fila
		 - Neste caso estamos passando o endereço da estrutura structSend disposto em pvParameters, observe que é possível passar diretamente.
		 - O terceiro parâmetro é a especificação do tempo que ua tarefa deve ser mantida em estado do bloqueado se a fila estiver cheia.
		Obs.: Como as instâncias da tarefa Sender tem uma prioridade maior que a tarefa Receiver a fila deverá  ficar cheia.
		Assim a tarefa Receiver será executada removendo itens da fila quando ambas as tarefas de Sender estiverem no estado bloqueado.
		*/
		xStatus = xQueueSendToBack(xQueue, pvParameters, xTicksToWait);
		if (xStatus != pdPASS)
		{
			/* A operação de envio não pode ser concluida, mesmo após esperar por 100ms
			   Não foi liberado espaço na fila
			*/
			vPrintString("Não foi possível enviar dados para a fila.\n");
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
		/* Por ter a prioridade mais baixa, essa tarefa só será executada quando o as tarefas de Sender estiverem no estado Bloqueado. 
		As instâncias da Tarefa Sender só entrarão no estado Bloqueado quando a fila estiver cheia, 
		Deste modo a tarefa sempre espera o número de itens na fila ser igual ao comprimento da fila (Neste caso, tamanho 3).
		*/
		if (uxQueueMessagesWaiting(xQueue) != 3)
		{
			vPrintString("A fila deveria estar cheia !\n");
		}
		/* A função xQueueReceive() permite receber itens da fila.
		   - O primeiro parâmetro recebe a fila.
		   - O segundo parâmetro corresponde ao buffer onde serão armazenados os dados recebidos da fila, no caso o  endereçao da estrutura structReceiver 
		   - O terceiro parametro é a quantidade de tempo que a tarefa deverá permanecer no estado de bloqueado caso a fila esteja vazia.
		   - Neste caso foi definido como zero, o bloqueio não será necessário porque a fila deve estar sempre cheia.
		*/
		xStatus = xQueueReceive(xQueue, &structReceiver, 0);
		if (xStatus == pdPASS)
		{
			/*  
			Os dados foram recebidos com sucesso da fila. 
			A condição abaixo verifica qual das instâncias Sender está sendo recebida.   			
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
			vPrintString("Não foi possível receber nenhum dado da fila!\n");
		}
	}
}
