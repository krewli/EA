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

#include <iostream>

#include "genetic_exception.h"

#include "seed.h"
#include "random.h"
#include "util_exception.h"

namespace ga
{

    template<
    typename gene_t,
    typename chromosome_t,
    typename problem_t,
    class mutation_p,
    class fitness_p
    >
    class GeneticIndividual
    {
    public:
	using genotype_encoding = gene_t;
	using chromosome_encoding = chromosome_t;
	using problem_type = problem_t;
	using mutation_policy = mutation_p;
	using fitness_policy = fitness_p;

	GeneticIndividual(unsigned size)
	: size_{ size }, seed_{ util::NO_SEED }
	{
	}

	GeneticIndividual(const GeneticIndividual&) = default;
	GeneticIndividual(GeneticIndividual&&) = default;

	GeneticIndividual& operator=(const GeneticIndividual&) = default;
	GeneticIndividual& operator=(GeneticIndividual&&) = default;

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

	util::Seed get_seed() const
	{
	    return seed_;
	}

	void set_chromosome(const chromosome_encoding& chromosome)
	{
	    if (chromosome.size() != size_)
	    {
		throw InvalidChromosomeSize(chromosome.size(), size_);
	    }

	    chromosome_ = chromosome;
	}

	void set_seed(const util::Seed& seed)
	{
	    seed_ = seed;
	}

	bool operator==(const GeneticIndividual& other) const
	{
	    return (size_ == other.size_ &&
		    chromosome_ == other.chromosome_ &&
		    seed_ == other.seed_);
	}

	bool operator!=(const GeneticIndividual& other) const
	{
	    return !(*this == other);
	}
	
	void print_chromosome()
	{
	    for (unsigned i = 0; i < chromosome_.size(); ++i)
	    {
		std::cout << chromosome_.at(i) << " ";
	    }
	    std::cout << std::endl;
	}


    protected:

    private:
	unsigned size_;
	chromosome_encoding chromosome_;
	util::Seed seed_;
    };
    
}

#endif /* GENETIC_INDIVIDUAL_H */

