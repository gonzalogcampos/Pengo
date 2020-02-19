#include <Console.h>
#include <sstream>

const unsigned int MIN_PRIORITY = 3;


void console(std::string text, unsigned int priority)
{
    if(priority<=MIN_PRIORITY)
        std::cout<<text;
}

std::string str(float f)
{
    std::ostringstream ss;
    ss << f;
    return ss.str();
}