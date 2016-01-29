/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "knapsack_utility.h"
#include "knapsack_item.h"
#include "knapsack_id.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

namespace Knapsack
{
    Knapsack read_knapsack_data( const std::string& filename )
    {
	std::ifstream file { filename } ;

	if ( !file )
	{
	    throw std::runtime_error("Could not open file " + filename + ".\n") ;
	}

	unsigned capacity ;
	unsigned number_of_items ;

	file >> number_of_items >> capacity ;

	Knapsack::data_type items ;

	int value, weight ;

	for ( unsigned i = 0 ; i < number_of_items ; i++ )
	{
	    file >> value >> weight ;
	    items.push_back(KnapsackItem { KnapsackID(i), value, weight }) ;
	}

	file.close() ;

	return Knapsack { capacity, number_of_items, items } ;
    }
}
