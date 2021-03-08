#include <stdio.h>

//用typedef 定义一个数组类型
void test()
{
    int arr[5] = {1,2,3,4,5};
    /*
    以前特别不理解这种写法，可以尝试三步走：
    1. 要给谁起别名，就定义谁，比如要typedef int arr[5],那就定义一个: int arr[5].
    2. 用新的类型名替换原有的名字：int MY_ARR[5]
    3. 在整个类型前面加typedef: typedef int MY_ARR[5]
    这样MY_ARR就是一个数组类型，该数组必须是5个元素，每个元素都是int
    */
    typedef int MY_ARR[5];
    MY_ARR arr1 = {1, 2, 3, 4, 5};
    for(int i=0; i< sizeof(arr1)/sizeof(int); i++) {
        printf("%d\n", arr1[i]);
    }

    //数组类型指针
    MY_ARR *p = &arr1;
    for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        printf("%d\n", (*p)[i]); //*p 就是arr， 再加上[]就表示的是第几个
    }
}

//用typedef直接定义一个数组类型指针
void test1()
{
    int arr[5] = {1, 2, 3, 4, 5};
    /*
    按照上面的三步走，本来就定义成为了 typedef int* MY_ARR[5];
    但是因为[]的优先级太高了，所以就定义成为了一个存放指针的数组，即MY_ARR中存放都是int *类型的指针
    而我们希望的是*和MY_ARR结合
    所以要加个括号，才能是数组指针。
    */

    //不加括号的形式
    typedef int* MY_ARR[3];
    int a=1,b=2,c=3;
    MY_ARR p = {&a, &b, &c};
    printf("%d\n", *(p[2]));

    //加括号的形式
    typedef int(*MY_ARR1)[5];
    MY_ARR1 p1 = &arr;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d\n", (*p1)[i]); //*p 就是arr， 再加上[]就表示的是第几个
    }
}

//反过头来再看一位数组的地址
void test2()
{
    //直接定义数组指针
    int arr[5] = {1, 2, 3, 4, 5};
    int (*p)[5] = &arr;  //所以你明白了为啥&arr的步长了吗？ 指针的步长由类型决定，这是一个数组指针的类型。所以说对数组名取地址，
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        printf("%d\n", (*p)[i]); //*p 就是arr， 再加上[]就表示的是第几个
    }
}

int main()
{
    test2();
    return 0;
}