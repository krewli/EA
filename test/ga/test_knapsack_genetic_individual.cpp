/* 
 * File:   test_genetic_individual
 * Author: krewli
 *
 * Created on Feb 2, 2016, 10:14:24 PM
 */

#include <gtest/gtest.h>

#include <vector>

#include "genetic_individual.h"

#include "knapsack.h"
#include "knapsack_mutation.h"
#include "knapsack_fitness.h"
#include "knapsack_utility.h"

#include "seed.h"

namespace ga
{
    namespace test
    {

	class KnapsackGeneticIndividualTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( )
	    {
		// Setup ...
		knapsack_individual = new GeneticKnapsackIndividual(5);
	    }

	    void TearDown( )
	    {
		// Teardown ...
		delete knapsack_individual;
	    }

	    using GeneticKnapsackIndividual =
		    GeneticIndividual <
		    bool,
		    std::vector<bool>,
		    knapsack::Knapsack,
		    knapsack::KnapsackMutation,
		    knapsack::KnapsackFitness>;
	    using chromosome_type =
		    GeneticKnapsackIndividual::chromosome_encoding;

	    GeneticKnapsackIndividual* knapsack_individual;
	};

	TEST_F( KnapsackGeneticIndividualTestSuite, test_getters_functions )
	{
	    GeneticKnapsackIndividual::chromosome_encoding expected_chromosome { true, false, true, true, false };
	    knapsack_individual->set_chromosome(expected_chromosome);

	    EXPECT_EQ(expected_chromosome, knapsack_individual->get_chromosome());
	    EXPECT_EQ(5, knapsack_individual->get_size());
	}

	TEST_F( KnapsackGeneticIndividualTestSuite, test_setters_functions )
	{
	    GeneticKnapsackIndividual::chromosome_encoding expected_chromosome { true, false, true, true, false };
	    util::Seed expected_seed { 1 };

	    knapsack_individual->set_chromosome(expected_chromosome);
	    knapsack_individual->set_seed(util::Seed { 1 });


	    EXPECT_EQ(expected_chromosome, knapsack_individual->get_chromosome());
	    EXPECT_EQ(expected_seed, knapsack_individual->get_seed());
	}

	TEST_F( KnapsackGeneticIndividualTestSuite, test_mutation_policy )
	{
	    chromosome_type chromosome { true, false, true, true, false };
	    chromosome_type expected_result1 { true, false, false, true, true };
	    chromosome_type expected_result2 { false, true, false, false, true };
	    chromosome_type expected_result3 { true, false, true, true, false };

	    knapsack_individual->set_seed(util::Seed(0));

	    knapsack_individual->set_chromosome(chromosome);
	    knapsack_individual->mutate(0.5);
	    EXPECT_EQ(expected_result1, knapsack_individual->get_chromosome());

	    knapsack_individual->set_chromosome(chromosome);
	    knapsack_individual->mutate(1.0);
	    EXPECT_EQ(expected_result2, knapsack_individual->get_chromosome());

	    knapsack_individual->set_chromosome(chromosome);
	    knapsack_individual->mutate(0.0);
	    EXPECT_EQ(expected_result3, knapsack_individual->get_chromosome());
	}

	TEST_F( KnapsackGeneticIndividualTestSuite, test_fitness_policy )
	{
	    using namespace knapsack;
	    try
	    {
		Knapsack knapsack = read_knapsack("data/knapsack/ks_3_0");

		KnapsackFitness::chromosome_type chromosome1 { true, false, true, false, false };
		knapsack_individual->set_chromosome(chromosome1);
		EXPECT_EQ(80, knapsack_individual->fitness(knapsack));

		KnapsackFitness::chromosome_type chromosome2 { false, false, false, false, false };
		knapsack_individual->set_chromosome(chromosome2);
		EXPECT_EQ(0, knapsack_individual->fitness(knapsack));

		KnapsackFitness::chromosome_type chromosome3 { true, true, true, false, false };
		knapsack_individual->set_chromosome(chromosome3);
		EXPECT_EQ(128, knapsack_individual->fitness(knapsack));
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}
	
	TEST_F(KnapsackGeneticIndividualTestSuite, test_exception_handling )
	{
	    chromosome_type chromosome{true, false, true};
	    EXPECT_THROW(knapsack_individual->set_chromosome(chromosome), InvalidChromosomeSize);
	}
    }
}

