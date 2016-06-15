/**
 * @文件：2-pointer.c
 * @说明：该文件主要包括数组和指针的测试部分
 * @作者：高嵩凌
 * @版本：1.0
 * @日期：2015-11-12
 */
#include "../../include/head.h"

/**
 * @函数说明：ptr_show_array 
 * 			  显示二维数组各个元素地址
 */
void ptr_show_array()
{
	char ch[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int i,j;

	/*
	 * 打印各个元素值
	 */
	for(i = 0; i < 3; i ++)
	{
		for(j = 0; j < 3; j ++)
			printf("%d\t", ch[i][j]);
		putchar(10);
	}

	/*
	 * 打印各个元素地址值
	 */
	for(i = 0; i < 3; i ++)
	{
		for(j = 0; j < 3; j ++)
			printf("%p\t", &ch[i][j]);
		putchar(10);
	}

	printf("&ch = %p\n", &ch);
	printf("&ch + 1 = %p\n", &ch + 1);
	printf("&ch[1][0] = %p\n", &ch[1][0]);
	printf("ch  + 1 = %p\n", ch + 1);
	printf("&ch[0][1] = %p\n", &ch[0][1]);
	printf("ch[0] = %p\n", ch[0]);
	printf("ch[0] + 1= %p\n", ch[0] + 1);
	printf("ch[1] = %p\n", ch[1]);
	printf("ch[1] + 3 = %p\n", ch[1] + 3);
	printf("*(ch[0] + 2) = %d\n", *(ch[0] + 2));
	printf("*ch[1] = %d\n", *ch[1]);
	printf("&ch[1] + 1 = %p\n", &ch[1] + 1);
	printf("*(*(ch + 1) + 1) = %d\n", *(*(ch + 1) + 1));
	printf("*(*(&ch[0] + 1) + 1) + 1 = %d\n", *(*(&ch[0] + 1) + 1) + 1);
}

void func(int i)
{
	printf("func para is %d\n", i);
}

void (*func_test(int i, void (*func)(int)))(int)
{
	printf("in func_test\n");
	func(i);
	return func;
}

/**
 * @函数说明：ptr_show_pointer 
 * 			  显示指针数组，指针函数等
 */
void ptr_show_pointer()
{
	int i = 0;

	/* 产生一个函数指针数组，注册不同的函数指针 */
	void (*(*func_reg[])(int, void (*)(int)))(int) = 
	{
		func_test,
		NULL,
	};

	while (func_reg[i])
	{
		func_reg[i](i, func);
		i++;
	}
}
