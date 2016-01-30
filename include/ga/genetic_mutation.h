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
				double probability,
				const util::Seed& seed);

	static genotype mutate_gene(const genotype& gene,
				double probability,
				const util::Seed& seed);
    };
}


#endif /* GENETIC_MUTATION_H */

