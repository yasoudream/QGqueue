#include "ListQueue.h"

bool ListQueue_init(ListQueue * queue, int typesize)
{
	if (queue == NULL || typesize == 0)
		return false;
	queue->length = 0;
	queue->QueueData = NULL;
	queue->typeSize = typesize;
	return true;
}

bool ListQueue_destory(ListQueue * queue)
{
	if (!ListQueue_clear(queue))
		return false;
	queue->typeSize = 0;
	return true;
}

bool ListQueue_pop(ListQueue * queue, void * getter)
{
	if (queue == NULL || getter == NULL || queue->length == 0)
		return false;
	ListQueueNode* pt = queue->QueueData;
	queue->QueueData = queue->QueueData->next;
	memcpy(getter, pt->data, queue->typeSize);
	queue->length--;
	free(pt->data);
	free(pt);
	return true;
}

bool ListQueue_push(ListQueue * queue, void * getter)
{
	if (queue == NULL || getter == NULL || queue->typeSize == 0)
		return false;
	ListQueueNode* ndata = (ListQueueNode*)malloc(sizeof(ListQueueNode));
	ndata->data = malloc(queue->typeSize);
	ndata->next = NULL;
	ListQueueNode** pt = &queue->QueueData;
	while (*pt != NULL)
	{
		pt = &(*pt)->next;
	}
	*pt = ndata;
	memcpy(ndata->data, getter, queue->typeSize);
	queue->length++;
	return true;
}

bool ListQueue_clear(ListQueue * queue)
{
	if (queue == NULL)
		return false;
	ListQueueNode* pt = queue->QueueData;
	while (pt != NULL)
	{
		queue->QueueData = queue->QueueData->next;
		free(pt->data);
		free(pt);
		pt = queue->QueueData;
	}
	queue->length = 0;
	queue->QueueData = NULL;
	return true;
}

bool ListQueue_getHead(ListQueue * queue, void * getter)
{
	if (queue == NULL || queue->length == 0 || getter == NULL)
		return false;
	memcpy(getter, queue->QueueData->data, queue->typeSize);
	return true;
}

bool ListQueue_isEmpty(ListQueue * queue)
{
	if (queue->length == 0)
		return true;
	return false;
}

int ListQueue_getLength(ListQueue * queue)
{
	return queue->length;
}

bool ListQueue_traverse(ListQueue * queue, void(*func)(void*))
{
	if (queue == NULL || queue->length == 0)
		return false;
	ListQueueNode* pt = queue->QueueData;
	while (pt != NULL)
	{
		func(pt->data);
		pt = pt->next;
	}
	return true;
}
