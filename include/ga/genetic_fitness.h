/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_fitness.h
 * Author: krewli
 *
 * Created on January 30, 2016, 3:55 PM
 */

#ifndef GENETIC_FITNESS_H
#define GENETIC_FITNESS_H

namespace ga
{

    template<typename chromosome_t, typename problem_t>
    struct Fitness
    {
	using chromosome_type = chromosome_t;
	using problem_type = problem_t;

	static double fitness(const chromosome_type& chromosome,
			const problem_type& problem);
    };
}

#endif /* GENETIC_FITNESS_H */

