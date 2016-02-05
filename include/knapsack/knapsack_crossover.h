/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_crossover.h
 * Author: krewli
 *
 * Created on February 2, 2016, 11:58 PM
 */

#ifndef KNAPSACK_CROSSOVER_H
#define KNAPSACK_CROSSOVER_H

#include "knapsack_individual_alias.h"

#include "genetic_crossover.h"

#include "random.h"
#include "seed.h"

#include <iostream>

namespace knapsack
{

    struct KnapsackRandomPoint
    :
    public ga::Crossover<knapsack_individual,
    std::vector<knapsack_individual>>
    {

	static return_type offspring(const individual_type& parent1,
				const individual_type& parent2,
				const util::Seed & seed)
	{
	    assert(parent1.get_size() == parent2.get_size());

	    int cross_point = get_cross_point(parent1.get_size(), seed);

	    return_type offspring;

	    offspring.push_back(child(parent1, parent2, cross_point));
	    offspring.push_back(child(parent2, parent1, cross_point));

	    return offspring;
	}

	static int get_cross_point(int upper_bound, const util::Seed & seed)
	{
	    return util::get_random_integer(1, upper_bound - 2, seed);;
	}

	static individual_type child(const individual_type& parent1,
				const individual_type& parent2,
				int cross_point)
	{
	    using chromosome_type = individual_type::chromosome_encoding;

	    individual_type child{ parent1.get_size() };
	    chromosome_type new_chromosome;

	    chromosome_type parent1_chromosome = parent1.get_chromosome();
	    chromosome_type parent2_chromosome = parent2.get_chromosome();

	    for (unsigned i = 0; i < parent1.get_size(); ++i) {
		if (i < cross_point) {
		    new_chromosome.push_back(parent1_chromosome.at(i));
		}
		else {
		    new_chromosome.push_back(parent2_chromosome.at(i));
		}
	    }

	    child.set_chromosome(new_chromosome);
	    return child;
	}
    };
}

#endif /* KNAPSACK_CROSSOVER_H */

