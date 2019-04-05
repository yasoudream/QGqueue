#ifndef __LIST_QUEUE__
#define __LIST_QUEUE__

#include <stdlib.h>
#include <string.h>

//链表实现队列

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




//初始化队列
bool ListQueue_init(ListQueue* queue, int typesize);
//销毁队列
bool ListQueue_destory(ListQueue* queue);


//弹出
bool ListQueue_pop(ListQueue* queue, void* getter);
//加入
bool ListQueue_push(ListQueue* queue, void* getter);
//清空
bool ListQueue_clear(ListQueue* queue);


//获得首元素
bool ListQueue_getHead(ListQueue* queue, void* getter);
//判空
bool ListQueue_isEmpty(ListQueue* queue);
//获得元素数
int ListQueue_getLength(ListQueue* queue);


//遍历
bool ListQueue_traverse(ListQueue* queue, void(*func)(void*));




#endif

