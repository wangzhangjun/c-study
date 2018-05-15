# c语言对文件操作
#### 1、文件读写API
fgetc fputc  按照字符读写文件
fputs fgets 按照行读写文件（读写配置文件）
fread fwirte 按照块读写文件（大数据块的搬移）
####2、按字符写入文件
```
void main01()//写文件（按字符）
{
	int i = 0;
	FILE *fp = NULL;
	char a[] = "avdfasdsa";
	char *filename = "c:/1.txt";//Linux和win通用
	fp = fopen(filename, "a+");
	if(fp == NULL)
	{
		printf("func open() err\n");
		return;
	}
	for(i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	fclose(fp);
	system("pause");
}
```
####3、按字符读取文件
```
void main02()
{
    int i = 0;
    FILE *fp = NULL;
    char *filename = "c:/1.txt";
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("func open() err\n");
        return;
    }
    while(!feof(fp))
    {
        char tmpc = fgetc(fp);
        printf("%c",tmpc);
    }
    fclose(fp);
    system("pause");
}
```
####4.复制一个exe文件
```
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int getfilesize(char *path)
{
	int length = 0;
	FILE *fp = fopen(path, "r");
	if(fp == NULL)
	{
		return;
	}
	else
	{
		fseek(fp, 0, SEEK_END);//将文件的指针指向文件的末尾
		length = ftell(fp);//ftell是文件指针相对于文件首的偏移字节数
		return length;//获取文件的大小
	}
}
void copy(char *oldpath, char *newpath)
{
	FILE *pfr, *pfw;
	pfr = fopen(oldpath, "rb");
	pfw = fopen(newpath, "wb");//写入二进制模式
	if(pfr == NULL || pfw == NULL)
	{
		fclose(pfr);
		fclose(pfw);
		return;
	}
	else
	{
		int length = getfilesize(oldpath);
		char *p = (char *)malloc(length * sizeof(char));//分配内存，读取文件，内存中是以最小的字节为单位来设计的
		fread(p, sizeof(char), length, pfr);//读取二进制文件
		fwrite(p, sizeof(char), length, pfw);//写入二进制文件
		fclose(pfr);
		fclose(pfw);
	}
}
void main05()
{
	char *oldpath = "C:\\Users\\wang\\Desktop\\putty.exe";
	char *newpath = "C:\\Users\\wang\\Desktop\\puttya.exe";
	copy(oldpath,newpath );
	system("pause");
}
```
####给一个二进制（exe）的文件加密
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getfilesize1(char *path)
{
	int length = 0;
	FILE *fp = fopen(path, "r");
	if(fp == NULL)
	{
		return;
	}
	else
	{
		fseek(fp, 0, SEEK_END);//将文件的指针指向文件的末尾
		length = ftell(fp);//ftell是文件指针相对于文件首的偏移字节数
		return length;//获取文件的大小
	}
}

void jia(char *oldpath, char *newpath)
{
	int i = 0;
	FILE *pfr, *pfw;
	pfr = fopen(oldpath, "rb");
	pfw = fopen(newpath, "wb");
	if(pfr == NULL || pfw == NULL)
	{
		fclose(pfr);
		fclose(pfw);
		return;
	}
	else
	{
		int length = getfilesize1(oldpath);
		char *p = (char *)malloc(length * sizeof(char));
		fread(p, sizeof(char), length, pfr);
		for(i=0; i<length; i++)
		{
			p[i] ^= 'B';//动态数组（每个数组是一个字节）
		}
		fwrite(p,sizeof(char),length, pfw);
		fclose(pfr);
		fclose(pfw);
	}
}
void jie(char *oldpath, char *newpath)
{
	int i = 0;
	FILE *pfr, *pfw;
	pfr = fopen(oldpath, "rb");
	pfw = fopen(newpath, "wb");
	if(pfr == NULL || pfw == NULL)
	{
		fclose(pfr);
		fclose(pfw);
		return;
	}
	else
	{
		int length = getfilesize1(oldpath);
		char *p = (char *)malloc(length * sizeof(char));
		fread(p, sizeof(char), length, pfr);
		for(i=0; i<length; i++)
		{
			p[i] ^= 'B';//动态数组（每个数组是一个字节）
		}
		fwrite(p,sizeof(char),length, pfw);
		fclose(pfr);
		fclose(pfw);
	}
}
void main06()
{
	char *oldpath = "C:\\Users\\wang\\Desktop\\putty.exe";
	char *newpath = "C:\\Users\\wang\\Desktop\\jiaputty.exe";
	char *newjiepath = "C:\\Users\\wang\\Desktop\\jieputtya.exe";
	jia(oldpath, newpath);
	jie(newpath, newjiepath);
	system("pause");
}
```
####普通的文件加密
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sjia(char ch)
{
	return ch ^ 123;
}
int  sjie(char ch)
{
	return ch ^ 123;   
}
void jiemi(char *pathjia, char *pathjie)
{
	char ch;
	FILE *pfr, *pfw;
	pfr = fopen(pathjia , "r");
	pfw = fopen(pathjie , "w");
	if(pfr == NULL || pfw == NULL)
	{
		return;
	}
	while(!feof(pfr))
	{
		ch = fgetc(pfr);
		fputc(sjie(ch) , pfw);
	}
	fclose(pfr);//一定要记得关闭文件
	fclose(pfw);
}
void jiami(char *oldpath, char *pathjia)
{
	char ch;
	FILE *pfr, *pfw;
	pfr = fopen(oldpath , "r");
	pfw = fopen(pathjia , "w");
	if(pfr==NULL || pfw == NULL)
	{
		return;
	}
	while(!feof(pfr))
	{
		ch = fgetc(pfr);
		fputc(sjia(ch) , pfw);
	}
	fclose(pfr);//一定要记得关闭文件
	fclose(pfw);
}
void main()
{
	char *oldpath = "C:\\Users\\wang\\Desktop\\test.txt";
	char *pathjia = "C:\\Users\\wang\\Desktop\\testjia.txt";
	char *pathjie = "C:\\Users\\wang\\Desktop\\testjie.txt";
	jiami(oldpath,pathjia);
	jiemi(pathjia,pathjie);
	system("pause");
}
```
