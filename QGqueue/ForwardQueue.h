#ifndef __FORWARD_QUEUE__
#define __FORWARD_QUEUE__

#include <stdlib.h>
#include <string.h>

//����ʵ�ֶ���
typedef struct ForwardQueue
{
	void* QueueData;
	int head;
	int tail;
	int queueSize;
	int length;
	int typeSize;
}ForwardQueue;


//��ʼ������
bool ForwardQueue_init(ForwardQueue* queue, int typesize, int size);
//���ٶ���
bool ForwardQueue_destory(ForwardQueue* queue);


//����
bool ForwardQueue_pop(ForwardQueue* queue, void* getter);
//����
bool ForwardQueue_push(ForwardQueue* queue, void* getter);
//���
bool ForwardQueue_clear(ForwardQueue* queue);


//�����Ԫ��
bool ForwardQueue_getHead(ForwardQueue* queue, void* getter);
//��ô�С
int ForwardQueue_getSize(ForwardQueue* queue);
//����
bool ForwardQueue_isFull(ForwardQueue* queue);
//�п�
bool ForwardQueue_isEmpty(ForwardQueue* queue);
//���Ԫ����
int ForwardQueue_getLength(ForwardQueue* queue);


//����
bool ForwardQueue_traverse(ForwardQueue* queue, void (*func)(void*));




#endif

