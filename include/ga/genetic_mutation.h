/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_mutation.h
 * Author: krewli
 *
 * Created on January 30, 2016, 3:54 PM
 */

#ifndef GENETIC_MUTATION_H
#define GENETIC_MUTATION_H

#include <algorithm>
#include <iterator>

#include "seed.h"
#include "random.h"

namespace ga
{

    template<typename gene_t, typename chromosome_t>
    struct Mutation
    {
	using genotype = gene_t;
	using chromosome_type = chromosome_t;

	static chromosome_type mutate(const chromosome_type& chromosome,
				unsigned double probability,
				const util::Seed& seed)
	{
	    unsigned seed_counter = 0;
	    util::Seed internal_seed = seed;

	    chromosome_type new_chromosome = chromosome;

	    std::for_each(std::begin(new_chromosome), std::end(new_chromosome),
		    [&](genotype& gene)
		    {
			if (internal_seed != util::NO_SEED)
			    internal_seed += seed_counter++;
			gene = mutate_gene(gene, probability, internal_seed);
		    });

	    return new_chromosome;
	}

	static genotype mutate_gene(const genotype& gene,
				unsigned double probability,
				const util::Seed& seed);
    };
}


#endif /* GENETIC_MUTATION_H */

