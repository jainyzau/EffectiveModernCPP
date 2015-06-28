#include <iostream>

void func(int a)
{
    std::cout << a << std::endl;
}

void func(char a) = delete;
void func(double a) = delete;
void func(bool a) = delete;

class MyClass
{
    public:
        MyClass() {};
        MyClass(const MyClass& rhs) = delete;
};

int main()
{
 //   func('a');
 //   func(1.0);
 //   func(true);
    func(3);

    MyClass mc0;
//    MyClass mc1(mc0); 
}
