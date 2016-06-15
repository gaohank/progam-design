/*********************************************************
CopyRight (C), 1999-2016,翔迅科技有限责任公司.
*********************************************************/
/**
 * @文件：progam-design.C
 * @说明：这个程序主要记录一些基本的知识，以及可以给日后其他
 * 		  项目使用的代码模板。
 * @作者：高嵩凌
 * @版本：1.0
 * @日期：2015-10-31
 */

#include "include/menu.h"

int is_clear_sceen = TRUE;

int choose_step_number(int item_num)
{
	int n;

CHOOSE_NO:
	printf("choose your number choice:");
	/*scanf("%*[^0-9]%d", &n);*/
	scanf("%d", &n);

	if (n <= 0 || n > item_num)
	{
		printf("your input number is uncorrect\n");
		printf("repeat ");
		goto CHOOSE_NO;
	}

	return n;
}

enum menu_type do_menu_choice(struct _menu *p_cur_menu)
{
	int item_no;
	enum menu_type new_menu;

	if (is_clear_sceen)
	{
		draw_cur_menu(p_cur_menu);
	}

	item_no = choose_step_number(p_cur_menu->items_num);

	new_menu = (p_cur_menu->menu_func)(item_no);

	return new_menu;
}

/**
 * @函数说明：main 
 * 			  程序入口函数
 *
 * @函数参数：argc
 * 			  命令行传入参数
 * @函数参数：argv[]
 * 			  对应命令行各参数指针
 *
 * @返回值：
 */
int main(int argc, const char *argv[])
{
	enum menu_type menu = MENU_MAIN;
	struct _menu total_menu[MENU_MAX];

	total_menu_register(total_menu);

	do {
		/* 默认的界面类型为主界面 */
		if (total_menu[menu].type == 0)
		{
			menu = MENU_MAIN;
		}
		menu = do_menu_choice(&total_menu[menu]);
	} while (menu != MENU_QUIT);

	system("clear");

    return 0;
}

