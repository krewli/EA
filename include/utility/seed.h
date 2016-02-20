/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   seed.h
 * Author: krewli
 *
 * Created on January 30, 2016, 2:25 PM
 */

#ifndef SEED_H
#define SEED_H

namespace util
{

    class Seed
    {
    public:
	Seed(long int seed_value)
	: seed_{ seed_value }
	{
	}

	Seed(const Seed&) = default;

	Seed& operator=(const Seed&) = default;
	Seed& operator=(Seed&&) = default;

	~Seed() = default;

	bool operator==(const Seed& other) const
	{
	    return seed_ == other.seed_;
	}

	bool operator!=(const Seed& other) const
	{
	    return !(*this == other);
	}

	Seed operator+(int val)
	{
	    Seed copy{ *this };
	    copy += val;
	    return copy;
	}

	Seed& operator+=(int val)
	{
	    seed_ += val;
	    return *this;
	}

	Seed& operator++()
	{
	    ++seed_;
	    return *this;
	}

	Seed operator++(int)
	{
	    Seed result(*this);
	    ++(*this);
	    return result;
	}

	void set_value(unsigned long int seed_value)
	{
	    seed_ = seed_value;
	}

	long int get_value() const
	{
	    return seed_;
	}

    private:
	long int seed_;

    };

    static const Seed NO_SEED{ -1 };
}

#endif /* SEED_H */

