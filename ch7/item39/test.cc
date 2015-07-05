#include <iostream>
#include <future>
#include <vector>

std::promise<void> p;
void reacting(int i)
{
    std::cout << i << ": Detected 0!" << std::endl;
}
void detecting(int threadNum)
{
    auto sf = p.get_future().share();
    std::vector<std::thread> threads;
    for(auto i = 0; i < threadNum; ++i)
        threads.emplace_back([i, sf]{
                sf.wait();
                reacting(i);
                });
    char x = 'a';
    while(x != '0')
        std::cin >> x;
    p.set_value();
    for(auto& t : threads)
        t.join();
}


int main()
{
    detecting(3);
}


