##
## 编译progam-design工程，生成progam可执行文件 
##


CC := gcc
CFLAGS := -Wall -g
OBJDIR := ./obj
OBJS := progam-design.o\
	menu/menu_item.o\
	menu/menu_func.o\
	test/0-c_code/0-print.o\
	test/0-c_code/1-struct.o\
	test/0-c_code/2-pointer.o\
	test/0-c_code/3-io.o\
	test/3-linux_code/1-timer.o\
	test/3-linux_code/2-time.o\
	test/4-thread_code/thdopt.o\
	test/5-process_code/pcsopt.o\
	test/6-ipc_code/3-shm.o\
	test/6-ipc_code/4-mesg.o\
	test/6-ipc_code/5-sem.o\
	test/7-network_code/1-tcp.o
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
