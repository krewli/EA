/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_selection.h
 * Author: krewli
 *
 * Created on February 2, 2016, 11:48 PM
 */

#ifndef KNAPSACK_SELECTION_H
#define KNAPSACK_SELECTION_H

#include <iostream>

#include "knapsack.h"
#include "knapsack_individual_alias.h"

#include "genetic_selection.h"

#include "random.h"

namespace knapsack
{

    struct KnapsackRouletteWheel
    :
    public ga::Selection<
    knapsack_individual,
    knapsack_generation_type,
    Knapsack>
    {
	using individual_type = knapsack_individual;
	using generation_type = knapsack_generation_type;
	using problem_type = Knapsack;

	static individual_type select(const generation_type& generation,
				const problem_type& problem,
				const util::Seed& seed)
	{

	    int lower_bound{ 0 };
	    int upper_bound{ get_total_fitness(generation, problem) };
	    int random_number = util::get_random_integer(lower_bound, upper_bound, seed);

	    // std::cout << upper_bound << " " << random_number << std::endl;
	    
	    unsigned index = 0;
	    int current_fitness_sum = generation.at(index).fitness(problem);
	    
	    while (current_fitness_sum < random_number)
	    {
		++index;
		current_fitness_sum += generation.at(index).fitness(problem);
	    }

	    return generation.at(index);
	}

	static int get_total_fitness(const generation_type& generation,
				const problem_type & problem)
	{
	    int fitness_sum = 0;
	    std::for_each(generation.cbegin(), generation.cend(),
		    [&](const individual_type & indiv)
		    {
			fitness_sum += indiv.fitness(problem);
		    });
	    return fitness_sum;
	}
    };
}

#endif /* KNAPSACK_SELECTION_H */

