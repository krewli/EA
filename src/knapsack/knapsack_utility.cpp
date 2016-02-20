/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "knapsack_utility.h"
#include "knapsack_item.h"
#include "knapsack_id.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

namespace knapsack
{

    Knapsack read_knapsack( const std::string& filename )
    {
	std::ifstream file { filename };

	if ( !file )
	{
	    throw std::runtime_error("Could not open file " + filename + ".\n");
	}

	unsigned capacity;
	unsigned number_of_items;

	file >> number_of_items >> capacity;

	Knapsack::data_type items;

	int value, weight;

	for ( unsigned i = 0; i < number_of_items; i++ )
	{
	    file >> value >> weight;
	    items.push_back(KnapsackItem { KnapsackID(i), value, weight });
	}

	file.close();

	return Knapsack { capacity, number_of_items, items };
    }

    knapsack_individual::chromosome_encoding generate_default_chromosome( unsigned size )
    {
	knapsack_individual::chromosome_encoding chromosome;

	for ( unsigned i = 0; i < size; ++i )
	{
	    chromosome.push_back(false);
	}

	return chromosome;
    }

    bool valid_chromosome( const knapsack_individual::chromosome_encoding& chromosome,
			   const Knapsack& knapsack )
    {
	double capacity = 0.0;

	for ( unsigned i = 0; i < chromosome.size(); ++i )
	{

	    if ( chromosome.at(i) )
	    {
		capacity += knapsack.get_weight_at(i);
	    }
	}

	return capacity <= knapsack.get_capacity();
    }

    knapsack_individual generate_random_individual( const Knapsack& knapsack,
						    const util::Seed& seed )
    {
	knapsack_individual result { knapsack.get_item_count() };

	knapsack_individual::chromosome_encoding chromosome = generate_default_chromosome(result.get_size());

	chromosome.at(0) = true;

	result.set_chromosome(chromosome);
	result.set_seed(seed);
	result.mutate(0.5);

	return result;
    }

    knapsack_generation generate_random_generation( unsigned size,
						    const Knapsack& knapsack,
						    const util::Seed& seed )
    {
	knapsack_generation result { size };

	knapsack_generation_type generation;

	util::Seed internal_seed { seed };

	for ( unsigned i = 0; i < size; ++i )
	{
	    generation.push_back(generate_random_individual(knapsack, internal_seed));
	    ++internal_seed;
	}

	result.set_generation(generation);

	return result;
    }
}
