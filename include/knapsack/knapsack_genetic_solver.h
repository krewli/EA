/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_genetic_solver.h
 * Author: krewli
 *
 * Created on February 20, 2016, 6:07 PM
 */

#ifndef KNAPSACK_GENETIC_SOLVER_H
#define KNAPSACK_GENETIC_SOLVER_H

#include "knapsack_generation_alias.h"
#include "knapsack_utility.h"

namespace knapsack
{

    knapsack_generation knapsack_genetic_solve(unsigned generation_size,
					       unsigned num_of_generations,
					       double mutation_probability,
					       const Knapsack& knapsack)
    {
	int generation_counter{ 0 };

	knapsack_generation current_generation{ generate_random_generation(generation_size, knapsack) };
	knapsack_generation_type children;

	knapsack_generation_type best_child_per_generation;

	knapsack_individual best_individual_in_current_generation{knapsack.get_item_count()};

	while (generation_counter < num_of_generations)
	{
	    while (children.size() != current_generation.get_size())
	    {
		auto offsprings = current_generation.offspring(knapsack);

		children.push_back(offsprings.at(0));
		children.push_back(offsprings.at(1));
	    }

	    best_individual_in_current_generation.set_chromosome(generate_default_chromosome(knapsack.get_item_count()));

	    for (auto child : children)
	    {
		child.mutate(mutation_probability);

		if (child.fitness(knapsack) > best_individual_in_current_generation.fitness(knapsack))
		{
		    best_individual_in_current_generation = child;
		}
	    }

	    best_child_per_generation.push_back(best_individual_in_current_generation);

	    current_generation.set_generation(children);
	    children.clear();
	    
	    ++generation_counter;
	}

	knapsack_generation result{ num_of_generations };
	result.set_generation(best_child_per_generation);
	return result;
    }
}

#endif /* KNAPSACK_GENETIC_SOLVER_H */

