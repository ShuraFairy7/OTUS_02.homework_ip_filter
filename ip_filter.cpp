#include "ip_filter.h"

ip_pool_vector filterAnyIpPool(const ip_pool_vector& ip_pool, const int& value)
{
    ip_pool_vector result_filtered_ip_pool;

    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(result_filtered_ip_pool),
        [&value](const auto ip)
        {
            return std::any_of(ip.begin(), ip.end(), 
                [&value](const int& compare_value)
                {
                    return compare_value == value;
                });
        }
    );
    return result_filtered_ip_pool;
}

