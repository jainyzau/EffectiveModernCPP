#include <iostream>
#include <exception>

void func() noexcept
{
    throw std::runtime_error("should not throw");
}

int main()
{
    std::cout << "startting..." << std::endl;
    try
    {
        func();
    }
    catch(...)
    {
        std::cout << "should not reach here..." << std::endl;
    }
    std::cout << "stopping..." << std::endl;
}
