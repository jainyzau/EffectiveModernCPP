#include <iostream>
#include <memory>

class Base
{
    public:
        virtual void func(int a)
        {
            std::cout << "Base::func: " << a << std::endl;
        }

        virtual void func2(int a) final
        {
            std::cout << "Base::func2: " << a << std::endl;
        }
};

class Derived : public Base
{
    public:
        virtual void func(int a) override
        {
            std::cout << "Derived::func: " << a << std::endl;
        }

        // error no matter keywords virtual and override are given or not.
        /*virtual*/ void func2(int a) //override
        {
            std::cout << "Derived::func2: " << a << std::endl;
        }
};

int main()
{
    std::unique_ptr<Base> pBase =
            std::make_unique<Derived>();
    pBase->func(3);
    pBase->func2(6);
}
