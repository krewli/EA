/* 
 * File:   test_knapsack_utility
 * Author: krewli
 *
 * Created on Jan 29, 2016, 9:26:25 PM
 */

#include <gtest/gtest.h>

#include "knapsack_item.h"
#include "knapsack_utility.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackUtilityTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	};

	TEST_F( KnapsackUtilityTestSuite, test_read_knapsack )
	{
	    try
	    {
		std::string filename { "data/knapsack/ks_3_0" };
		Knapsack actual_knapsack = read_knapsack(filename);

		Knapsack::data_type expected_data {
		    KnapsackItem(KnapsackID(0), 45, 5),
		    KnapsackItem(KnapsackID(1), 48, 8),
		    KnapsackItem(KnapsackID(2), 35, 3)
		};
		Knapsack expected_knapsack { 10, 3, expected_data };

		EXPECT_EQ(expected_knapsack, actual_knapsack);
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}

	TEST_F( KnapsackUtilityTestSuite, test_exception_throwing_when_reading_from_file_that_does_not_exist )
	{
	    EXPECT_THROW(read_knapsack("ks_3_0"), std::runtime_error);
	}
    }
}



