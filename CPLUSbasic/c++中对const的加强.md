# c++中对const的加强

### 1.const复习
```
#include <iostream>
int main(void)
{
  //const 定义常量---> const 意味只读
  const int a;
  int const b;
  //第⼀个第⼆个意思⼀样 代表一个常整形数
  const int *c;
  //第三个 c是一个指向常整形数的指针(所指向的内存数据不能被修改，但是本⾝身可以修改)
  int * const d;
  //第四个 d 常指针(指针变量不能被修改，但是它所指向内存空间可以被修改)
  const int * const e ;
  //第五个 e⼀个指向常整形的常指针(指针和它所指向的内存空间，均不能被修改)
  return 0;
}
```

### 2.C语言中的冒牌const
```
#include <stdio.h>
int main() {
    const int a = 10;
    int *p = (int*)&a;
    printf("a===>%d\n", a);
       *p = 11;
       printf("a===>%d\n", a);
       return 0;
   }
```

### 3.c++中的真正的const
```
void main03()
{
    const int a = 10;
    ·    //在c++里面通过const修饰的东西，会变成什么样子呢?在c++里面是将其放在一个符号表（没有地址）里面
    int *p = NULL;
    //当你对a取地址的时候，有一个内存空间（&a   a的内存空间）
    p = (int *)&a;//执行&a的时候，重新开辟内存，让p 指向这个内存，所以改变*p，和符号表里面的值没有关系
    printf("修改之前a:%d\n", a);//输出10
    *p = 11;
    printf("修改之后a:%d\n", a);//输出10
    printf("*p:%d", *p);     //输出11

    system("pause");
}
```
* 在c++里面（真正的常量），当你const int a的时候，实际上是在符号表里面，只有当你&a的时候才会给分配一个内存空间

* 在c里面的const是只读变量（冒牌货），有自己的内存空间

* const（由编译器处理，提供类型检查和作用域检查）和define（由预处理处理，单纯的文本替换）的作用域不一样

### 4.const和#define的区别
```
#include <iostream>
void fun1() {
#define a 10
    const int b = 20;
}
void fun2() {
    printf("a = %d\n", a);  //正确
    //printf("b = %d\n", b); //错误
}
int main() {
    fun1();
    fun2();
    return 0;
}
```
* 1.const常量是由编译器处理的，提供类型检查和作用域检查
* 2.宏定义由预处理器处理，单纯的文本替换
