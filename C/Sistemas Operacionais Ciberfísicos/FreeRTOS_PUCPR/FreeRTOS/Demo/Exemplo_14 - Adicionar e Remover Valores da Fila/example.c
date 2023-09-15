#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "basic_io.h"


/*  
Criado o prot�tipo das tarefas, s�o criado duas instancias para a tarefa sender 
Para tarefa receiver � criao apenas uma �nica inst�ncia
*/
static void vSenderTask(void *pvParameters);
static void vReceiverTask(void *pvParameters);

/*
Declarado uma vari�vel do tipo xQueueHandle
Esta vari�vel � utilizada para armazenar uma fila que � acessado por todas as tr�s tarefas.
*/
xQueueHandle fila;


int main_(void)
{
	/*
	A fila � criada para armazenar no m�ximo 5 valores do tipo long 
	*/
	fila = xQueueCreate(5, sizeof(long));

	if (fila != NULL)
	{
		/*
		S�o criadas duas inst�ncias da tarefa sender utilizadas para gravar os valores na fila. 
		Os valores  s�o passados por par�metro, a primeira inst�nica vai gravar continuamente o valor 100 
		enquanto a outra inst�ncia da tarefa ir� escrever continuamente o valor 200 na fila. 
		Ambas as tarefas s�o criadas com prioridade 1.
		*/
		xTaskCreate(vSenderTask, "Sender1", 1000, (void *)100, 1, NULL);
		xTaskCreate(vSenderTask, "Sender2", 1000, (void *)200, 1, NULL);

		/* 
		Para efetuar a leitura da fila � criado a tarefa receiver.
		Esta tarefa � criado com prioridade 2, superior as tarefas sender respons�veis em gravar na fila.
		*/
		xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 2, NULL);
		/*
		Experimente alterar a prioriade da tarefa receiver para que tenha a mesma prioridade das inst�ncias da tarefa sender.
		Comentar uma das inst�ncias de sender e depois deixar as inst�ncias
		*/

		vTaskStartScheduler();
	}
	else
	{
		vPrintString("A fila nao pode ser criada");
	}

	/*
	Se tudo estiver bem n�o chegaremos neste ponto, neste momento a tarefa estar� sendo executada. 
	Ent�o ao chegar neste ponto � prov�vel que n�o existe mem�ria heap insuficiente dispon�vel para que o recurso seja criado.
	*/
	for (;; );
	return 0;
}

static void vSenderTask(void *pvParameters)
{
	long enviarValor;
	portBASE_TYPE status;

	/* 
	Duas inst�ncias desta tarefa s�o criadas, os valores que s�o passados por par�metro para essa tarefa s�o colocados na fila. 
	Converter o par�metro para um valor tipo long
	*/
	enviarValor = (long)pvParameters;

	for (;; )
	{
		/* A fun��o xQueueSendToBack() permite gravar os dados na fila.  
		
		 - O primeiro par�metro � a fila onde ser�o gravados os dados que est�o sendo enviados.
		   A fila foi criada antes que o escalonador fosse iniciado, antes da tarefa come�ar a ser executada.

		 - O segundo par�metro � o endere�o da vari�vel que cont�m os dados a serem gravados.

         - O terceiro par�metro permite definir o tempo de bloqueio. 
		   O tempo que a tarefa deve ser mantida no estado bloqueado para aguardar que haja espa�o  na fila caso esteja cheia. 
		   Nesse caso, n�o foi especificado um tempo de bloqueio porque sempre deve haver espa�o na fila. 
		*/
		status = xQueueSendToBack(fila, &enviarValor, 0);

		if (status != pdPASS)
		{
			/* N�o foi poss�vel escrever na fila, a fila est� cheia */
			vPrintString("Nao foi possivel enviar dados para a fila\n");
		}

		/* Permite que outra tarefa sender seja executada */
		taskYIELD();
	}
}

static void vReceiverTask(void *pvParameters)
{
	/* Defini��o da vari�vel que vai receber os valores da fila. */
	long receberValor;
	portBASE_TYPE status;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	for (;; )
	{
		/*
		A fun��o uxQueueMessagesWaiting() verifica se h� mensagem aguardando para serem inseridas na fila - quando ultrapassa o tamanho m�ximo da fila.
		Como esta tarefa desbloqueia imediatamente os dados s�o gravados na fila 
		Esta chamada deve sempre encontrar a fila vazia
		*/
		if (uxQueueMessagesWaiting(fila) != 0)
		{
			vPrintString("A fila deveria estar vazia!\n");
		}

		/* 
		A fun��o xQueueReceive() recebe um valor da fila, este valor � removido da fila.

		 - O primeiro parametro � a fila no qual os dados ser�o recebidos.
		
		 - O segundo par�metro � o buffer no qual os dados recebidos ser�o colocados. 
		   Neste caso o buffer � simplesmente o endere�o de uma vari�vel que tem o tamanho necess�rio para receber os dados.
.
		 - O �ltimo parametro � o tempo de bloqueio
		   A quantidade m�xima de tempo que uma tarefa deve permanecer em estado bloqueado para aguardar que os  dados estejam dispon�veis caso a  fila esteja vazia. 
		
		*/
		status = xQueueReceive(fila, &receberValor, xTicksToWait);

		if (status == pdPASS)
		{
			/* Os dados foram recebidos com sucesso da fila, imprimindo valor recebido */
			vPrintStringAndNumber("Valor recebido da fila = ", receberValor);
		}
		else
		{
			/* N�o recebemos nada da fila, mesmo depois de esperar por 100ms.*/
			vPrintString("N�o foi poss�vel receber dados da fila.\r\n");
		}
	}
}