# c++中的命名空间

c++ 引入了命名空间的概念
```
#include <iostream>

using namespace std;

namespace namespaceB
{
    int a = 10;
    namespace namespaceC
    {
        struct teacher
        {
            int id;
            char name[64];
        };
    }

    namespace namespaceD
    {
        struct teacher
        {};
    }
}


int main() {
    cout << "Hello, World!" << endl;

    //using namespaceB::namespaceC::teacher;  第一种方法
//    using namespace namespaceB::namespaceC;  第二种方法
    using namespaceB::namespaceC::teacher;     //第三种方法
    teacher t;

    namespaceB::namespaceC::teacher t1;      //还可以直接这么写
    return 0;
}
```
