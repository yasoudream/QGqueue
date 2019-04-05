#ifndef __FORWARD_QUEUE__
#define __FORWARD_QUEUE__

#include <stdlib.h>
#include <string.h>

//数组实现队列
typedef struct ForwardQueue
{
	void* QueueData;
	int head;
	int tail;
	int queueSize;
	int length;
	int typeSize;
}ForwardQueue;


//初始化队列
bool ForwardQueue_init(ForwardQueue* queue, int typesize, int size);
//销毁队列
bool ForwardQueue_destory(ForwardQueue* queue);


//弹出
bool ForwardQueue_pop(ForwardQueue* queue, void* getter);
//加入
bool ForwardQueue_push(ForwardQueue* queue, void* getter);
//清空
bool ForwardQueue_clear(ForwardQueue* queue);


//获得首元素
bool ForwardQueue_getHead(ForwardQueue* queue, void* getter);
//获得大小
int ForwardQueue_getSize(ForwardQueue* queue);
//判满
bool ForwardQueue_isFull(ForwardQueue* queue);
//判空
bool ForwardQueue_isEmpty(ForwardQueue* queue);
//获得元素数
int ForwardQueue_getLength(ForwardQueue* queue);


//遍历
bool ForwardQueue_traverse(ForwardQueue* queue, void (*func)(void*));




#endif

