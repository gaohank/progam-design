#include "../../include/head.h"

/**
 * @函数说明：pt_show_color 
 * 			  该函数显示输出字符串的颜色
 */
void pt_show_color()
{
	int i;

	printf("what mode do you want (0--combin 1--1~10 2--front other-background):\n");
	scanf("%d", &i);
	if (i == 0)
	{
		printf("combine:\n");
		printf("\\e[31;40m : \e[31;40mhelloworld\n\e[0m");
		printf("\\e[31;41m : \e[31;41mhelloworld\n\e[0m");
		printf("\\e[31;42m : \e[31;42mhelloworld\n\e[0m");
	}
	else if (i == 1)
	{
		for (i = 0; i < 11; i++)
		{
			printf("\\e[%dm : \e[%dmhelloworld\n\e[0m", i, i);
		}
	}
	else if (i == 2)
	{
		for (i = 30; i < 40; i++)
		{
			printf("\\e[%dm : \e[%dmhelloworld\n\e[0m", i, i);
		}
	}
	else
	{
		for (i = 40; i < 50; i++)
		{
			printf("\\e[%dm : \e[%dmhelloworld\n\e[0m", i, i);
		}
	}
}

/**
 * @函数说明：pt_show_scanf 
 * 			  显示不同的标准输入形式  
 */
void pt_show_scanf()
{
	int num = 0;
	char ch = 'a', buf[100] = "hello-world";

	printf("step 1: scanf(\"%%*[^0-9]%%i\", &num)\n");
	printf("抑制输入的非0-9字符，将接收字符转化为整型\n");
	scanf("%*[^0-9]%i", &num);
	printf("the num is %d\n", num);

	printf("step 2: scanf(\"%%*c%%[A-Z]\", &ch)\n");
	printf("抑制单个字符，然后匹配A-Z字符, ch默认为a\n");
	scanf("%*c%[A-Z]", &ch);
	printf("ch = %c\n", ch);

	printf("step 3: scanf(\"%%3s\", buf)\n");
	printf("取前3个字符\n");
	printf("由于输入可能会很多，需要把输入缓冲中没有用的字符抑制\n");
	printf("scanf(\"%%*[^\\n]\")\n");
	scanf("%3s", buf);
	scanf("%*[^\n]");
	printf("buf = %s\n", buf);
}

/**
 * @函数说明：pt_show_format 
 * 			  显示格式化输出
 */
void pt_show_format()
{
	float fnum = 19.0F;
	double dnum = 19.0;
	char buf[100] = "helloworld";

	printf("float  19.0/3 = %f\n", fnum / 3);
	printf("float %%.3f 19.0/3 = %.3f\n", fnum / 3);
	printf("double 19.0/3 = %lf\n", dnum / 3);
	printf("%%10.2f = %10.2f\n", fnum / 3);
	printf("%%-10.2f = %-10.2f\n", fnum / 3);
	printf("%%5.2s buf = %5.2s\n", buf);
	printf("%%-5.2s buf = %-5.2s\n", buf);
	printf("%%20.2s buf = %20.2s\n", buf);
	printf("%%-20.2s buf = %-20.2s\n", buf);
	printf("%%.20s buf = %.20s\n", buf);
	printf("%%.6d 100 = %.6d\n", 100);
}

/**
 * @函数说明：pt_show_priority
 * 			  显示运算符不同的优先级
 */
void pt_show_priority()
{
	printf("运算符优先级：\n");
	printf("优先级等级 1 ------- 从左到右\n");
	printf("[]\t()\t.\t->\t\n");
	printf("优先级等级 2 ------- 单目运算符 从右到左\n");
	printf("-(负号)\t(类型)\t++\t--\t*(取值)\t&\t!\t~\tsizeof\t\n");
	printf("优先级等级 3 ------- 双目运算符 从左到右\n");
	printf("/\t*\t%%\t\n");
	printf("优先级等级 4 ------- 双目运算符 从左到右\n");
	printf("+\t-\t\n");
	printf("优先级等级 5 ------- 双目运算符 从左到右\n");
	printf("<<\t>>\t\n");
	printf("优先级等级 6 ------- 双目运算符 从左到右\n");
	printf(">\t>=\t<\t<=\t\n");
	printf("优先级等级 7 ------- 双目运算符 从左到右\n");
	printf("==\t!=\t\n");
	printf("优先级等级 8 ------- 双目运算符 从左到右\n");
	printf("&\n");
	printf("优先级等级 9 ------- 双目运算符 从左到右\n");
	printf("^\n");
	printf("优先级等级 10 ------- 双目运算符 从左到右\n");
	printf("|\n");
	printf("优先级等级 11 ------- 双目运算符 从左到右\n");
	printf("&&\n");
	printf("优先级等级 12 ------- 双目运算符 从左到右\n");
	printf("||\n");
	printf("优先级等级 13 ------- 三目运算符 从右到左\n");
	printf("?:\n");
	printf("优先级等级 14 ------- 从右到左\n");
	printf("=\t/=\t*=\t%%=\t+=\t-=\t<<=\t>>=\t&=\t^=\t|=\t\n");
	printf("优先级等级 15 ------- 从左到右\n");
	printf(",\n");
}

/**
 * @函数说明：pt_show_endian
 * 			  显示当前的字节序
 */
void pt_show_endian()
{
	union {
		int i;
		char ch;
	}var;

	var.i = 1;

	if (var.ch)
	{
		printf("当前系统是小端字节序\n");
	}
	else 
	{
		printf("当前系统是大端字节序\n");
	}
}

const int gci = 1;
static int gsi = 2;
const static int gcsi = 3;
struct _g_mem {
	int g_mem_i;
	const int g_mem_ci;
}gvar = {
	1,
	2,
};

/**
 * @函数说明：pt_show_var_addr 
 * 			  局部和全局变量分别属于那个存储区
 */
void pt_show_var_addr()
{
	const int ci = 1;
	static int si = 2;
	const static int csi = 3;

	printf("&gci = %p\n&gsi = %p\n&gcsi = %p\n", &gci, &gsi, &gcsi);
	printf("&ci = %p\n&si = %p\n&csi = %p\n", &ci, &si, &csi);
	printf("&gmem_i %p\n&gmem_ci %p\n", 
			&gvar.g_mem_i, &gvar.g_mem_ci);
}
