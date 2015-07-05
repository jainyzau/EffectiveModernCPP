#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std::chrono_literals;

std::atomic<int> gCount(0);

void func(int id)
{
    int x = 0;
    while(gCount.load() < 100)
    {
        x = gCount.load();
        ++gCount;
        std::cout << id << ": " << x << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread t1([]{func(1);});
    std::thread t2([]{func(2);});
    std::thread t3([]{func(3);});
    t1.join();
    t2.join();
    t3.join();
}
