#include <iostream>

template<class... Ts>
void func(Ts... args)
{
    std::cout << "func() is called!" << std::endl;
}

int main()
{
//    func({1, 2, 3});

    auto il = {1, 2, 3};
    func(il);
}
