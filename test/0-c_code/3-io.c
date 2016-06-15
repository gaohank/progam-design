#include "../../include/head.h"
#include "unistd.h"

#define FILE_PATH "init.conf.txt" 	// 初始化配置文件
#define BUFFSIZE 1024

/*
 * 保存配置信息结构体
 */
struct _tag_conf {
	char ch;
	short s;
	float f;
	int i;
};

/**
 * @函数说明：stdio_fopen 
 * 			  测试标准IO的打开功能
 */
void stdio_fopen()
{
	FILE *fp;
	char file_path[100];
	
	printf("input open file path\n");

	scanf("%s", file_path);

	if (NULL == (fp = fopen(file_path, "r+")))
	{
		/* 报错但是不退出程序
		 * 0 -- 不退出，1 -- 退出
		 */
		error(0, errno, "fopen %s failed: %s-%s-%d\n", \
				file_path ,__FILE__, __func__, __LINE__);
		return;
	}

	fclose(fp);
}

/**
 * @函数说明：stdio_rdwr 
 * 			  测试标准的读写操作
 */
void stdio_rdwr()
{
	FILE *fp;
	struct _tag_conf confr[10], confw[3] = {
		[0] = {'a', 10, 10.0, 100},
		[1] = {'b', 20, 11.0, 200},
		[2] = {'c', 30, 12.0, 300},
	};
	int wdcnt = 0;
	
	if (NULL == (fp = fopen(FILE_PATH, "wb+")))
	{
		/* 报错但是不退出程序
		 * 0 -- 不退出，1 -- 退出
		 */
		error(0, errno, "fopen %s failed: %s-%s-%d\n", \
				FILE_PATH ,__FILE__, __func__, __LINE__);
		return;
	}

	printf("the file discriptor is %d\n", fileno(fp));

	/* 写数据 */
	printf("the confw size is %d\n", sizeof confw);
	wdcnt = fwrite(confw, sizeof confw, 1, fp);	
	printf("the write word is %d\n", wdcnt);

	printf("file size is %ld\n", ftell(fp));
	printf("fgetc is %d\n", fgetc(fp));

	fseek(
			fp, 
			0, 			// 偏移为0 
			SEEK_SET);  // 设置到文件头

	/* 读数据 */
	wdcnt = fread(confr, sizeof(struct _tag_conf), 10, fp);
	printf("wdcnt is %d\nfeof is %d\nEOF is %d\n", wdcnt, feof(fp), EOF);
	printf("confr is %c\t%d\t%f\t%d\n", confr[2].ch, confr[2].s, \
			confr[2].f, confr[2].i);

	/*wdcnt = fread(&confr, sizeof confr, 1, fp);*/
	/*printf("wdcnt is %d\nfeof is %d\n", wdcnt, feof(fp));*/
	/*printf("confr is %c\t%d\t%f\t%d\n", confr.ch, confr.s, \*/
			/*confr.f, confr.i);*/

	/*wdcnt = fread(&confr, sizeof confr, 1, fp);*/
	/*printf("wdcnt is %d\nfeof is %d\n", wdcnt, feof(fp));*/
	/*printf("confr is %c\t%d\t%f\t%d\n", confr.ch, confr.s, \*/
			/*confr.f, confr.i);*/

	wdcnt = fread(&confr, sizeof confr, 1, fp);
	printf("wdcnt is %d\nfeof is %d\n", wdcnt, feof(fp));

	fclose(fp);

	remove(FILE_PATH); // 删除文件或目录
}

/**
 * @函数说明：stdio_fgets 
 * 			  测试fgets函数
 */
void stdio_fgets()
{
	FILE *fp;
	char buf[BUFFSIZE] = "helloworld";

	if (NULL == (fp = fopen(FILE_PATH, "w+")))
	{
		/* 报错但是不退出程序
		 * 0 -- 不退出，1 -- 退出
		 */
		error(0, errno, "fopen %s failed: %s-%s-%d\n", \
				FILE_PATH ,__FILE__, __func__, __LINE__);
		return;
	}

	if (EOF == fputs(buf, fp))
	{
		goto ERR;
	}

	if (EOF == fputs(buf, fp))
	{
		goto ERR;
	}

	/*fseek(fp, 0, SEEK_SET);*/
	rewind(fp); // 重新将文件指针定位在流开始的地方
	memset(buf, 0, BUFFSIZE);
	
	/*
	 *fgets函数会取得BUFFISIZE-1个数据，然后在最后1位加‘\0’
	 *如果遇到换行符号，则读入'\n'并退出;
	 *如果遇到EOF则直接推出;
	 * */
	while (NULL != fgets(buf, BUFFSIZE, fp)) // fgets会取得换行符
	{
		fputs(buf, stdout); // fputs不会在字符串后加上'\n'
		printf("\nfeof is %d\n", feof(fp));
	}
	printf("current position ftell is %ld\n", ftell(fp));
	printf("feof is %d\n", feof(fp));

	fclose(fp);

	unlink(FILE_PATH); // 删除文件名FILE_PATH，如果这是文件的唯一名字，则删除该文件
	return;

ERR:
	error(0, errno, "fputs failed\n");
	fclose(fp);
}

/**
 * @函数说明：stdio_tmpfile 
 * 			  测试临时函数tmpfile和tmpnam
 */
void stdio_tmpfile()
{
	FILE *fp;
	char buff[128] = {'a', '\0', 'b', '\0', 'c', '\0'};
	char buf[128];
	
	fp = tmpfile(); // 创建临时文件，返回指向该流的指针

	if (NULL == fp)
	{
		error(0, errno, "tmpfile");
		return;
	}

	/*fputs("helloworld", fp);*/
	/*fputs(buff, fp);*/
	fwrite(buff, 1, 128, fp); // 按二进制写入文件，包括'\0'终止符
	rewind(fp);
	puts(fgets(buf, 128, fp));
	printf("%c %c %c\n", buf[0], buf[2], buf[4]);

	fclose(fp); // 当文件关闭或程序正常终止时，会自动删除该临时文件
}
