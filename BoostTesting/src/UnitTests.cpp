#define BOOST_TEST_MODULE My first test module
#include "../../../boost/boost_1_79_0/boost/test/included/unit_test.hpp"
BOOST_AUTO_TEST_CASE(first_test_function)
{
	int a = 42;
	BOOST_TEST(a > 0);
}