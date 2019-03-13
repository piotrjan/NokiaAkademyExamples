#include <iostream>
#include <future>

int main()
{
    std::promise<std::string> MrBellsMicrophone;

    std::future<std::string> MrWatsonsSpeaker = MrBellsMicrophone.get_future();

    MrBellsMicrophone.set_value("Mr. Watson – come here – I want to see you");

    std::cout << MrWatsonsSpeaker.get() << std::endl;

    // and what happens if I get the value again

    try {
        std::cout << MrWatsonsSpeaker.get() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }

    return 0;
}