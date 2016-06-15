/** * @文件：1-struct.C * @说明：该文件主要包含测试结构体偏移的函数,结构体和联合体 * @作者：高嵩凌
 * @版本：1.0
 * @日期：2015-11-12
 */
#include "../../include/head.h"

union _section {
	unsigned int all;
	struct _control {
		struct {
			char a : 1;
			char b : 1;
			char c : 1;
		}ctl1;	
		struct {
			short d : 1;
			short e : 1;
			short f : 1;
		}ctl2;
		struct {
			int g : 1;
			int h : 1;
			int i : 1;
		}ctl3;
		struct {
			char j : 1;
			short k : 1;
			int m : 1;
		}ctl4;
	}st_ctl;
};

/**
 * @函数说明：st_show_size 
 * 			  显示数据结构大小 
 */
void st_show_size()
{
	union _section sect;
	printf("section size is %d\n", sizeof sect);
	printf("section size of ctl1 is %d\n", sizeof sect.st_ctl.ctl1);
	printf("section size of ctl2 is %d\n", sizeof sect.st_ctl.ctl2);
	printf("section size of ctl3 is %d\n", sizeof sect.st_ctl.ctl3);
	printf("section size of ctl4 is %d\n", sizeof sect.st_ctl.ctl4);
}

struct _align {
	char c1;
	short s1;
	char c2;
	int  i;
	short s2;
};
/**
 * @函数说明：st_show_alignment 
 * 			  显示数据结构元素对齐
 */
void st_show_alignment()
{
	struct _align align;
	printf("offset of c1 is %d\n", (unsigned)&align.c1 - (unsigned)&align);
	printf("offset of s1 is %d\n", (unsigned)&align.s1 - (unsigned)&align);
	printf("offset of c2 is %d\n", (unsigned)&align.c2 - (unsigned)&align);
	printf("offset of s2 is %d\n", (unsigned)&align.s2 - (unsigned)&align);
	printf("total struct size is %d\n", sizeof align);
}
