#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class Point
{
    public:
        constexpr Point(int _x = 0, int _y = 0) noexcept : x(_x), y(_y) {}
        constexpr int get_x() const noexcept{ return x; }
        constexpr int get_y() const noexcept{ return y; }
        constexpr void set_x(int _x) noexcept{ x = _x;}
        constexpr void set_y(int _y) noexcept{ y = _y;}
        constexpr Point mid() const noexcept{ return Point(x/2, y/2); }
        constexpr Point reflection(const Point& p) const noexcept
        {
            Point result;
            result.set_x(-p.get_x());
            result.set_y(-p.get_y());
            return result;
        }
    private:
        int x;
        int y;
};

constexpr int array_size(int n) noexcept
{
    /*
    std::vector<int> lVec = {1, 2, 3, 4,  5, 6, 7, 8, 9, 0};
    for(const auto& i : lVec)
    {
        std::cout << i << std::endl;
    }
    */

    return 2 * n;
}

int main()
{
    std::array<int, array_size(3)> lArr = {1, 2, 3};
    std::for_each(std::begin(lArr), std::end(lArr), [](auto& i) {
            std::cout << i << std::endl;
            });

    constexpr Point lPoint(-2, -6);
    std::array<int, lPoint.reflection(lPoint).get_x() + 2> lArr2 = {1};
    std::for_each(std::begin(lArr2), std::end(lArr2), [](auto& i) {
            std::cout << i << std::endl;
            });

    Point lPoint2;
    lPoint2.set_x(3);
}
