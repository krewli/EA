/* 
 * File:   test_knapsack_item
 * Author: krewli
 *
 * Created on Jan 29, 2016, 9:25:35 PM
 */

#include <gtest/gtest.h>

#include "knapsack_item.h"

namespace Knapsack
{
    namespace Test
    {

	class KnapsackItemTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	    KnapsackItem item1 { KnapsackID(0), 200, 100 };
	    KnapsackItem item2 { KnapsackID(0), 200, 100 };
	    KnapsackItem item3 { KnapsackID(1), 200, 100 };
	};

	TEST_F( KnapsackItemTestSuite, test_access_functions )
	{
	    EXPECT_EQ(200, item1.get_value());
	    EXPECT_EQ(100, item1.get_weight());
	}

	TEST_F( KnapsackItemTestSuite, test_comparison_operators )
	{
	    EXPECT_EQ(item1, item1);
	    EXPECT_NE(item1, item3);
	}
    }
}


