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
	    EXPECT_THROW(read_knapsack("this_file_does_not_exist"), std::runtime_error);
	}

	TEST_F( KnapsackUtilityTestSuite, test_generate_random_individual )
	{
	    try
	    {
		std::string filename { "data/knapsack/ks_3_0" };
		Knapsack knapsack = read_knapsack(filename);

		util::Seed seed { 0 };

		knapsack_individual actual_result { generate_random_individual(knapsack, seed) };

		knapsack_individual expected_result { knapsack.get_item_count() };
		knapsack_individual::chromosome_encoding chromosome { false, false, true };
		expected_result.set_chromosome(chromosome);

		EXPECT_EQ(expected_result.get_chromosome(), actual_result.get_chromosome());
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}

	TEST_F( KnapsackUtilityTestSuite, test_generate_random_generation )
	{
	    try
	    {
		std::string filename { "data/knapsack/ks_3_0" };
		Knapsack knapsack = read_knapsack(filename);

		util::Seed seed { 0 };

		knapsack_generation actual_result { generate_random_generation(3, knapsack, seed) };

		knapsack_individual id1 { knapsack.get_item_count() };
		knapsack_individual id2 { knapsack.get_item_count() };
		knapsack_individual id3 { knapsack.get_item_count() };

		knapsack_individual::chromosome_encoding chromosome1 { false, false, true };
		knapsack_individual::chromosome_encoding chromosome2 { false, true, false };
		knapsack_individual::chromosome_encoding chromosome3 { true, true, true };

		id1.set_chromosome(chromosome1);
		id2.set_chromosome(chromosome2);
		id3.set_chromosome(chromosome3);

		knapsack_generation_type expected_result { id1, id2, id3 };

		EXPECT_EQ(expected_result.at(0).get_chromosome(), 
			 actual_result.get_generation().at(0).get_chromosome());
		EXPECT_EQ(expected_result.at(1).get_chromosome(), 
			 actual_result.get_generation().at(1).get_chromosome());
		EXPECT_EQ(expected_result.at(2).get_chromosome(), 
			 actual_result.get_generation().at(2).get_chromosome());
	    }
	    catch ( std::runtime_error& e )
	    {
		std::cout << "Runtime error: " << e.what() << std::endl;
		FAIL();
	    }
	}
    }
}



