#include "ForwardQueue.h"

bool ForwardQueue_init(ForwardQueue * queue, int typesize, int size)
{
	if (size < 0 || queue == NULL || typesize == 0)
		return false;
	queue->head = size - 1;
	queue->tail = size - 1;
	queue->length = 0;
	queue->queueSize = size;
	queue->typeSize = typesize;
	queue->QueueData = malloc(size * typesize);
	return true;
}

bool ForwardQueue_destory(ForwardQueue * queue)
{
	
	if (queue == NULL)
		return false;
	free(queue->QueueData);
	queue->head = 0;
	queue->length = 0;
	queue->QueueData = NULL;
	queue->queueSize = 0;
	queue->tail = 0;
	queue->typeSize;
	return true;
}

bool ForwardQueue_pop(ForwardQueue * queue, void * getter)
{
	if (queue == NULL || queue->QueueData == NULL || queue->length == 0 || queue->queueSize == 0 || getter == NULL)
		return false;
	memcpy(getter, (char*)queue->QueueData + queue->typeSize / sizeof(char) * queue->head, queue->typeSize);
	if (queue->length == 1)
	{
		queue->tail = queue->head;
	}
	else
	{
		if (queue->head == queue->queueSize - 1)
			queue->head = 0;
		else
			queue->head++;
	}
	queue->length--;
	return true;
}

bool ForwardQueue_push(ForwardQueue * queue, void * getter)
{
	if (queue == NULL || getter == NULL || queue->length == queue->queueSize)
		return false;
	if (queue->length != 0)
	{
		if (queue->tail == queue->queueSize - 1)
			queue->tail = 0;
		else
			queue->tail++;
	}
	else
		queue->tail = queue->head;

	memcpy((char*)queue->QueueData + queue->typeSize / sizeof(char) * queue->tail, getter, queue->typeSize);
	queue->length++;
	return true;
}

bool ForwardQueue_clear(ForwardQueue * queue)
{
	if (queue == NULL)
		return false;
	queue->head = queue->queueSize - 1;
	queue->tail = queue->queueSize - 1;
	queue->length = 0;
	return true;
}

bool ForwardQueue_getHead(ForwardQueue * queue, void * getter)
{
	if (queue == NULL || getter == NULL || queue->length == 0)
		return false;
	memcpy(getter, (char*)queue->QueueData + queue->typeSize * queue->head, queue->typeSize);
	return true;
}

int ForwardQueue_getSize(ForwardQueue * queue)
{
	return queue->queueSize;
}

bool ForwardQueue_isFull(ForwardQueue * queue)
{
	if (queue->length == queue->queueSize)
		return true;
	return false;
}

bool ForwardQueue_isEmpty(ForwardQueue * queue)
{
	if (queue->length != queue->queueSize)
		return true;
	return false;
}

int ForwardQueue_getLength(ForwardQueue * queue)
{
	return queue->length;
}

bool ForwardQueue_traverse(ForwardQueue * queue, void(*func)(void*))
{
	if (queue == NULL || queue->length == 0)
		return false;
	int index = queue->head;
	while (index != queue->tail)
	{
		func((char*)queue->QueueData + queue->typeSize / sizeof(char) * index);
		if (index == queue->queueSize - 1)
			index = 0;
		else
			index++;
	}
	func((char*)queue->QueueData + queue->typeSize / sizeof(char) * index);
	return true;
}
