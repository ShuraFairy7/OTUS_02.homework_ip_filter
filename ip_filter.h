#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "types.h"

ip_pool_vector filterAnyIpPool(const ip_pool_vector& ip_pool, const int& value);

template<typename... Args>
ip_pool_vector filterIpPool(const ip_pool_vector& ip_pool, const Args & ... args) 
{
    ip_pool_vector result_filtered_ip_pool;
    std::vector<int> compare_values = { args... };

    std::copy_if(ip_pool.begin(), ip_pool.end(), std::back_inserter(result_filtered_ip_pool),
        [&compare_values](const auto & ip)
        {
            return std::equal(ip.begin(), ip.begin() + compare_values.size(), compare_values.begin());
        }
    );
    return result_filtered_ip_pool;
}


