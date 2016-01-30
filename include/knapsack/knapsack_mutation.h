/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_mutation.h
 * Author: krewli
 *
 * Created on January 30, 2016, 5:35 PM
 */

#ifndef KNAPSACK_MUTATION_H
#define KNAPSACK_MUTATION_H

#include "genetic_mutation.h"
#include "seed.h"

namespace knapsack
{
    struct KnapsackMutation
    : public ga::Mutation<bool, std::vector<bool>>
    {

	static chromosome_type mutate(const chromosome_type& chromosome,
				unsigned double probability,
				const util::Seed & seed = util::NO_SEED)
	{
	    unsigned seed_counter = 0;
	    util::Seed internal_seed = seed;

	    chromosome_type new_chromosome = chromosome;

	    std::for_each(std::begin(new_chromosome), std::end(new_chromosome),
		    [&](chromosome_type::reference gene)
		    {
			if (internal_seed != util::NO_SEED)
			    internal_seed += seed_counter++;
			gene = mutate_gene(gene, probability, internal_seed);
		    });

	    return new_chromosome;
	}

	static genotype mutate_gene(const genotype& gene,
				double probability,
				const util::Seed & seed)
	{
	    genotype new_gene = gene;

	    if (util::get_random_real(0, 1, seed) < probability) {

		new_gene = gene == true ? false : true;
	    }

	    return new_gene;
	}
    };
}

#endif /* KNAPSACK_MUTATION_H */

