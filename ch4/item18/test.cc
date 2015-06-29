#include <memory>
#include <iostream>

class MyClass
{

};

int main()
{
    auto DeleteMyClass = [](MyClass* p){
        std::cout << "delete object of MyClass" << std::endl;
        delete p;
    };
    std::unique_ptr<MyClass, decltype(DeleteMyClass)> pMyClass(new MyClass, DeleteMyClass);
}
