#include <iostream>
#include <chrono>
#include <future>

int addNumbers(int a, int b)
{
    std::cout << "Thinking..." << std::endl;
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    std::cout << "I know!" << std::endl;
    return a + b;
}

int main()
{
    // default policy std::launch::async | std::launch::deferred which lets to decide which policy will be used
    std::future<int> futureWithResultOfAddition = std::async(addNumbers, 1, 2);
    std::cout << "Starting waiting for result.." << std::endl;

    std::cout << "The result is " << futureWithResultOfAddition.get() << std::endl;

    return 0;
}