#include <iostream>

class Person
{
    friend std::ostream &operator<<(std::ostream &out, Person &p);

private:
    char *_name;
    int _num;
public:
    Person(const char * name, int num){
        this->_name = new char(strlen(name) + 1);
        strcpy(this->_name, name);
        this->_num = num;
    }
    ~Person(){
        if(this->_name != nullptr) {
            std::cout << "析构" << std::endl;
            delete _name;
            _name = nullptr;
        }
    }
    void printPerson(){
        std::cout << this->_name << "," << this->_num << std::endl;
    }
};

void test()
{
    Person p("lucy", 18);
    p.printPerson(); //这里是封装了一个函数来打印，那如果我们是需要类似std::cout << p << std::endl;这样的打印是不是更符合人们的使用习惯,所以就需要重载操作符
}

//重载操作符
//由我们的需求可知，我们是需要重载<<，这是一个二元运算符，两个参数，做参数是cout(ostream),右参数是person的对象
//又因为我们需要打印的是p的私有变量，所以要使用friend
std::ostream & operator<<(std::ostream &out, Person &p) {
    out << p._name << "," << p._num;
    return out;
}

void test1()
{
    Person p("lucy", 19);
    operator<<(std::cout, p);  //调用方式，你看它就像是一个函数调用方式
    //对这个调用方式进行优化，去掉operator,第一个参数放在运算符左边，第二个参数放在运算符的右边
    std::cout << p ;  //调用方式
}

//但是我们还想让其支持连等，比如这样写：std::cout << p << std::endl;
void test2()
{
    Person p("lucy", 10);
    //我们分开来看：std::cout << p这个是支持的，再继续追加就不支持了，所以如果让 std::cout << p 这个继续返回的是一个std::count的话，是不是就可以支持？
    //所以可以让其返回一个count的引用，改返回值为：std::ostream &
    // std::cout << p << std::endl;
    std::cout << p << "...test..." << std::endl;
}

int main()
{
    test2();
    return 0;
}