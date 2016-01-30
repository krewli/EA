/* 
 * File:   test_knapsack
 * Author: krewli
 *
 * Created on Jan 29, 2016, 9:24:29 PM
 */

#include <gtest/gtest.h>

#include "knapsack.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	};

	TEST_F( KnapsackTestSuite, test_access_functions )
	{
	    unsigned expected_capacity = 100;
	    unsigned expected_item_count = 10;
	    Knapsack::data_type expected_data { };

	    unsigned capacity = 100;
	    unsigned item_count = 10;
	    Knapsack::data_type data { };
	    Knapsack knapsack { capacity, item_count, data };

	    EXPECT_EQ(expected_capacity, knapsack.get_capacity());
	    EXPECT_EQ(expected_item_count, knapsack.get_item_count());
	    EXPECT_EQ(expected_data, knapsack.get_data());
	}
    }
}


