/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   random.h
 * Author: krewli
 *
 * Created on January 30, 2016, 4:18 PM
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <string>

#include "seed.h"
#include "util_exception.h"

namespace util
{
    int get_random_integer(int lower_bound, int upper_bound, const Seed& seed = NO_SEED);
    double get_random_real(int lower_bound, int upper_bound, const Seed& seed = NO_SEED);
    std::mt19937 get_random_generator(const Seed& seed);
}

#endif /* RANDOM_H */

