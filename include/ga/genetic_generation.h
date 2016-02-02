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

#include "seed.h"

namespace ga
{

    template<typename individual_t,
    typename generation_t,
    class selection_p,
    class crossover_p>
    class GeneticGeneration
    {
    public:
	using individual_type = individual_t;
	using generation_type = generation_t;
	using selection_policy = selection_p;
	using crossover_policy = crossover_p;

	GeneticGeneration(unsigned size)
	: size_{ size }, seed_{ util::NO_SEED }
	{
	}

	GeneticGeneration(unsigned size, const generation_type& generation)
	: size_{ size }, generation_{ generation }, seed_{ util::NO_SEED }
	{
	}

	~GeneticGeneration() = default;

	unsigned get_size() const
	{
	    return size_;
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
	    if(generation.size() != size_)
	    {
		throw InvalidGenerationSize{generation.size(), size_};
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

	GeneticGeneration(const GeneticGeneration&) = delete;
	GeneticGeneration(GeneticGeneration&&) = delete;

	GeneticGeneration& operator=(const GeneticGeneration&) = delete;
	GeneticGeneration& operator=(GeneticGeneration&&) = delete;
    };
}

#endif /* GENETIC_GENERATION_H */

