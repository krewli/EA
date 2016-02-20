/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knapsack_id.h
 * Author: krewli
 *
 * Created on January 29, 2016, 9:03 PM
 */

#ifndef KNAPSACK_ID_H
#define KNAPSACK_ID_H

namespace knapsack
{

    class KnapsackID
    {
    public:
	KnapsackID(int id)
	: id_{ id }
	{
	}

	KnapsackID(const KnapsackID&) = default;
	KnapsackID(KnapsackID&&) = default;

	~KnapsackID() = default;

	bool operator==(const KnapsackID& other) const
	{
	    return (id_ == other.id_);
	}

	bool operator!=(const KnapsackID& other) const
	{
	    return !(*this == other);
	}

    private:
	const int id_;

	KnapsackID& operator=(const KnapsackID&) = delete;
	KnapsackID& operator=(KnapsackID&&) = delete;
    };
}

#endif /* KNAPSACK_ID_H */

