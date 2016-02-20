/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: krewli
 *
 * Created on January 29, 2016, 8:28 PM
 */

#include <cstdlib>
#include <iostream>

#include "knapsack.h"
#include "knapsack_generation_alias.h"
#include "knapsack_genetic_solver.h"

using namespace std;
using namespace knapsack;

/*
 * 
 */
int main( int argc, char** argv )
{
    try
    {
	Knapsack knapsack = read_knapsack("data/knapsack/ks_3_0");
	
	knapsack_generation solution = knapsack_genetic_solve(10, 10, 0.1, knapsack);
	
	for (const auto& child : solution.get_generation())
	{
	    cout << child.fitness(knapsack) << endl;
	}
	
    }
    catch ( std::runtime_error& e )
    {
	cout << "Runtime error: " << e.what() << endl;
	return 1;
    }

    return 0;
}

