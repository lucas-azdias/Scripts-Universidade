#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "basic_io.h"


/*  
Criado o protótipo das tarefas, são criado duas instancias para a tarefa sender 
Para tarefa receiver é criao apenas uma única instância
*/
static void vSenderTask(void *pvParameters);
static void vReceiverTask(void *pvParameters);

/*
Declarado uma variável do tipo xQueueHandle
Esta variável é utilizada para armazenar uma fila que é acessado por todas as três tarefas.
*/
xQueueHandle fila;


int main_(void)
{
	/*
	A fila é criada para armazenar no máximo 5 valores do tipo long 
	*/
	fila = xQueueCreate(5, sizeof(long));

	if (fila != NULL)
	{
		/*
		São criadas duas instâncias da tarefa sender utilizadas para gravar os valores na fila. 
		Os valores  são passados por parâmetro, a primeira instânica vai gravar continuamente o valor 100 
		enquanto a outra instância da tarefa irá escrever continuamente o valor 200 na fila. 
		Ambas as tarefas são criadas com prioridade 1.
		*/
		xTaskCreate(vSenderTask, "Sender1", 1000, (void *)100, 1, NULL);
		xTaskCreate(vSenderTask, "Sender2", 1000, (void *)200, 1, NULL);

		/* 
		Para efetuar a leitura da fila é criado a tarefa receiver.
		Esta tarefa é criado com prioridade 2, superior as tarefas sender responsáveis em gravar na fila.
		*/
		xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 2, NULL);
		/*
		Experimente alterar a prioriade da tarefa receiver para que tenha a mesma prioridade das instâncias da tarefa sender.
		Comentar uma das instâncias de sender e depois deixar as instâncias
		*/

		vTaskStartScheduler();
	}
	else
	{
		vPrintString("A fila nao pode ser criada");
	}

	/*
	Se tudo estiver bem não chegaremos neste ponto, neste momento a tarefa estará sendo executada. 
	Então ao chegar neste ponto é provável que não existe memória heap insuficiente disponível para que o recurso seja criado.
	*/
	for (;; );
	return 0;
}

static void vSenderTask(void *pvParameters)
{
	long enviarValor;
	portBASE_TYPE status;

	/* 
	Duas instâncias desta tarefa são criadas, os valores que são passados por parâmetro para essa tarefa são colocados na fila. 
	Converter o parâmetro para um valor tipo long
	*/
	enviarValor = (long)pvParameters;

	for (;; )
	{
		/* A função xQueueSendToBack() permite gravar os dados na fila.  
		
		 - O primeiro parâmetro é a fila onde serão gravados os dados que estão sendo enviados.
		   A fila foi criada antes que o escalonador fosse iniciado, antes da tarefa começar a ser executada.

		 - O segundo parâmetro é o endereço da variável que contém os dados a serem gravados.

         - O terceiro parâmetro permite definir o tempo de bloqueio. 
		   O tempo que a tarefa deve ser mantida no estado bloqueado para aguardar que haja espaço  na fila caso esteja cheia. 
		   Nesse caso, não foi especificado um tempo de bloqueio porque sempre deve haver espaço na fila. 
		*/
		status = xQueueSendToBack(fila, &enviarValor, 0);

		if (status != pdPASS)
		{
			/* Não foi possível escrever na fila, a fila está cheia */
			vPrintString("Nao foi possivel enviar dados para a fila\n");
		}

		/* Permite que outra tarefa sender seja executada */
		taskYIELD();
	}
}

static void vReceiverTask(void *pvParameters)
{
	/* Definição da variável que vai receber os valores da fila. */
	long receberValor;
	portBASE_TYPE status;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	for (;; )
	{
		/*
		A função uxQueueMessagesWaiting() verifica se há mensagem aguardando para serem inseridas na fila - quando ultrapassa o tamanho máximo da fila.
		Como esta tarefa desbloqueia imediatamente os dados são gravados na fila 
		Esta chamada deve sempre encontrar a fila vazia
		*/
		if (uxQueueMessagesWaiting(fila) != 0)
		{
			vPrintString("A fila deveria estar vazia!\n");
		}

		/* 
		A função xQueueReceive() recebe um valor da fila, este valor é removido da fila.

		 - O primeiro parametro é a fila no qual os dados serão recebidos.
		
		 - O segundo parâmetro é o buffer no qual os dados recebidos serão colocados. 
		   Neste caso o buffer é simplesmente o endereço de uma variável que tem o tamanho necessário para receber os dados.
.
		 - O último parametro é o tempo de bloqueio
		   A quantidade máxima de tempo que uma tarefa deve permanecer em estado bloqueado para aguardar que os  dados estejam disponíveis caso a  fila esteja vazia. 
		
		*/
		status = xQueueReceive(fila, &receberValor, xTicksToWait);

		if (status == pdPASS)
		{
			/* Os dados foram recebidos com sucesso da fila, imprimindo valor recebido */
			vPrintStringAndNumber("Valor recebido da fila = ", receberValor);
		}
		else
		{
			/* Não recebemos nada da fila, mesmo depois de esperar por 100ms.*/
			vPrintString("Não foi possível receber dados da fila.\r\n");
		}
	}
}