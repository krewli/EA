/* 
 * File:   test_knapsack_id
 * Author: krewli
 *
 * Created on Jan 29, 2016, 9:25:01 PM
 */

#include <gtest/gtest.h>

#include "knapsack_id.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackIDTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	    KnapsackID id1 { 0 };
	    KnapsackID id2 { 0 };
	    KnapsackID id3 { 1 };
	};

	TEST_F( KnapsackIDTestSuite, test_comparison_operators )
	{
	    EXPECT_EQ(id1, id2);
	    EXPECT_NE(id1, id3);
	}
    }
}


