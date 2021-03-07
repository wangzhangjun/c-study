#include <iostream>
#include <stdio.h>


void test()
{
    int arr[] = {1, 2, 3};
    //需求：给arr取一个别名
    /*
    给谁起别名，就定义谁：
    1. 取个别名，写出来：&my_arr
    2. 给谁起别名，就定义谁：int arr[]
    3. 替换： int &my_arr[], 但是请注意，[]优先级最高，会和my_arr结合，就变成了一个数组，这个数组中存放的都是引用元素
        所以要用（）： int (&my_arr)[]
    */
    
    int len = sizeof(arr) / sizeof(int);
    int(&my_arr)[3] = arr; //数组的引用
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", my_arr[i]);
    }
}

void test2()
{
    int arr[3] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(int);

    typedef int my_arr[3];  //用typedef定义一个数组类型， 参考《数组指针技术推演》的笔记
    my_arr &test = arr;     //数组类型定义一个引用
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", test[i]);
    }
}
int main()
{
    test2();
    return 0;
}