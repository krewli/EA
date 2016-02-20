/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_generation.h
 * Author: krewli
 *
 * Created on February 2, 2016, 11:10 PM
 */

#ifndef GENETIC_GENERATION_H
#define GENETIC_GENERATION_H

#include <iostream>

#include "genetic_crossover.h"
#include "genetic_selection.h"

#include "seed.h"

namespace ga
{

    template<typename individual_t,
    typename generation_t,
    typename problem_t,
    class selection_p,
    class crossover_p>
    class GeneticGeneration
    {
    public:
	using individual_type = individual_t;
	using generation_type = generation_t;
	using problem_type = problem_t;
	using selection_policy = selection_p;
	using crossover_policy = crossover_p;
	using offspring_type = typename crossover_policy::return_type;

	GeneticGeneration(unsigned size)
	: size_{ size }, seed_{ util::NO_SEED }
	{
	}

	GeneticGeneration(const GeneticGeneration&) = default;
	GeneticGeneration(GeneticGeneration&&) = default;

	~GeneticGeneration() = default;

	unsigned get_size() const
	{
	    return size_;
	}

	offspring_type offspring(const problem_type& problem) const
	{
	    util::Seed internal_seed{ seed_ };
	    ++internal_seed;

	    individual_type parent1 = selection_policy::select(generation_,
							    problem,
							    seed_);
	    individual_type parent2 = selection_policy::select(generation_,
							    problem,
							    internal_seed);

	    while (parent1 == parent2)
	    {
		++internal_seed;
		parent2 = selection_policy::select(generation_,
						problem,
						internal_seed);
	    };

	    return crossover_policy::offspring(parent1, parent2, seed_);
	}

	generation_type get_generation() const
	{
	    return generation_;
	}

	util::Seed get_seed() const
	{
	    return seed_;
	}

	void set_generation(const generation_type& generation)
	{	    
	    if (generation.size() != size_)
	    {
		throw InvalidGenerationSize{ static_cast<int> (generation.size()),
					static_cast<int> (size_) };
	    }

	    generation_ = generation;
	}

	void set_seed(const util::Seed& seed)
	{
	    seed_ = seed;
	}

    protected:

    private:
	const unsigned size_;
	generation_type generation_;
	util::Seed seed_;

	GeneticGeneration& operator=(const GeneticGeneration&) = delete;
	GeneticGeneration& operator=(GeneticGeneration&&) = delete;
    };
}

#endif /* GENETIC_GENERATION_H */

