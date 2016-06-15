#ifndef __MENU_COMMON_H__
#define __MENU_COMMON_H__

#include "menu.h"

// 生成各个界面条目的枚举类型 {{{1


// +- 宏定义 {{{2
#define menu_enum_start(menu) enum menu##_item {\
	menu##begin,\

#define main_enum_end \
	MAIN_QUIT,\
};

// 一般界面需要有返回主菜单和退出选项
#define menu_enum_end(flag) \
	flag##_RETURN,\
	flag##_QUIT,\
};

// 测试界面需要有清空测试内容的选项，和返回上一级选项
#define test_menu_enum_end(flag) \
	flag##_PREVIOUS,\
	flag##_RETURN,\
	flag##_CLEAR,\
	flag##_QUIT,\
};
// 宏定义结束 }}}2


// +- 主界面各个条目枚举 {{{2
menu_enum_start(main)
	MAIN_CBASE,
	MAIN_CXXBASE,
	MAIN_DATASTRUCTURE,
	MAIN_LINUX,
	MAIN_THREAD,
	MAIN_PROCESS,
	MAIN_IPC,
	MAIN_NETWORK,
main_enum_end
// +- 主界面各个条目枚举 }}}2


// +- CBASE界面各个条目枚举 {{{2
menu_enum_start(cbase)
	CB_PRINT,
	CB_STRUCT,
	CB_POINTER,
	CB_IO,
	CB_MEM,
menu_enum_end(CB)


// 		+- CB_PRINT界面条目枚举类型 {{{3
menu_enum_start(cb_print)
	CB_PT_WITH_COLOR,
	CB_PT_WITH_SCANF,
	CB_PT_WITH_FORMAT,
	CB_PT_WITH_PRIORITY,
	CB_PT_WITH_ENDIAN,
	CB_PT_WITH_VAR_ADDR,
test_menu_enum_end(CB_PT)
// 		+- CB_PRINT }}}3


// 		+- CB_STRUCT界面条目枚举类型 {{{3
menu_enum_start(cb_struct)
	CB_ST_SHOW_SIZE,
	CB_ST_SHOW_ALIGN,
test_menu_enum_end(CB_ST)
// 		+- CB_STRUCT }}}3


// 		+- CB_POINTER界面条目枚举类型 {{{3
menu_enum_start(cb_ptr)
	CB_PTR_SHOW_ARRAY_ADDR,
	CB_PTR_SHOW_POINTER,
test_menu_enum_end(CB_PTR)
// 		+- CB_POINTER }}}3


// 		+- CB_IO界面条目枚举类型 {{{3
menu_enum_start(cb_io)
	CB_IO_FOPEN,
	CB_IO_RDWR,
	CB_IO_FGETS,
	CB_IO_TMPFILE,
test_menu_enum_end(CB_IO)
// 		+- CB_IO }}}3


// 		+- CB_MEM界面条目枚举类型 {{{3
menu_enum_start(cb_mem)
test_menu_enum_end(CB_MEM)
// 		+- CB_MEM }}}3


// +- CBASE及其子界面条目枚举类型结束 }}}2


// +- CXXBASE界面各个条目枚举 {{{2
menu_enum_start(cxxbase)
menu_enum_end(CXXB)
// +- CXXBASE }}}2


// +- 数据结构界面各个条目枚举 {{{2
menu_enum_start(datastructure)
	DS_STACK,
	DS_LIST,
	DS_TREE,
	DS_GRAPH,
menu_enum_end(DS)
// +- 数据结构 }}}2


// +- linux界面各个条目枚举 {{{2
menu_enum_start(linux)
	LX_TIME,
	LX_TIMER,
	LX_URGP,
menu_enum_end(LX)


// +-- LX_TIME界面条目 {{{3
menu_enum_start(lx_time)
	LX_TIME_TEST,
test_menu_enum_end(LX_TIME)
// +-- LX_TIME }}}3


// +-- LX_TIMER界面条目 {{{3
menu_enum_start(lx_timer)
	LX_TIMER_EXEC_BY_THREAD,
	LX_TIMER_STOP,
test_menu_enum_end(LX_TIMER)
// +-- LX_TIMER }}}3


// +- linux }}}2


// +- thread界面各个条目枚举 {{{2
menu_enum_start(thread)
	THD_MUTEX,
	THD_COND,
	THD_SEM,
	THD_KEY,
	THD_PROJ,
menu_enum_end(THD)
// +- thread }}}2

	
// +- process界面各个条目枚举 {{{2
menu_enum_start(process)
	PCS_WAIT,
	PCS_WAITPID,
	PCS_ZOMBIE,
	PCS_ORPHAN,
menu_enum_end(PCS);
// +- process }}}2


// +- ipc界面各个条目枚举 {{{2
menu_enum_start(ipc)
	IPC_PIPE,
	IPC_SIGNAL,
	IPC_SHM,
	IPC_MESG,
	IPC_SEM,
menu_enum_end(IPC)


// 		+- IPC_SHM界面条目枚举类型 {{{3
menu_enum_start(ipc_shm)
	IPC_SHM_POSIX_TEST,
test_menu_enum_end(IPC_SHM)
// 		+- IPC_SHM }}}3


// 		+- IPC_MESG界面条目枚举类型 {{{3
menu_enum_start(ipc_mesg)
	IPC_MESG_SYSV_STATE,
	IPC_MESG_POSIX_RW,
test_menu_enum_end(IPC_MESG)
// 		+- IPC_MESG }}}3


// 		+- IPC_SEM界面条目枚举类型 {{{3
menu_enum_start(ipc_sem)
	IPC_SEM_FUNCTION,
	IPC_POSIX_SEM_TEST,
test_menu_enum_end(IPC_SEM)
// 		+- IPC_SEM }}}3


// +- ipc }}}2


// +- network界面各个条目枚举 {{{2
menu_enum_start(network)
	NW_TCP,
	NW_UDP,
	NW_GROUP,
menu_enum_end(NW)
// +- network 2}}}


// 各个界面枚举类型定义结束 }}}1


// 声明各个界面条目对于的处理函数 {{{1
enum menu_type do_main_menu(int);
enum menu_type do_cbase_menu(int);
	enum menu_type do_cb_print_menu(int);
	enum menu_type do_cb_struct_menu(int);
	enum menu_type do_cb_pointer_menu(int);
	enum menu_type do_cb_io_menu(int);
	enum menu_type do_cb_mem_menu(int);
enum menu_type do_cxxbase_menu(int);
enum menu_type do_ds_menu(int);
enum menu_type do_linux_menu(int);
	enum menu_type do_lx_time_menu(int);
	enum menu_type do_lx_timer_menu(int);
enum menu_type do_thread_menu(int);
	enum menu_type do_thd_mutex_menu(int);
enum menu_type do_process_menu(int);
enum menu_type do_ipc_menu(int);
	enum menu_type do_ipc_shm_menu(int);
	enum menu_type do_ipc_mesg_menu(int);
	enum menu_type do_ipc_sem_menu(int);
enum menu_type do_network_menu(int);
// 声明界面各项处理函数结束 }}}1

#endif
