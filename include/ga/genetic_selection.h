/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_selection.h
 * Author: krewli
 *
 * Created on February 2, 2016, 11:41 PM
 */

#ifndef GENETIC_SELECTION_H
#define GENETIC_SELECTION_H

#include "seed.h"

namespace ga
{

    template<typename individual_t, typename generation_t, typename problem_t>
    struct Selection
    {
	using individual_type = individual_t;
	using generation_type = generation_t;
	using problem_type = problem_t;

	static individual_type select(const generation_type& generation,
				const problem_type& problem,
				const util::Seed& seed);
    };


}

#endif /* GENETIC_SELECTION_H */

