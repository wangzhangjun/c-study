#include <stdio.h>

//指针数组本质是一个二级指针
//指针数组是存储地址的数组，每个元素都是地址
void test()
{
    int a = 10;
    int b = 20;
    int c = 30;

    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;

    int *arr[] = {p1, p2,p3};  //指针数组
    
    //都是打印10的值
    printf("%d\n", *(arr[0])); //根据之前的知识： arr[0] => *(arr+0),那么 *(arr[0]) => *(*(arr+0)) => **(arr)
    printf("%d\n", **arr); // *(*(arr+0))

    printf("%d\n", *(arr[1])); //20 可读
}

void test2()
{
    int a[] = {10, 11};
    int b[] = {20, 21};
    int c[] = {30, 31};

    int *p1 = a;
    int *p2 = b;
    int *p3 = c;

    int *arr[] = {p1, p2, p3};
    printf("%d\n",arr[0][1]); //11  技术推演 arr[0] 是第一个数组的地址，访问元素arr[1]是第一个数组的首地址
    printf("%d\n", *(arr[0]+1)); //11
}
int main()
{
    test2();
    return 0;
}