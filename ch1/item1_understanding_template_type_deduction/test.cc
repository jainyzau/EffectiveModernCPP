#include <iostream>
#include <array>

using std::cout;
using std::endl;

template<class T, size_t N>
constexpr size_t array_size(T (&param)[N]) noexcept
{
    return N;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << array_size(arr) << std::endl;
    std::array<int, array_size(arr)> new_arr;
    std::cout << new_arr.size() << std::endl;
}
