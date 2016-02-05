/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <exception>
#include <stdexcept>

#include "random.h"

namespace util
{

    int get_random_integer( int lower_bound, int upper_bound, const Seed& seed )
    {
	if ( lower_bound > upper_bound )
	{
	    throw InvalidBoundError(lower_bound, upper_bound);
	}

	auto random_generator = get_random_generator(seed);
	std::uniform_int_distribution<> dist(lower_bound, upper_bound);
	return dist(random_generator);
    }

    double get_random_real( int lower_bound, int upper_bound, const Seed& seed )
    {
	if ( lower_bound > upper_bound )
	{
	    throw InvalidBoundError(lower_bound, upper_bound);
	}

	auto random_generator = get_random_generator(seed);
	std::uniform_real_distribution<> dist(lower_bound, upper_bound);
	return dist(random_generator);
    }

    std::mt19937 get_random_generator( const Seed& seed )
    {
	std::random_device rd;
	std::mt19937 random_generator(rd());

	if ( seed != NO_SEED )
	    random_generator.seed(seed.get_value());

	return random_generator;
    }
}

