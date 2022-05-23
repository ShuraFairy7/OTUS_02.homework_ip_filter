#pragma once

#include "types.h"
#include <stdexcept>

constexpr static const int NUMBER_SEGMENTS_OF_IP_ADDRESS{4};

string_vector split(const std::string& str, char d);
int_vector stringToInt(const std::vector<std::string>& ip, size_t count_line);
void printIpPool(const ip_pool_vector& ip_pool);
void reverseLexicographicalSortIpPool(ip_pool_vector& ip_pool);
