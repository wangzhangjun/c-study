#include <stdio.h>

void test()
{
    int arr[2][3] =  {
        {2,5,8},
        {3,6,9}
    };
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void test1()
{
    int arr[2][3] = {
        {2, 5, 8},
        {3, 6, 9}};
    printf("%lu\n", sizeof(arr));                //24： 数组大小
    printf("%lu\n", sizeof(arr[0]));           //12：一行的大小
    printf("%lu\n", sizeof(arr) / sizeof(arr[0])); //2： 行数,有几个一维数组, 技术推演：一维数组的大小：sizeof(arr) / sizeof[arr[0]]
    printf("%lu\n", sizeof(arr[0][0])); //4：一个元素的大小
    printf("%lu\n", sizeof(arr[0])/sizeof(arr[0][0])); //3：列数
}

void test2()
{
    int arr[2][3] = {
        {2, 5, 8},
        {3, 6, 9}};
    printf("%p\n", arr);  //数组首地址
    printf("%p\n", &arr[0][0]);        //首元素的地址
    printf("%p\n", arr[0]);  //数组的首行地址。 技术推演：一维数组的首地址arr==&arr==&arr[0]
    //前三个一样
    /* 技术推演(为什么arr[i]表示第i个整体数组的地址)：
    类比一维数组的&arr+1,是往前跳整个数组的字节数。
    所以arr[1]到arr[0]也是差了二维数组中的一个一维数组的字节数，
    就像是一维数组的&arr表示的是整个数组的地址，
    所以arr[i]表示的是一维数组的整体数组的地址。*/
    printf("%p\n", arr[1]);   //比上面是差了12,第二个一维数组的首地址。
    printf("%p\n", arr[0]+1); //比上面三个是差了4，往后加了一个元素的地址
    printf("%d\n", *(arr[0] + 1)); //5
    printf("%d\n", *(arr[0]));     //2 相当于 *(arr[0] + 0)； 技术推演 => 一维数组的*(arr)打印的是首元素的值（参考指针与一维数组）
    printf("%p\n", &(arr[0]) + 1); //比上面是差了12，把第一个一维数组跳过去了,也就是第二个一维数组的首地址
}

int main()
{
    test2();
    return 0;
}