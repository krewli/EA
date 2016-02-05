/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_crossover.h
 * Author: krewli
 *
 * Created on February 2, 2016, 11:41 PM
 */

#ifndef GENETIC_CROSSOVER_H
#define GENETIC_CROSSOVER_H

#include "seed.h"

namespace ga
{

    template<typename individual_t, typename return_t>
    struct Crossover
    {
	using individual_type = individual_t;
	using return_type = return_t;

	static return_type offspring(const individual_type& parent1,
				const individual_type& parent2,
				const util::Seed& seed);
    };
}

#endif /* GENETIC_CROSSOVER_H */

