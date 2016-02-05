/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_data.h
 * Author: krewli
 *
 * Created on January 29, 2016, 8:35 PM
 */

#ifndef KNAPSACK_DATA_H
#define KNAPSACK_DATA_H

#include <vector>

#include "knapsack_item.h"

namespace knapsack
{

    class Knapsack
    {
    public:
	using data_type = std::vector<KnapsackItem>;

	Knapsack(unsigned capacity, unsigned item_count, const data_type& data)
	: capacity_{ capacity }, item_count_{ item_count }, data_{ data }
	{
	}

	Knapsack(const Knapsack&) = default;
	Knapsack(Knapsack&&) = default;

	~Knapsack() = default;

	data_type get_data() const
	{
	    return data_;
	}

	unsigned get_capacity() const
	{
	    return capacity_;
	}

	unsigned get_item_count() const
	{
	    return item_count_;
	}

	double get_value_at(unsigned index) const
	{
	    return data_.at(index).get_value();
	}

	bool operator==(const Knapsack& other) const
	{
	    return (capacity_ == other.capacity_ &&
		    item_count_ == other.item_count_ &&
		    data_ == other.data_);
	}

	bool operator!=(const Knapsack& other) const
	{
	    return !(*this == other);
	}

    protected:

    private:
	const unsigned capacity_;
	const unsigned item_count_;
	const data_type data_;

	Knapsack& operator=(const Knapsack&) = delete;
	Knapsack& operator=(Knapsack&&) = delete;
    };
}


#endif /* KNAPSACK_DATA_H */

