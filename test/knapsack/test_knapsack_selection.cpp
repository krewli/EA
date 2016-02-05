/* 
 * File:   test_knapsack_selection
 * Author: krewli
 *
 * Created on Feb 5, 2016, 12:54:33 PM
 */

#include <gtest/gtest.h>

#include "knapsack.h"
#include "knapsack_utility.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackSelectionTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	    Knapsack get_knapsack( )
	    {
		try
		{
		    return read_knapsack("data/knapsack_data/ks_3_0");
		}
		catch ( std::runtime_error& e )
		{
		    std::cout << "Runtime error: " << e.what() << std::endl;
		}
	    }
	};

	TEST_F( KnapsackSelectionTestSuite, testExample )
	{
	    FAIL();
	}
    }
}

