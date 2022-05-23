#define BOOST_TEST_MODULE test_version

#include "utils.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

// Case 1: ("",  '.') -> [""]
BOOST_AUTO_TEST_CASE(test_case_1) 
{
	auto str_vec = split("", '.');
	BOOST_TEST_MESSAGE("str_vec[0]: " << str_vec.at(0));
	BOOST_CHECK((str_vec.size() == 1) && (str_vec.at(0) == ""));
}

// Case 2: ("11", '.') -> ["11"]
BOOST_AUTO_TEST_CASE(test_case_2) 
{
	auto str_vec = split("11", '.');
	BOOST_TEST_MESSAGE("str_vec[0]: " << str_vec.at(0));
	BOOST_CHECK((str_vec.size() == 1) && (str_vec.at(0) == "11"));
}

// Case 3: ("..", '.') -> ["", "", ""]
BOOST_AUTO_TEST_CASE(test_case_3) 
{
	auto str_vec = split("..", '.');
	BOOST_CHECK((str_vec.size() == 3) && (str_vec.at(0) == "")
		&& (str_vec.at(1) == "") && (str_vec.at(2) == ""));
}

// Case 4: ("11.", '.') -> ["11", ""]
BOOST_AUTO_TEST_CASE(test_case_4) 
{
	auto str_vec = split("11.", '.');
	BOOST_CHECK((str_vec.size() == 2) && (str_vec.at(0) == "11") && (str_vec.at(1) == ""));
}

// Case 5: (".11", '.') -> ["", "11"]
BOOST_AUTO_TEST_CASE(test_case_5) 
{
	auto str_vec = split(".11", '.');
	BOOST_CHECK((str_vec.size() == 2) && (str_vec.at(0) == "") && (str_vec.at(1) == "11"));
}

// Case 6: ("11.22", '.') -> ["11", "22"]
BOOST_AUTO_TEST_CASE(test_case_6) 
{
	auto str_vec = split("11.22", '.');
	BOOST_CHECK((str_vec.size() == 2) && (str_vec.at(0) == "11") && (str_vec.at(1) == "22"));
}

BOOST_AUTO_TEST_SUITE_END()
