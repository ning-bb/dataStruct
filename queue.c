#include <stdio.h>
#include <stdlib.h>

//����ڵ�
typedef struct ListNode {
	int val;
	struct ListNode* next;
}*node;

//���еĶ�ͷ�Ͷ�β
typedef struct {
	node front;
	node rear;
}linkQueue;

//����һ���ն���
linkQueue InitQueue(void)
{	
	linkQueue ret;
	node temp = (node)malloc(sizeof(struct ListNode));
	if (temp == NULL)
		exit(-1);

	temp->next = NULL;
	ret.front = temp;
	ret.rear = temp;

	return ret;
}

//���ٶ���
int DestroyQueue(linkQueue queue)
{
	while (queue.front != NULL)
	{
		queue.rear = queue.front->next;
		free(queue.front);
		queue.front = queue.rear;
	}

	return 0;
}

//���Ӳ���
int EnQueue(linkQueue* queue, int val)
{
	node temp = (node)malloc(sizeof(struct ListNode));
	if (temp == NULL)
		return -1;

	temp->val = val;
	temp->next = NULL;

	queue->rear->next = temp;
	queue->rear = temp;

	return 0;
}

//���Ӳ���
int DeQueue(linkQueue* queue, int *val)
{
	//�����ж϶����Ƿ�Ϊ��
	if (queue->front == queue->rear)
		return -1;

	node temp = queue->front->next;

	*val = temp->val;

	queue->front->next = temp->next;

	if (temp == queue->rear)
		queue->rear = queue->front;

	free(temp);
	return 0;
}

//��ӡ������Ϣ
void printfQueue(linkQueue queue)
{
	queue.front = queue.front->next;

	while (queue.front != NULL)
	{
		printf("%d \r\n", queue.front->val);

		queue.front = queue.front->next;
	}
}

//main�������Դ���
int main(void)
{
	printf("queue test!\r\n");
	linkQueue queue;
	int val;

	queue = InitQueue();

	EnQueue(&queue,1);
	EnQueue(&queue, 2);
	EnQueue(&queue, 3);
	EnQueue(&queue, 4);

	printfQueue(queue);

	printf("/---------------/\r\n");
	DeQueue(&queue, &val);
	printf("val = %d\r\n", val);
	printf("/---------------/\r\n");
	printfQueue(queue);
	printf("/---------------/\r\n");
	
	EnQueue(&queue, 6);
	printfQueue(queue);

	return 0;
}