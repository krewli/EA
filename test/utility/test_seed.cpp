/* 
 * File:   test_seed
 * Author: krewli
 *
 * Created on Jan 30, 2016, 2:39:18 PM
 */

#include <gtest/gtest.h>

#include "seed.h"

namespace util
{
    namespace test
    {

	class SeedTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( )
	    {
		// Setup ...
		s1.set_value(0);
		s2.set_value(0);
		s3.set_value(1);
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	    Seed s1 { -1 };
	    Seed s2 { -1 };
	    Seed s3 { -1 };
	};

	TEST_F( SeedTestSuite, test_getters )
	{
	    EXPECT_EQ(0, s1.get_value());
	}

	TEST_F( SeedTestSuite, test_setters )
	{
	    s1.set_value(1);
	    EXPECT_EQ(1, s1.get_value());
	}

	TEST_F( SeedTestSuite, test_comparison )
	{
	    EXPECT_EQ(s1, s2);
	    EXPECT_NE(s1, s3);
	}

	TEST_F( SeedTestSuite, test_addition )
	{
	    s1 += 1;
	    auto s4 = s1 + 1;
	    EXPECT_EQ(1, s1.get_value());
	    EXPECT_EQ(2, s4.get_value());
	}

	TEST_F( SeedTestSuite, test_no_seed_value )
	{
	    s1.set_value(-1);
	    EXPECT_EQ(s1, NO_SEED);
	    EXPECT_NE(s2, NO_SEED);
	}

    }
}


