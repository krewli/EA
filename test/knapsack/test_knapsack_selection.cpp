/* 
 * File:   test_knapsack_selection
 * Author: krewli
 *
 * Created on Feb 5, 2016, 12:54:33 PM
 */

#include <gtest/gtest.h>

#include "knapsack.h"
#include "knapsack_utility.h"
#include "knapsack_individual_alias.h"
#include "knapsack_generation_alias.h"
#include "knapsack_selection.h"

#include "seed.h"

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
	};

	TEST_F( KnapsackSelectionTestSuite, test_selection )
	{
	    try
	    {
		Knapsack knapsack = read_knapsack("data/knapsack/ks_3_0");

		util::Seed seed { 0 };

		knapsack_individual id1 { 3 };
		knapsack_individual id2 { 3 };
		knapsack_individual id3 { 3 };

		knapsack_individual::chromosome_encoding chromosome1 { true, false, false };
		knapsack_individual::chromosome_encoding chromosome2 { false, true, false };
		knapsack_individual::chromosome_encoding chromosome3 { false, false, true };

		id1.set_chromosome(chromosome1);
		id2.set_chromosome(chromosome2);
		id3.set_chromosome(chromosome3);

		knapsack_generation_type generation { id1, id2, id3 };

		knapsack_individual actual_result = KnapsackRouletteWheel::select(generation, knapsack, seed);

		EXPECT_EQ(id2, actual_result);
		EXPECT_NE(id1, actual_result);
		EXPECT_NE(id3, actual_result);
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}
    }
}

