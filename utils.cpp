#include "utils.h"

string_vector split(const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

int_vector stringToInt(const std::vector<std::string>& ip, size_t count_line)
{
    if (ip.size() != NUMBER_SEGMENTS_OF_IP_ADDRESS)
        throw std::logic_error("Number segments of IP address is not equal to " + 
            std::to_string(NUMBER_SEGMENTS_OF_IP_ADDRESS) + " : " + std::to_string(ip.size()) + "\n" +
        "Line number in file: " + std::to_string(count_line));

    std::vector<int> result;
    for (const auto& byte : ip)
    {
        if (byte.empty())
            throw std::logic_error("Empty byte string\nLine number in file: " + std::to_string(count_line));

        auto value = std::stoi(byte);
        if ((value > 0xFF) || (value < 0))
            throw std::logic_error("Byte of IP address is out of range 0...255 : " + std::to_string(value) + "\n" +
                "Line number in file: " + std::to_string(count_line));

        result.push_back(value);        
    }    

    return result;
}

void printIpPool(const ip_pool_vector& ip_pool)
{
    for (const auto& ip : ip_pool)
    {
        for (auto byte = ip.cbegin(); byte != ip.cend(); ++byte)
        {
            if (byte != ip.cbegin())
            {
                std::cout << ".";
            }
            std::cout << *byte;
        }
        std::cout << std::endl;
    }
}

void reverseLexicographicalSortIpPool(ip_pool_vector& ip_pool)
{
    std::sort(ip_pool.begin(), ip_pool.end(), std::greater<>());
}

