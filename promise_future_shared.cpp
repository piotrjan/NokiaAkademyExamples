#include <iostream>
#include <future>

int main()
{
    std::promise<std::string> MrBellsMicrophone;

    std::future<std::string> Speaker = MrBellsMicrophone.get_future();

    std::shared_future<std::string> MrWatsonsSpeaker = Speaker.share(); 

    MrBellsMicrophone.set_value("Mr. Watson – come here – I want to see you");

    std::cout << MrWatsonsSpeaker.get() << std::endl;

    // and what happens if I get the value again

    std::cout << MrWatsonsSpeaker.get() << std::endl;

    // Speaker no longer keeps the shared state

    try {
        std::cout << Speaker.get() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    return 0;
}