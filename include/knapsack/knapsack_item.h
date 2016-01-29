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

namespace Knapsack
{

    class KnapsackItemID
    {
    public:
	KnapsackItemID(int id)
	: id_{ id }
	{
	}

	KnapsackItemID(const KnapsackItemID&) = default;
	
	~KnapsackItemID() = default;

	bool operator==(const KnapsackItemID& other) const
	{
	    return (id_ == other.id_);
	}
	
	bool operator!=(const KnapsackItemID& other) const
	{
	    return !(*this == other);
	}

    private:
	const int id_;
	
	KnapsackItemID(KnapsackItemID&&) = delete;
	
	KnapsackItemID& operator=(const KnapsackItemID&) = delete;
	KnapsackItemID& operator=(KnapsackItemID&&) = delete;
    };

    class KnapsackItem
    {
    public:
	KnapsackItem(const KnapsackItemID& id, int value, int weight)
	: id_{ id }, value_{ value }, weight_{ weight }
	{
	}

	KnapsackItem(const KnapsackItem&) = default;

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
	const KnapsackItemID id_;
	const int value_;
	const int weight_;

	KnapsackItem& operator=(const KnapsackItem&) = delete;
    };
}

#endif /* KNAPSACK_ITEM_H */

