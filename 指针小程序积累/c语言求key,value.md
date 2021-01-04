# c语言求key,value
主调函数分配内存，被调函数通过指针去改变这个内存中的内容，好好体会这个

```
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//去掉空格的函数
int trimSpace02(char *mybuf,char *out){
    int ret = 0;
    int count = 0;
    int i=0;

    if(mybuf == NULL){
        ret = -1;
        return ret;
    }else{
        char *p =mybuf;
        int len = strlen(p);
        int j = len-1;
        while (isspace(p[i]) && p[i] != '\0'){
            i++;
        }
        while (isspace(p[j]) && (j>0)){
            j--;
        }
        count = j-i+1;
        memcpy(out,mybuf+i,count);
        out[count] = '\0';
    }
    return ret;
}

//功能函数
int getKeyByValude(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int *valuebuflen){
    //在大的字符串中查找关键字
    char *p = keyvaluebuf;
    int rv = 0;
    char tmp[2048*10];
    p = strstr(keyvaluebuf, keybuf);    
    if (p == NULL){
        return 0;
    }
    p = p + strlen(keybuf);
    //查找等号
    p = strstr(keyvaluebuf, "=");
    if (p == NULL){
        return 0;
    }
    p = p+1;
    //去掉空格
    rv = trimSpace02(p,tmp);
    if (rv != 0){
        printf("func trimSpace_ok2() err:%d\n", rv);
        return rv;
    }
    strcpy(valuebuf,tmp);
    *valuebuflen = strlen(tmp);
    return 0;
}
//主调用函数
void main(){
    int rv = 0;
    char keyvaluebuf[] = "ORACLE_name  =  itcast     ";
    char *keybuf = "ORACLE_name";
    char valuebuf[1024];
    int valuebuflen = 0;
    rv = getKeyByValude(keyvaluebuf, keybuf, valuebuf, &valuebuflen);
    if (rv != 0){
        printf("func getkeyByValue（￡¨）￡? err:%d",rv);
        return;
    }
    printf("valuebuf:%s\n", valuebuf);
    printf("valuebuflen:%d\n", valuebuflen);
    system("pause");
}
```
