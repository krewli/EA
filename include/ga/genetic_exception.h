/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   genetic_exception.h
 * Author: krewli
 *
 * Created on February 2, 2016, 11:21 PM
 */

#ifndef GENETIC_EXCEPTION_H
#define GENETIC_EXCEPTION_H

#include <exception>

namespace ga
{

    class GeneticException : public std::runtime_error
    {
    public:

	explicit GeneticException(const char* message)
	: std::runtime_error(message)
	{
	}

	explicit GeneticException(const std::string& message)
	: std::runtime_error(message)
	{
	}

	virtual ~GeneticException() throw ()
	{
	}

	virtual const char* what() const throw ()
	{
	    return msg_.c_str();
	}

    protected:
	std::string msg_;
    };

    class InvalidChromosomeSize : public GeneticException
    {
    public:

	explicit InvalidChromosomeSize(int actual_size, int expected_size)
	: GeneticException(std::string{ "(" + std::to_string(actual_size) + ")" +
			" does not match the expected size (" +
			std::to_string(expected_size) + ")." })
	{
	}

	~InvalidChromosomeSize() override = default;
    };

}

#endif /* GENETIC_EXCEPTION_H */

