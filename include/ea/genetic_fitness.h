/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_fitness.h
 * Author: krewli
 *
 * Created on January 30, 2016, 3:55 PM
 */

#ifndef GENETIC_FITNESS_H
#define GENETIC_FITNESS_H

#include "knapsack.h"

namespace ea
{

    template<typename chromosome, typename problem>
    struct Fitness
    {
	using chromosome_type = chromosome;
	using problem_type = problem;

	virtual static double fitness(const chromosome_type& chromosome,
				const problem_type& problem) = 0;
    };

    struct KnapsackFitness : public Fitness<std::vector<bool>, knapsack::Knapsack>
    {

	static double fitness(const chromosome_type& chromosome,
			const problem_type& problem) override
	{
	    double fitness_value = 0.0;

	    for (unsigned i = 0; i < chromosome.size(); ++i) {
		if (chromosome.at(i)) {
		    fitness_value += problem.get_value_at(i);
		}
	    }

	    return fitness_value;
	}
    };
}

#endif /* GENETIC_FITNESS_H */

