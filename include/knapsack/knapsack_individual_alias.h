/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_alias.h
 * Author: krewli
 *
 * Created on February 3, 2016, 12:11 AM
 */

#ifndef KNAPSACK_ALIAS_H
#define KNAPSACK_ALIAS_H

#include "knapsack.h"
#include "knapsack_mutation.h"
#include "knapsack_fitness.h"

#include "genetic_individual.h"

namespace knapsack
{
    using knapsack_individual = ga::GeneticIndividual <
	    bool,
	    std::vector<bool>,
	    Knapsack,
	    KnapsackMutation,
	    KnapsackFitness>;
}

#endif /* KNAPSACK_ALIAS_H */

