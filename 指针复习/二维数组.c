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

int main()
{
    test1();
    return 0;
}