#include <iostream>
#include <memory>

class MyClass : public std::enable_shared_from_this<MyClass>
{
    public:
        ~MyClass() 
        {
            std::cout << __func__ << std::endl;
        }

};

int main()
{
    std::shared_ptr<MyClass> pMyClass(new MyClass);
    std::shared_ptr<MyClass> spMyClass(pMyClass->shared_from_this());
    if(pMyClass == spMyClass)
        std::cout << "shared_ptrs are equal" << std::endl;

}
