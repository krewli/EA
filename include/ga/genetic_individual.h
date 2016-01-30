/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_individual.h
 * Author: krewli
 *
 * Created on January 30, 2016, 2:14 PM
 */

#ifndef GENETIC_INDIVIDUAL_H
#define GENETIC_INDIVIDUAL_H

#include "seed.h"

namespace GA
{

    template<
    unsigned size,
    typename genotype,
    typename chromosome,
    typename problem,
    class mutation,
    class fitness
    >
    class GeneticIndividual
    {
    public:
	using genotype_encoding = genotype;
	using chromosome_encoding = chromosome<genotype>;
	using problem_type = problem;
	using mutation_policy = mutation;
	using fitness_policy = fitness;

	GeneticIndividual()
	: size_{ size }, chromosome_{ chromosome_encoding(size) }, seed_{ util::NO_SEED }
	{
	}

	GeneticIndividual(const GeneticIndividual&) = default;
	GeneticIndividual(GeneticIndividual&&) = default;

	~GeneticIndividual() = default;

	void mutate(double probability)
	{
	    chromosome_ = mutation_policy::mutate(chromosome_,
					    probability,
					    seed_);
	}

	double fitness(const problem_type& problem) const
	{
	    return fitness_policy::fitness(chromosome_, problem);
	}

	unsigned get_size() const
	{
	    return size_;
	}

	chromosome_encoding get_chromosome() const
	{
	    return chromosome_;
	}

	void set_chromosome(const chromosome_encoding& chromosome)
	{
	    chromosome_ = chromosome;
	}

	void set_seed(const util::Seed& seed)
	{
	    seed_ = seed;
	}

    protected:

    private:
	const unsigned size_;
	chromosome_encoding chromosome_;
	util::Seed seed_;

	GeneticIndividual& operator=(const GeneticIndividual&) = delete;
	GeneticIndividual& operator=(GeneticIndividual&&) = delete;
    };
}

#endif /* GENETIC_INDIVIDUAL_H */

