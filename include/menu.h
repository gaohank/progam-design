#ifndef __MENU_H__
#define __MENU_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

enum menu_type {
    /* 主界面及子界面条目 */
	MENU_MAIN,

	MENU_CBASE, 		/* C基础 */
	MENU_CXXBASE, 		/* C++基础 */
	MENU_SHELL,         /* SHELL */
	MENU_DATASTRUCTURE, /* 数据结构 */
	MENU_LINUX, 		/* linux系统相关 */
	MENU_THREAD, 		/* 线程相关 */
	MENU_PROCESS, 		/* 进程相关 */
	MENU_IPC,  			/* 进程间通信 */
	MENU_NETWORK, 		/* 网络通信 */

    /* CBASE子界面条目 */
	MN_CB_PRINT,
	MN_CB_STRUCT,
	MN_CB_POINTER,
	MN_CB_IO,
	MN_CB_MEM,

    /* CXXBASE子界面条目 */
	/* TODO */

    /* DATASTRUCTURE子界面条目 */
	MN_DS_STACK,
	MN_DS_LIST,
	MN_DS_TREE,
	MN_DS_GRAPH,

	/* MENU_LINUX子界面条目 */
	MN_LINUX_TIME,
	MN_LINUX_TIMER,
	MN_LINUX_USER_GROUP,

    /* THREAD子界面条目 */
	/* THREAD无子界面 */

	/* PROCESS子界面条目 */
	/* PROCESS无子界面 */
	
    /* IPC子界面条目 */
	MN_IPC_PIPE,
	MN_IPC_SIGNAL,
	MN_IPC_SHM,
	MN_IPC_MESG,
	MN_IPC_SEM,

    /* NETWORK子界面条目 */
	MN_NW_TCP,
	MN_NW_UDP,
	MN_NW_GROUP, 	/* 组播 */

	/* 退出界面 */
	MENU_QUIT,

	/* 最大界面数量 */
	MENU_MAX = 128,
};

// 界面结构体，包括界面类型，界面名称，界面各个条目
// 界面处理函数等
struct _menu {
	enum menu_type type;
	char *menu_name;
	char* (*menu_items)[];
	enum menu_type (*menu_func)(int);
	int  items_num;
};

extern struct _menu total_menu[];
extern int is_clear_sceen;

// 注册所有界面的函数
void total_menu_register(struct _menu total_menu[]);
// 绘制当前的界面
void draw_cur_menu(struct _menu*);

#endif
