#include <iostream>
#include <chrono>
#include <future>
using namespace std::chrono_literals;

int addNumbers(int a, int b)
{
    std::cout << "Thinking..." << std::endl;
    std::this_thread::sleep_for(1s);
    throw std::exception();
    std::cout << "I know!" << std::endl;
    return a + b;
}

int main()
{
    std::future<int> futureWithResultOfAddition = std::async(std::launch::async, addNumbers, 1, 2);

    std::this_thread::sleep_for(500ms);

    std::cout << "Starting waiting for result.." << std::endl;

    try
    {
        std::cout << "The result is " << futureWithResultOfAddition.get() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Something unexpected happened :(" << std::endl;
    }

    return 0;
}