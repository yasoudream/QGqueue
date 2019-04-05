#ifndef __LIST_QUEUE__
#define __LIST_QUEUE__

#include <stdlib.h>
#include <string.h>

//����ʵ�ֶ���

typedef struct ListQueueNode
{
	void* data;
	ListQueueNode* next;

}ListQueueNode;

typedef struct ListQueue
{
	ListQueueNode* QueueData;
	int length;
	int typeSize;
}ListQueue;




//��ʼ������
bool ListQueue_init(ListQueue* queue, int typesize);
//���ٶ���
bool ListQueue_destory(ListQueue* queue);


//����
bool ListQueue_pop(ListQueue* queue, void* getter);
//����
bool ListQueue_push(ListQueue* queue, void* getter);
//���
bool ListQueue_clear(ListQueue* queue);


//�����Ԫ��
bool ListQueue_getHead(ListQueue* queue, void* getter);
//�п�
bool ListQueue_isEmpty(ListQueue* queue);
//���Ԫ����
int ListQueue_getLength(ListQueue* queue);


//����
bool ListQueue_traverse(ListQueue* queue, void(*func)(void*));




#endif

