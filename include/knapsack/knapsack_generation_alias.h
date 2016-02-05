/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_generation_alias.h
 * Author: krewli
 *
 * Created on February 5, 2016, 4:53 PM
 */

#ifndef KNAPSACK_GENERATION_ALIAS_H
#define KNAPSACK_GENERATION_ALIAS_H

#include "knapsack_individual_alias.h"
#include "knapsack_crossover.h"
#include "knapsack_selection.h"

#include "genetic_generation.h"

namespace knapsack
{
    using knapsack_generation = ga::GeneticGeneration<
	    knapsack_individual,
	    knapsack_generation_type,
	    KnapsackRouletteWheel,
	    KnapsackRandomPoint>;

}


#endif /* KNAPSACK_GENERATION_ALIAS_H */

