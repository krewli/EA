/* 
 * File:   test_knapsack_fitness
 * Author: krewli
 *
 * Created on Jan 30, 2016, 5:40:52 PM
 */

#include <gtest/gtest.h>

#include "knapsack_fitness.h"
#include "knapsack_utility.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackFitnessTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	};

	TEST_F( KnapsackFitnessTestSuite, test_fitness )
	{
	    try
	    {
		Knapsack knapsack = read_knapsack("data/knapsack/ks_3_0");
		KnapsackFitness::chromosome_type chromosome1 { true, false, true };
		EXPECT_EQ(80, KnapsackFitness::fitness(chromosome1, knapsack));

		KnapsackFitness::chromosome_type chromosome2 { false, false, false };
		EXPECT_EQ(0, KnapsackFitness::fitness(chromosome2, knapsack));

		KnapsackFitness::chromosome_type chromosome3 { true, true, true };
		EXPECT_EQ(0, KnapsackFitness::fitness(chromosome3, knapsack));
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}
    }
}


