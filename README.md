# My Awesome Book

c/c++
c语言知识积累笔记
This file file serves as your book's preface, a great place to describe your book's content and ideas.

1.memcpy结构体(上面结构体那一章)和数组写法。

2.enum所占内存的大小。
c语言默认的每个枚举是int的大小。
c++可以指定：
```
enum test : unit8_t {
    test1 = 0x01
};
```