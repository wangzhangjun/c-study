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
//函数返回引用
int &test3()
{
    //不能返回栈变量
    int num = 10;
    return num; //函数返回谁，引用就是该变量的别名
}

int &test4()
{
    //可以返回static的变量
    static int num = 10;
    return num;
}

//当函数作为左值是，必须返回引用
//你看下面的调用：test5() = 00; 如果说test5()返回的是一个具体的数字的话，就出错了，数字是不能放在=的左边的。
//而返回的是引用的时候，就是一个变量的别名，当然是可以作左值的。
int &test5()
{
    static int num = 10;
    std::cout << num << std::endl;
    return num;
}


int main()
{

    test5() = 00;  //把00赋值给test5()函数的返回值
    test5();//0
    // int &ret = test3(); //ret是num的别名，因为是栈变量，已经释放，别名指向一个不确定的空间
    // std::cout << ret << std::endl;

    // int &ret1 = test4();
    // std::cout << ret1 << std::endl;
    return 0;
}





















