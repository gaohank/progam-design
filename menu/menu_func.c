#include "../include/menu_common.h"
#include "../include/head.h"

// 所有界面及其对应的处理函数 {{{1


// +- 主界面处理函数 {{{2
enum menu_type do_main_menu(int item_no)
{
	enum menu_type menu;

	// 主界面中对应各项的处理
	switch (item_no)
	{
	case MAIN_CBASE:
		menu = MENU_CBASE;
		break;
	case MAIN_CXXBASE:
		menu = MENU_CXXBASE;
		break;
	case MAIN_DATASTRUCTURE:
		menu = MENU_DATASTRUCTURE;
		break;
	case MAIN_LINUX:
		menu = MENU_LINUX;
		break;
	case MAIN_THREAD:
		menu = MENU_THREAD;
		break;
	case MAIN_PROCESS:
		menu = MENU_PROCESS;
		break;
	case MAIN_IPC:
		menu = MENU_IPC;
		break;
	case MAIN_NETWORK:
		menu = MENU_NETWORK;
		break;
	case MAIN_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		menu = MENU_MAIN;
	}

	return menu;
}
// +- main }}}2


// +- 界面CBASE及其子界面处理函数 {{{2 
enum menu_type do_cbase_menu(int item_no)
{
	enum menu_type menu;

	// CBASE界面中对应各项的处理
	switch(item_no)
	{
	case CB_PRINT:
		menu = MN_CB_PRINT;
		break;
	case CB_STRUCT:
		menu = MN_CB_STRUCT;
		break;
	case CB_POINTER:
		menu = MN_CB_POINTER;
		break;
	case CB_IO:
		menu = MN_CB_IO;
		break;
	case CB_MEM:
		menu = MN_CB_MEM;
		break;
	case CB_RETURN:
		menu = MENU_MAIN;
		break;
	case CB_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		menu = MENU_CBASE;
		break;
	}

	return menu;
}


// 		+- CB_PRINT界面处理函数 {{{3
enum menu_type do_cb_print_menu(int item_no)
{
	enum menu_type menu;

	menu = MN_CB_PRINT;
	is_clear_sceen = FALSE;

	// CB_PRINT界面中对应各项的处理
	switch (item_no)
	{
	case CB_PT_WITH_COLOR:
		pt_show_color();
		break;
	case CB_PT_WITH_SCANF:
		pt_show_scanf();
		break;
	case CB_PT_WITH_FORMAT:
		pt_show_format();
		break;
	case CB_PT_WITH_PRIORITY:
		pt_show_priority();
		break;
	case CB_PT_WITH_ENDIAN:
		pt_show_endian();
		break;
	case CB_PT_WITH_VAR_ADDR:
		pt_show_var_addr();
		break;
	case CB_PT_PREVIOUS:
		menu = MENU_CBASE;
		is_clear_sceen = TRUE;
		break;
	case CB_PT_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case CB_PT_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case CB_PT_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// 		+- CB_PRINT }}}3


// 		+- CB_STRUCT界面处理函数 {{{3
enum menu_type do_cb_struct_menu(int item_no)
{
	enum menu_type menu;
	menu = MN_CB_STRUCT;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case CB_ST_SHOW_SIZE:
		st_show_size();
		break;
	case CB_ST_SHOW_ALIGN:
		st_show_alignment();
		break;
	case CB_ST_PREVIOUS:
		menu = MENU_CBASE;
		is_clear_sceen = TRUE;
		break;
	case CB_ST_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case CB_ST_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case CB_ST_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// 		+- CB_STRUCT }}}3


// 		+- CB_POINTER界面处理函数 {{{3
enum menu_type do_cb_pointer_menu(int item_no)
{
	enum menu_type menu;
	menu = MN_CB_POINTER;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case CB_PTR_SHOW_ARRAY_ADDR:
		ptr_show_array();
		break;
	case CB_PTR_SHOW_POINTER:
		ptr_show_pointer();
		break;
	case CB_PTR_PREVIOUS:
		menu = MENU_CBASE;
		is_clear_sceen = TRUE;
		break;
	case CB_PTR_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case CB_PTR_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case CB_PTR_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// 		+- CB_POINTER }}}3


// 		+- CB_IO界面处理函数 {{{3
enum menu_type do_cb_io_menu(int item_no)
{
	enum menu_type menu;
	menu = MN_CB_IO;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case CB_IO_FOPEN:
		stdio_fopen();
		break;
	case CB_IO_RDWR:
		stdio_rdwr();
		break;
	case CB_IO_FGETS:
		stdio_fgets();
		break;
	case CB_IO_TMPFILE:
		stdio_tmpfile();
		break;
	case CB_IO_PREVIOUS:
		menu = MENU_CBASE;
		is_clear_sceen = TRUE;
		break;
	case CB_IO_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case CB_IO_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case CB_IO_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
//		+- CB_IO }}}3 		


// 		+- CB_MEM界面处理函数 {{{3
enum menu_type do_cb_mem_menu(int item_no)
{
	enum menu_type menu;
	menu = MN_CB_MEM;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case CB_MEM_PREVIOUS:
		menu = MENU_CBASE;
		is_clear_sceen = TRUE;
		break;
	case CB_MEM_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case CB_MEM_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case CB_MEM_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// 		+- CB_MEM }}}3


// +- CBASE及其子界面处理函数结束 }}}2


// +- 界面CXXBASE处理函数 {{{2 
enum menu_type do_cxxbase_menu(int item_no)
{
	enum menu_type menu;

	switch(item_no)
	{
	case CXXB_RETURN:
		menu = MENU_MAIN;
		break;
	case CXXB_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		menu = MENU_CXXBASE;
		break;
	}

	return menu;
}
// +- CXXBASE }}}2


// +- 界面DataStructure处理函数 {{{2 
enum menu_type do_ds_menu(int item_no)
{
	/*int ret;*/
	enum menu_type menu;

	switch (item_no)
	{
	/*case DRV_IRQ_CLEAR:*/
		/*is_clear_sceen = TRUE;*/
		/*break;*/
	case DS_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +- DataStructure }}}2


// +- 界面linux处理函数 {{{2 
enum menu_type do_linux_menu(int item_no)
{
	/*int ret;*/
	enum menu_type menu;

	switch (item_no)
	{
	case LX_TIME:
		menu = MN_LINUX_TIME;
		break;
	case LX_TIMER:
		menu = MN_LINUX_TIMER;
		break;
	case LX_RETURN:
		menu = MENU_MAIN;
		break;
	case LX_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		menu = MENU_LINUX;
	}

	return menu;
}


// +- LINUX TIME界面处理函数 {{{3
enum menu_type do_lx_time_menu(int item_no)
{
	enum menu_type menu;
	menu = MN_LINUX_TIME;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case LX_TIME_TEST:
		timetest();
		break;
	case LX_TIME_PREVIOUS:
		menu = MENU_LINUX;
		is_clear_sceen = TRUE;
		break;
	case LX_TIME_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case LX_TIME_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case LX_TIME_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +- LINUX TIME }}}3


// +- LINUX TIMER界面处理函数 {{{3
enum menu_type do_lx_timer_menu(int item_no)
{
	enum menu_type menu;
	menu = MN_LINUX_TIMER;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case LX_TIMER_EXEC_BY_THREAD:
		timer_by_thread();
		break;
	case LX_TIMER_STOP:
		timer_stop();
		break;
	case LX_TIMER_PREVIOUS:
		menu = MENU_LINUX;
		is_clear_sceen = TRUE;
		break;
	case LX_TIMER_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case LX_TIMER_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case LX_TIMER_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +- LINUX TIMER }}}3


// +- linux }}}2


// +- 界面thread处理函数 {{{2 
enum menu_type do_thread_menu(int item_no)
{
	enum menu_type menu;

	menu = MENU_THREAD;
	/*is_clear_sceen = FALSE;*/

	switch (item_no)
	{
	case THD_MUTEX:
		thd_mutex_test();
		break;
	case THD_COND:
		thd_cond_test();
		break;
	case THD_SEM:
		thd_sem_test();
		break;
	case THD_KEY:
		thd_key_test();
		break;
	case THD_PROJ:
		thd_project_test();
		break;
	case THD_RETURN:
		menu = MENU_MAIN;
		break;
	case THD_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +- thread }}}2


// +- 界面porcess处理函数 {{{2 
enum menu_type do_process_menu(int item_no)
{
	enum menu_type menu;

	menu = MENU_PROCESS;
	is_clear_sceen = FALSE;

	switch (item_no)
	{
	case PCS_WAIT:
		printf("pcs_wait\n");
		pcs_wait_test();
		break;
	case PCS_WAITPID:
		printf("pcs_waitpid\n");
		pcs_waitpid_test();
		break;
	case PCS_ZOMBIE:
		printf("pcs_zombie\n");
		pcs_zombie_test();
		break;
	case PCS_ORPHAN:
		printf("pcs_orphan\n");
		pcs_orphan_test();
		break;
	case PCS_RETURN:
		is_clear_sceen = TRUE;
		menu = MENU_MAIN;
		break;
	case PCS_QUIT:
		is_clear_sceen = TRUE;
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +- process }}}2


// +- 界面ipc处理函数 {{{2 
enum menu_type do_ipc_menu(int item_no)
{
	enum menu_type menu;

	switch (item_no)
	{
	case IPC_PIPE:
		break;
	case IPC_SIGNAL:
		break;
	case IPC_SHM:
		menu = MN_IPC_SHM;
		break;
	case IPC_MESG:
		menu = MN_IPC_MESG;
		break;
	case IPC_SEM:
		menu = MN_IPC_SEM;
		break;
	case IPC_RETURN:
		menu = MENU_MAIN;
		break;
	case IPC_QUIT:
		menu = MENU_QUIT;
		break;
	}

	return menu;
}


// +-- IPC_SHM界面及其处理 {{{3
enum menu_type do_ipc_shm_menu(int item_no)
{
	enum menu_type menu;

	menu = MN_IPC_SHM;
	is_clear_sceen = FALSE;

	// IPC_SHM界面中对应各项的处理
	switch (item_no) {
	case IPC_SHM_POSIX_TEST:
		shm_posix_test();
		break;
	case IPC_SHM_PREVIOUS:
		menu = MENU_IPC;
		is_clear_sceen = TRUE;
		break;
	case IPC_SHM_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case IPC_SHM_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case IPC_SHM_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +-- IPC_SHM }}}3


// +-- IPC_MESG界面及其处理 {{{3
enum menu_type do_ipc_mesg_menu(int item_no)
{
	enum menu_type menu;

	menu = MN_IPC_MESG;
	is_clear_sceen = FALSE;

	// IPC_MESG界面中对应各项的处理
	switch (item_no)
	{
	case IPC_MESG_SYSV_STATE:
		mesg_stat_test();
		break;
	case IPC_MESG_POSIX_RW:
		printf("in posix mesg test\n");
		mq_send_recv_test();
		break;
	case IPC_MESG_PREVIOUS:
		menu = MENU_IPC;
		is_clear_sceen = TRUE;
		break;
	case IPC_MESG_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case IPC_MESG_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case IPC_MESG_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +-- IPC_MESG }}}3


// +-- IPC_SEM界面及其处理 {{{3
enum menu_type do_ipc_sem_menu(int item_no)
{
	enum menu_type menu;

	menu = MN_IPC_SEM;
	is_clear_sceen = FALSE;

	// IPC_MESG界面中对应各项的处理
	switch (item_no)
	{
	case IPC_SEM_FUNCTION:
		sem_func_test();
		break;
	case IPC_POSIX_SEM_TEST:
		posix_sem_test();
		break;
	case IPC_SEM_PREVIOUS:
		menu = MENU_IPC;
		is_clear_sceen = TRUE;
		break;
	case IPC_SEM_RETURN:
		menu = MENU_MAIN;
		is_clear_sceen = TRUE;
		break;
	case IPC_SEM_CLEAR:
		is_clear_sceen = TRUE;
		break;
	case IPC_SEM_QUIT:
		menu = MENU_QUIT;
		break;
	default:
		break;
	}

	return menu;
}
// +-- IPC_SEM }}}3


// ipc }}}2


// +- 界面network处理函数 {{{2 
enum menu_type do_network_menu(int item_no)
{
	enum menu_type menu;

	/*menu = MENU_LAPI_LMI;*/
	/*is_clear_sceen = FALSE;*/

	switch (item_no)
	{
	case NW_QUIT:
		menu = MENU_QUIT;
		break;
	}

	return menu;
}
// +- network }}}2


// 所有界面及其对应的处理函数 }}}1
