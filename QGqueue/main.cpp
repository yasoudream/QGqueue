#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ListQueue.h"
#define MAXSIZE 1000
//防用户int输入器
bool input_int(int* getter)
{
	char input[MAXSIZE];
	gets_s(input);
	int len, out;
	len = strlen(input);
	out = 0;
	for (int i = 0; i < len; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			out = out * 10 + input[i] - '0';
		else
			return false;
	}
	*getter = out;
	return true;
}




//整数输出器
void print(void* nmd)
{
	printf("           %d\n", *((int*)nmd));
}

int main()
{
	system("color F0");
	ListQueue list;
	ListQueue_init(&list, sizeof(int));
	int i = 0 , j = 0;
	char ch = 'a';
	while (ch != 'q')
	{
		system("cls");
		printf("\n    你有个链队列(int),\n\
    你想让他做啥？(输入数字)\n\
    1.push               2.pop             3.clear            4.getLength\n\n\
    5.getHead            6.isEmpty         7.traverse(输出)   q.destory_and_exit\n\n");
		fflush(stdin);
		ch = _getch();
		switch (ch)
		{
		case '1':
			printf("    input num: ");
			if (input_int(&i))
				ListQueue_push(&list, &i);
			else
				printf("    输入错误");
			break;
		case '2':
			if (!ListQueue_pop(&list, &i))
				printf("    空的，没得pop\n");
			else
				printf("    pop了个 %d\n", i);
			break;
		case '3':
			ListQueue_clear(&list);
			break;
		case '4':
			printf("    length is : %d\n",ListQueue_getLength(&list));
			break;
		case '5':
			if (!ListQueue_getHead(&list, &i))
				printf("     空的get不到\n");
			else
				printf("     head is : %d\n", i);
			break;
		case '6':
			if (ListQueue_isEmpty(&list))
				printf("    毛都没有\n");
			else
				printf("    有点东西\n");
			break;
		case '7':
			ListQueue_traverse(&list, print);
			break;
		case 'q':
			ListQueue_destory(&list);
			break;
		default:
			break;
		}
		printf("       按键继续");
		system("pause>nul");
	}
	printf("    亲已经退出");
	system("pause>nul");
	return 0;
}