#include <iostream>
#include <typeinfo>

template<class T>
void func1(T param)
{

}

template<class T>
void func2(std::initializer_list<T> param)
{
    T a;
    std::cout << typeid(a).name() << std::endl;
}

int main()
{
    //func1({1, 2, 3});
    func2({1, 2, 3});
}
