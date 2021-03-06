#include <stdio.h>

void test()
{
    int a[] = {1, 2, 3};
    printf("a:%p\n",a); 
    printf("&a:%p\n", &a[0]);//和上面的相同
    printf("*a:%d\n", *a);  //相当于*(a+0)
    printf("*a:%d\n", *(a+0)); //1
}

void test1()
{
    //即：a[0] => *(a+0) => p[0] => *(p+0)
    int a[] = {1, 2, 3};
    int len = sizeof(a) / sizeof(a[0]);
    int *p = a;  //a是一个常量地址，赋值给指针变量
    for(int i = 0; i < len; i++) {
        //这几种访问内存的方式都是一样的
        printf("%d\n", a[i]);
        printf("%d\n", *(a+i));
        printf("%d\n", *(p + i));
        printf("%d\n", p[i]);
    }
}

void test2()
{
    // 1. 指针的类型，决定了从指针存储的地址开始，向后读取的字节数，不影响指针的大小（都是4字节）
    // 2. 指针的类型，决定了指针+1操作后，向后加过的 字节数
    int a = 0x12345678;
    int *p = &a;        //相当于int *p = &a[0],可以指向任意:int *p = &a[8]
    printf("%p\n", *p); //0x12345678;

    short *p2 = &a;
    printf("%p\n", *p2); //0x5678

    char *p1 = &a;
    printf("%p\n", *p1); //0x78

    printf("p:%p\n", p);  
    printf("p:%p\n", p+1);  //比上面的大了4

    printf("p1:%p\n", p1);
    printf("p1:%p\n", p1 + 1); //比上面的大了1

    printf("p1:%p\n", p2);
    printf("p1:%p\n", p2 + 1); //比上面的大了2
}

void test3()
{
    //&数组名 + 1， 加一个数组的大小（3 * sizeof(int)）
    int a[] = {1, 2, 3};
    
    printf("a:%p\n", a);
    printf("&a[0]:%p\n", &a[0]);
    printf("&a:%p\n", &a);      //前3个都相同
    printf("&a+1:%p\n", &a+1);  //比前面多了12，一个数组的大小
}

//指针加减指针
void test4()
{
    int a[] = {1, 2, 3};
    int *p = &a[2];
    printf("%d\n", p-a);//a
}

//数组做函数参数 //退化为指针，所以一般会把数组的长度传递进来
void test5(int a[]) 
{
    printf("%d\n", sizeof(a) /sizeof(a[0])); 
}
int main()
{
    int a[] = {1,2,3,4,5};
    int b[3];
    // b = a;//error ,数组名是一个常量，常量是不能被修改的。
    int *p = b;  //但是这样是可以的，因为指针是一个变量，可以使用数组名给指针做赋值操作
    test();
    //test1();
    // test5(a);
}