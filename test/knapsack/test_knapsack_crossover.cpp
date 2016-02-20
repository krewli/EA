/* 
 * File:   test_knapsack_crossover
 * Author: krewli
 *
 * Created on Feb 5, 2016, 12:55:04 PM
 */

#include <gtest/gtest.h>

#include "knapsack_crossover.h"
#include "knapsack_individual_alias.h"

#include "seed.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackCrossoverTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }
	};

	TEST_F( KnapsackCrossoverTestSuite, test_creating_offspring )
	{
	    unsigned size = 3;
	    knapsack_individual parent1 { size };
	    knapsack_individual parent2 { size };
	    knapsack_individual::chromosome_encoding chromosome1 { true, false, false };
	    knapsack_individual::chromosome_encoding chromosome2 { false, true, true };
	    parent1.set_chromosome(chromosome1);
	    parent2.set_chromosome(chromosome2);
	    util::Seed seed { 0 };

	    auto actual_result = KnapsackRandomPoint::offspring(parent1, parent2, seed);

	    knapsack_individual expected_offspring_1 { size };
	    knapsack_individual expected_offspring_2 { size };
	    knapsack_individual::chromosome_encoding chromosome3 { true, true, true };
	    knapsack_individual::chromosome_encoding chromosome4 { false, false, false };
	    expected_offspring_1.set_chromosome(chromosome3);
	    expected_offspring_2.set_chromosome(chromosome4);

	    EXPECT_EQ(expected_offspring_1.get_chromosome(), actual_result.at(0).get_chromosome());
	    EXPECT_EQ(expected_offspring_2.get_chromosome(), actual_result.at(1).get_chromosome());
	}

	TEST_F( KnapsackCrossoverTestSuite, test_creating_offspring_with_larger_size )
	{
	    unsigned size = 5;
	    knapsack_individual parent1 { size };
	    knapsack_individual parent2 { size };
	    knapsack_individual::chromosome_encoding chromosome1 { true, false, false, true, true };
	    knapsack_individual::chromosome_encoding chromosome2 { false, true, true, false, false };
	    parent1.set_chromosome(chromosome1);
	    parent2.set_chromosome(chromosome2);
	    util::Seed seed { 0 };

	    auto actual_result = KnapsackRandomPoint::offspring(parent1, parent2, seed);

	    knapsack_individual expected_offspring_1 { size };
	    knapsack_individual expected_offspring_2 { size };
	    knapsack_individual::chromosome_encoding chromosome3 { true, false, true, false, false };
	    knapsack_individual::chromosome_encoding chromosome4 { false, true, false, true, true };
	    expected_offspring_1.set_chromosome(chromosome3);
	    expected_offspring_2.set_chromosome(chromosome4);

	    EXPECT_EQ(expected_offspring_1.get_chromosome(), actual_result.at(0).get_chromosome());
	    EXPECT_EQ(expected_offspring_2.get_chromosome(), actual_result.at(1).get_chromosome());
	}
    }
}

