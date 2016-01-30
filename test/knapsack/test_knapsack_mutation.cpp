/* 
 * File:   test_knapsack_mutation
 * Author: krewli
 *
 * Created on Jan 30, 2016, 5:39:46 PM
 */

#include <gtest/gtest.h>

#include "knapsack_mutation.h"

namespace knapsack
{
    namespace test
    {

	class KnapsackMutationTestSuite : public testing::Test
	{
	  protected:

	    void SetUp( ) {
		// Setup ...
	    }

	    void TearDown( ) {
		// Teardown ...
	    }

	};

	TEST_F( KnapsackMutationTestSuite, test_mutation_with_half_probability )
	{
	    KnapsackMutation::chromosome_type chromosome{true, false, true, true, false};
	    KnapsackMutation::chromosome_type expected_result{true, false, false, true, true};
	    
	    EXPECT_EQ(expected_result, KnapsackMutation::mutate(chromosome, 0.5, util::Seed(0)));
	}
	
	TEST_F( KnapsackMutationTestSuite, test_mutation_with_full_probability )
	{
	    KnapsackMutation::chromosome_type chromosome{true, false, true, true, false};
	    KnapsackMutation::chromosome_type expected_result{false, true, false, false, true};
	    
	    EXPECT_EQ(expected_result, KnapsackMutation::mutate(chromosome, 1));
	}
	
	TEST_F( KnapsackMutationTestSuite, test_mutation_with_zero_probability )
	{
	    KnapsackMutation::chromosome_type chromosome{true, false, true, true, false};
	    KnapsackMutation::chromosome_type expected_result{true, false, true, true, false};
	    
	    EXPECT_EQ(expected_result, KnapsackMutation::mutate(chromosome, 0));
	}
    }
}


