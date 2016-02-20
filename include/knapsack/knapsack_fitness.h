/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_fitness.h
 * Author: krewli
 *
 * Created on January 30, 2016, 5:35 PM
 */

#ifndef KNAPSACK_FITNESS_H
#define KNAPSACK_FITNESS_H

#include "knapsack.h"
#include "genetic_fitness.h"

namespace knapsack
{

    struct KnapsackFitness
    : public ga::Fitness<std::vector<bool>, Knapsack>
    {

	static double fitness(const chromosome_type& chromosome,
			const problem_type& problem)
	{
	    double fitness_value = 0.0;

	    for (unsigned i = 0; i < chromosome.size(); ++i)
	    {
		if (chromosome.at(i))
		{
		    fitness_value += problem.get_value_at(i);
		}
	    }

	    if (!within_capacity(chromosome, problem))
	    {
		fitness_value = 0;
	    }

	    return fitness_value;
	}

	static bool within_capacity(const chromosome_type& chromosome,
				const problem_type& problem)
	{
	    double capacity = 0.0;

	    for (unsigned i = 0; i < chromosome.size(); ++i)
	    {
		if (chromosome.at(i))
		{
		    capacity += problem.get_weight_at(i);
		}
	    }

	    return capacity < problem.get_capacity();
	}
    };
}

#endif /* KNAPSACK_FITNESS_H */

