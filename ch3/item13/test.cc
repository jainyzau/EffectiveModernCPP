#include <iostream>
#include <vector>
#include <typeinfo>

int main()
{
    std::vector<int> lVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for(auto citr = lVec.cbegin(); citr != lVec.cend(); ++citr)
    {
        std::cout << *citr << std::endl;
    }
    std::cout << typeid(decltype(lVec.cbegin())).name() << std::endl;
    std::vector<int>::const_iterator citr2 = lVec.begin();
    std::cout << typeid(decltype(citr2)).name() << std::endl;
}

