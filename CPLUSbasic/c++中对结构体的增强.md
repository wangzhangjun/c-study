# c++中对结构体的增强
* C语⾔言的struct定义了⼀一组变量的集合，C编译器并不认为这是⼀一种新的类型
* C++中的struct是⼀一个新类型的定义声明

```
#include <iostream>
struct Student
{
   char name[100];
   int age;
 };

int main(int argc, char *argv[])
{
   Student s1 = {"wang", 1};  //在C语言中定义时，必须是Struct student
   Student s2 = {"wang2", 2};
   return 0;
}
```
