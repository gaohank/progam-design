##
## 编译progam-design工程，生成progam可执行文件 
##


CC := gcc
CFLAGS := -Wall -g
OBJDIR := ./obj
OBJS := progam-design.o\
	menu/menu_item.o\
	menu/menu_func.o\
	test/C_code/0-print.o\
	test/C_code/1-struct.o\
	test/C_code/2-pointer.o\
	test/C_code/3-io.o\
	test/linux_code/1-timer.o\
	test/linux_code/2-time.o\
	test/thread_code/thdopt.o\
	test/process_code/pcsopt.o\
	test/ipc_code/3_shm.o\
	test/ipc_code/4_mesg.o\
	test/ipc_code/5_sem.o\
	test/network_code/1-tcp.o
TARDIR := ./out
TAR := $(TARDIR)/progam 

## $(waldcard $(TARDIR))如果匹配上，则为./out
## 否则为空

.PHONY: all clean
all: $(TAR)
	mkdir -p $(OBJDIR)
	mv $(OBJS) $(OBJDIR)

$(TAR):$(OBJS)
	mkdir -p $(TARDIR)
	$(CC) $(CFLAGS) $^ -o $@ -lrt

$(OBJS):%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@
 
clean:
	-rm -rf $(TARDIR) $(OBJDIR) $(TAR)

cleanobj:
	-rm -rf $(OBJDIR)
