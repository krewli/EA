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

    template<typename gene, typename chromosome>
    struct Mutation
    {
	using genotype = gene;
	using chromosome_type = chromosome;

	virtual static chromosome_type mutate(const chromosome_type& chromosome,
					double probability,
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

	virtual static genotype mutate_gene(const genotype& gene,
					double probability,
					const util::Seed& seed) = 0;
    };

    struct KnapsackMutation : public Mutation<bool, std::vector<bool>>
    {
	static genotype mutate_gene(const genotype& gene,
				double probability,
				const util::Seed & seed) override
	{
	    genotype new_gene;

	    if (util::get_random_real(0, 1, seed) < probability) {

		new_gene = gene == true ? false : true;
	    }

	    return new_gene;
	}
    };
}


#endif /* GENETIC_MUTATION_H */

