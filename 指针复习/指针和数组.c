#include <stdio.h>

void test()
{
    int a[] = {1, 2, 3};
    printf("a:%p\n",a); 
    printf("&a:%p\n", &a[0]);//和上面的相同
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
    int *p = &a;
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

int main()
{
    int a[] = {1,2,3};
    int b[3];
    // b = a;//error ,数组名是一个常量，常量是不能被修改的。
    int *p = b;  //但是这样是可以的，因为指针是一个变量，可以使用数组名给指针做赋值操作
    // test();
    //test1();
    test2();
}