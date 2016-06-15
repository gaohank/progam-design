#include "../include/menu_common.h"

// 主菜单 {{{1
char *main_menu[] = {
	"menu item -- c_base",
	"menu item -- cxx_base",
	"menu item -- data_structure",
	"menu item -- linux",
	"menu item -- thread",
	"menu item -- process",
	"menu item -- ipc",
	"menu item -- network",
	"quit",
	NULL
};
// 主菜单 }}}1


// +-- cbase菜单及其子菜单 {{{1
char *cbase_menu[] = {
	"c base menu item -- print",
	"c base menu item -- struct",
	"c base menu item -- pointer",
	"c base menu item -- io",
	"c base menu item -- mem",
	"return to previous menu",
	"quit",
	NULL
};

//		+-- MN_CB_PRINT菜单 {{{2
char *cb_print_menu[] = {
	"print with color",
	"print with scanf",
	"print with format",
	"print with priority",
	"print with endian",
	"print with var addr",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
//		+-- MN_CB_PRINT }}}2 


// 		+-- MN_CB_STRUCT菜单 {{{2
char *cb_struct_menu[] = {
	"show struct size",
	"show struct alignment",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// 		+-- MN_CB_STRUCT }}}2


// 		+-- MN_CB_POINTER菜单 {{{2
char *cb_pointer_menu[] = {
	"show array addr",
	"show pointer",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// 		+-- MN_CB_POINTER }}}2


// 		+-- MN_CB_IO菜单 {{{2
char *cb_io_menu[] = {
	"stdio fopen test",
	"stdio read write test",
	"stdio fgets",
	"stdio tmpfile",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// 		+-- MN_CB_IO }}}2


// 		+-- MN_CB_MEM菜单 {{{2
char *cb_mem_menu[] = {
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// 		+-- MN_CB_MEM }}}2


// +-- CBASE菜单结束 }}}1


// +-- cxxbase菜单及其子菜单 {{{1
char *cxxbase_menu[] = {
	"cxx base menu item -- ",
	"return to previous menu",
	"quit",
	NULL
};


// +-- cxxbase }}}1


// +-- 数据结构菜单及其子菜单 {{{1
char *ds_menu[] = {
	"datastructure menu item -- stack",
	"datastructure menu item -- list",
	"datastructure menu item -- tree",
	"datastructure menu item -- graph",
	"return to previous menu",
	"return to main menu",
	"quit",
	NULL
};


// +-- 数据结构 }}}1


// +-- linux菜单及其子菜单 {{{1
char *linux_menu[] = {
	"linux menu item -- time",
	"linux menu item -- timer",
	"linux menu item -- group",
	"return to main menu",
	"quit",
	NULL
};


// +---- LX_TIME 菜单 {{{2
char *lx_time_menu[] = {
	"time test",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// +---- LX_TIME }}}2


// +---- LX_TIMER 菜单 {{{2
char *lx_timer_menu[] = {
	"exec timer by thread",
	"stop timer",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// +---- LX_TIMER }}}2


// +-- linux }}}1


// +-- thread菜单及其子菜单 {{{1
char *thread_menu[] = {
	"thread mutex test",
	"thread cond test",
	"thread sem test",
	"thread key test",
	"thread project test",
	"return to previous menu",
	"quit",
	NULL
};
// +-- thread }}}1


// +-- process菜单及其子菜单 {{{1
char *process_menu[] = {
	"process wait test",
	"process waitpid test",
	"process zombie test",
	"process orphan test",
	"return to previous menu",
	"quit",
	NULL
};
// +-- process }}}1


// +- IPC进程间通信菜单及其子菜单 {{{1
char *ipc_menu[] = {
	"ipc menu item -- pipe",
	"ipc menu item -- signal",
	"ipc menu item -- share memory",
	"ipc menu item -- mesage queue",
	"ipc menu item -- semaphor",
	"return to main menu",
	"quit",
	NULL
};


// +-- MN_IPC_SHM菜单 {{{2
char *ipc_shm_menu[] = {
	"shm posix test",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// +-- MN_IPC_SHM }}}2


// +-- MN_IPC_MESG菜单 {{{2
char *ipc_mesg_menu[] = {
	"mesg state test : mesg queue state test",
	"mesg rw test: posix mesg queue rw test",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// +-- MN_IPC_MESG }}}2


// +-- MN_IPC_SEM菜单 {{{2
char *ipc_sem_menu[] = {
	"sem test : semaphor function test",
	"posix sem test",
	"return to previous menu",
	"return to main menu",
	"clear",
	"quit",
	NULL
};
// +-- MN_IPC_SEM }}}2


// +- IPC }}}1


// +-- network菜单及其子菜单 {{{1
char *network_menu[] = {
	"network menu item -- tcp",
	"network menu item -- udp",
	"network menu item -- groupcast",
	"return to previous menu",
	"quit",
	NULL
};
// +-- network }}}1


// 向struct _menu结构体变量数组中注册界面 {{{1


// 宏定义 {{{2
#define register_menu(total_menu, tp, name, items, func) \
	total_menu[tp].type = tp;\
	total_menu[tp].menu_name = name;\
	total_menu[tp].menu_items = &items;\
	total_menu[tp].menu_func = func;
// 宏定义 }}}2


// 各个界面注册函数 {{{2


// 注册main界面 {{{3
void add_main_menu(struct _menu total_menu[])
{
	register_menu(total_menu, MENU_MAIN, "main menu", main_menu, do_main_menu);
}
// main }}}3


// 注册CBASE界面 {{{3
void add_cbase_menu(struct _menu total_menu[])
{
	register_menu(total_menu, MENU_CBASE, "C base menu", cbase_menu, do_cbase_menu);
	// CBASE界面的子界面
	register_menu(total_menu, MN_CB_PRINT, "print test menu", cb_print_menu, do_cb_print_menu);
	register_menu(total_menu, MN_CB_STRUCT, "struct test menu", cb_struct_menu, do_cb_struct_menu);
	register_menu(total_menu, MN_CB_POINTER, "pointer test menu", cb_pointer_menu, do_cb_pointer_menu);
	register_menu(total_menu, MN_CB_IO, "io test menu", cb_io_menu, do_cb_io_menu);
	register_menu(total_menu, MN_CB_MEM, "memory test menu", cb_mem_menu, do_cb_mem_menu);
}
// cbase }}}3
 

// 注册CXXBASE界面 {{{3

// cxxbase }}}3


// 注册DATASTRUCTURE界面 {{{3

// datastructure }}}3


// 注册LINUX界面 {{{3
void add_linux_menu(struct _menu total_menu[])
{
	register_menu(total_menu, MENU_LINUX, "linux menu", linux_menu, do_linux_menu);
	// LINUX界面的子界面
	register_menu(total_menu, MN_LINUX_TIME, "time test menu", lx_time_menu, do_lx_time_menu);
	register_menu(total_menu, MN_LINUX_TIMER, "timer test menu", lx_timer_menu, do_lx_timer_menu);
}
// LINUX }}}3

 
// 注册THREAD界面 {{{3
void add_thread_menu(struct _menu total_menu[])
{
	register_menu(total_menu, MENU_THREAD, "thread menu", thread_menu, do_thread_menu);
}
// thread }}}3


// 注册process界面 {{{3
void add_process_menu(struct _menu total_menu[])
{
	register_menu(total_menu, MENU_PROCESS, "process menu", process_menu, do_process_menu);
}
// process }}}3


// 注册IPC界面 {{{3
void add_ipc_menu(struct _menu total_menu[])
{
	register_menu(total_menu, MENU_IPC, "ipc menu", ipc_menu, do_ipc_menu);
	register_menu(total_menu, MN_IPC_SHM, "ipc shm menu", ipc_shm_menu, do_ipc_shm_menu);
	register_menu(total_menu, MN_IPC_MESG, "ipc mesg menu", ipc_mesg_menu, do_ipc_mesg_menu);
	register_menu(total_menu, MN_IPC_SEM, "ipc sem menu", ipc_sem_menu, do_ipc_sem_menu);
}
// ipc }}}3


// 注册network界面 {{{3

// network }}}3


// 各个界面注册函数结束 }}}2


// total_menu_register 注册界面函数 {{{2
/**
 * @函数说明：total_menu_register 
 * 			  将所有界面注册到total_menu中
 * @函数参数：total_menu
 *     		  表示包含全部界面信息的结构体数组变量
 */
void total_menu_register(struct _menu total_menu[])
{
	int i = 0;
	void (*reg_menu_buf[])(struct _menu total_menu[]) = {
		add_main_menu,
		add_cbase_menu,
		add_linux_menu,
		add_thread_menu,
		add_process_menu,
		add_ipc_menu,
		NULL
	};

	while (reg_menu_buf[i] != NULL)
	{
		reg_menu_buf[i](total_menu);
		i++;
	}
}
// total_menu_register }}}2


// 注册界面 }}}1


// draw_cur_menu 画出当前界面函数 {{{1
/**
 * @函数说明：draw_cur_menu 
 * 			  画出当前界面
 *
 * @函数参数：pmenu 
 * 			  界面结构体变量指针
 */
void draw_cur_menu(struct _menu *pmenu)
{
	int i = 0;
	char * p = NULL;

	system("clear");

	printf("-----------------------------------------\n");
	printf("\t\t%s\n", pmenu->menu_name);
	printf("-----------------------------------------\n");

	while ((p = *(*pmenu->menu_items + i)))
	{
		printf("%d.%s\n", i + 1, p);
		i++;
	}
	printf("-----------------------------------------\n");

	pmenu->items_num = i;
}
// draw_cur_menu }}}1
