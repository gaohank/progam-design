#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <string.h>

// CBASE {{{1


// +-- print test {{{2
void pt_show_color();
void pt_show_scanf();
void pt_show_format();
void pt_show_priority();
void pt_show_endian();
void pt_show_var_addr();
// print test }}}2


// +-- struct test {{{2
void st_show_size();
void st_show_alignment();
// struct test }}}2


// +-- pointer test {{{2
void ptr_show_array();
void ptr_show_pointer();
// pointer test }}}2


// +-- io test {{{2
void stdio_fopen();
void stdio_rdwr();
void stdio_fgets();
void stdio_tmpfile();
// io test }}}2


// CBASE }}}1


// LINUX {{{1


// +-- timer test {{{2
void timer_by_thread();
void timer_stop();
// +-- timer test }}}2


// +-- time test {{{2
int timetest();
// +-- time test }}}2


// LINUX }}}1


// THREAD {{{1
void thd_mutex_test();
void thd_cond_test();
void thd_sem_test();
void thd_key_test();
void thd_project_test();
// THREAD }}}1


// PROCESS {{{1
void pcs_wait_test();
void pcs_waitpid_test();
void pcs_zombie_test();
void pcs_orphan_test();
// PROCESS }}}1


// IPC {{{1
int shm_posix_test();
int mesg_stat_test();
int mq_send_recv_test();
int sem_func_test();
int posix_sem_test();
// IPC }}}1

#endif
