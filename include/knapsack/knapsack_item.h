/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_item.h
 * Author: krewli
 *
 * Created on January 29, 2016, 8:34 PM
 */

#ifndef KNAPSACK_ITEM_H
#define KNAPSACK_ITEM_H

#include "knapsack_id.h"

namespace knapsack
{

    class KnapsackItem
    {
    public:
	KnapsackItem(const KnapsackID& id, int value, int weight)
	: id_{ id }, value_{ value }, weight_{ weight }
	{
	}

	KnapsackItem(const KnapsackItem&) = default;
	KnapsackItem(KnapsackItem&&) = default;

	~KnapsackItem() = default;

	int get_value() const
	{
	    return value_;
	}

	int get_weight() const
	{
	    return weight_;
	}

	bool operator==(const KnapsackItem& other) const
	{
	    return (id_ == other.id_);
	}

	bool operator!=(const KnapsackItem& other) const
	{
	    return !(*this == other);
	}

    protected:

    private:
	const KnapsackID id_;
	const int value_;
	const int weight_;

	KnapsackItem& operator=(const KnapsackItem&) = delete;
	KnapsackItem& operator=(KnapsackItem&&) = delete;
    };
}

#endif /* KNAPSACK_ITEM_H */

