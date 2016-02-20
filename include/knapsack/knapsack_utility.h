/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_utilities.h
 * Author: krewli
 *
 * Created on January 29, 2016, 8:34 PM
 */

#ifndef KNAPSACK_UTILITIES_H
#define KNAPSACK_UTILITIES_H

#include <string>

#include "knapsack.h"
#include "knapsack_individual_alias.h"
#include "knapsack_generation_alias.h"

#include "seed.h"

namespace knapsack
{
    // filenames ks_30_0, ks_50_0, ks_200_0, ks_400_0, ks_1000_0, ks_10000_0
    Knapsack read_knapsack(const std::string& filename);
    knapsack_individual::chromosome_encoding generate_default_chromosome(unsigned size);
    knapsack_individual generate_random_individual(const Knapsack& knapsack,
						   const util::Seed& seed = util::NO_SEED);
    knapsack_generation generate_random_generation(unsigned size,
						   const Knapsack& knapsack,
						   const util::Seed& seed = util::NO_SEED);
}


#endif /* KNAPSACK_UTILITIES_H */

