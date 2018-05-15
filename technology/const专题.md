# const专题

```
void main()
{
    const int a = 0;//这两种写法是一样的，代表一个常整形数
    int const b = 1;//加了const就不能随便的改变它的值
    const int *c;//如果const放在*的左边。修饰的c所指向的内存空间不能被修改
    int * const d ;//如果const放在*的右边，表示const修饰d,d是指针变量，不能改变它的指向，与它所指向的内存空间没有任何关系
    d = 0xaa11;//不能改变
    const char * const e;//指针变量和所指向的内存空间都不能被修改
    system("pause");
}  
```
