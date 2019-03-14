#include <iostream>
#include <chrono>
#include <future>
using namespace std::chrono_literals;

int addNumbers(int a, int b)
{
    std::cout << "Packaged task is thinking..." << std::endl;
    std::this_thread::sleep_for(1s);
    std::cout << "I know!" << std::endl;
    return a + b;
}

int main()
{
    
    std::packaged_task<int (int, int)> myOperation(addNumbers);
    
    std::future<int> futureWithResultOfAddition = myOperation.get_future();

    myOperation(1, 2);

    std::this_thread::sleep_for(500ms);

    std::cout << "Starting waiting for result.." << std::endl;

    std::cout << "The result is " << futureWithResultOfAddition.get() << std::endl;

    return 0;
}