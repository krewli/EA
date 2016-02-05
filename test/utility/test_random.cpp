/* 
 * File:   test_random
 * Author: krewli
 *
 * Created on Jan 30, 2016, 4:55:05 PM
 */

#include <gtest/gtest.h>

#include "random.h"

namespace util
{
    namespace test
    {

	class RandomTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	};

	TEST_F( RandomTestSuite, test_random_integer_generator )
	{
	    EXPECT_EQ(6, get_random_integer(0, 10, Seed(0)));
	    EXPECT_ANY_THROW(get_random_integer(5, 0));
	}
	
	TEST_F( RandomTestSuite, test_random_real_generator )
	{
	    EXPECT_FLOAT_EQ(0.59284461, get_random_real(0, 1, Seed(0)));
	}
	
	TEST_F(RandomTestSuite, test_exception_handling)
	{
	    EXPECT_THROW(get_random_real(0, -1), InvalidBoundError);
	    EXPECT_THROW(get_random_integer(10, 5), InvalidBoundError);
	}
    }
}



