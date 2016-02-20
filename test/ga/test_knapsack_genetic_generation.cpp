/* 
 * File:   test_knapsack_genetic_generation
 * Author: krewli
 *
 * Created on Feb 5, 2016, 1:07:16 PM
 */

#include <gtest/gtest.h>

#include "knapsack_generation_alias.h"
#include "knapsack.h"
#include "knapsack_individual_alias.h"
#include "knapsack_mutation.h"
#include "knapsack_fitness.h"
#include "knapsack_utility.h"

using namespace knapsack;

namespace ga
{
    namespace test
    {

	class KnapsackGeneticGenerationTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }
	    using GeneticKnapsackGeneration = knapsack_generation;

	};

	TEST_F( KnapsackGeneticGenerationTestSuite, test_offspring )
	{
	    try
	    {
		Knapsack knapsack = read_knapsack("data/knapsack/ks_3_0");

		util::Seed seed { 0 };

		knapsack_individual id1 { 3 };
		knapsack_individual id2 { 3 };
		knapsack_individual id3 { 3 };

		knapsack_individual::chromosome_encoding chromosome1 { false, true, true };
		knapsack_individual::chromosome_encoding chromosome2 { true, false, false };
		knapsack_individual::chromosome_encoding chromosome3 { false, false, true };

		id1.set_chromosome(chromosome1);
		id2.set_chromosome(chromosome2);
		id3.set_chromosome(chromosome3);

		knapsack_generation_type generation { id1, id2, id3 };

		GeneticKnapsackGeneration genetic_generation { 3 };
		genetic_generation.set_generation(generation);
		genetic_generation.set_seed(seed);

		auto actual_result = genetic_generation.offspring(knapsack);

		knapsack_individual expected_offspring_1 { 3 };
		knapsack_individual expected_offspring_2 { 3 };
		knapsack_individual::chromosome_encoding chromosome4 { true, false, true };
		knapsack_individual::chromosome_encoding chromosome5 { false, false, false };
		expected_offspring_1.set_chromosome(chromosome4);
		expected_offspring_2.set_chromosome(chromosome5);

		EXPECT_EQ(expected_offspring_1.get_chromosome(), actual_result.at(0).get_chromosome());
		EXPECT_EQ(expected_offspring_2.get_chromosome(), actual_result.at(1).get_chromosome());
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}
    }
}

