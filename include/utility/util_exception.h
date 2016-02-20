/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exception.h
 * Author: krewli
 *
 * Created on January 30, 2016, 5:13 PM
 */

#ifndef UTIL_EXCEPTION_H
#define UTIL_EXCEPTION_H

#include <exception>

namespace util
{

    class UtilException : public std::runtime_error
    {
    public:

	explicit UtilException(const char* message)
	: std::runtime_error(message) { }

	explicit UtilException(const std::string& message)
	: std::runtime_error(message) { }

	virtual ~UtilException() throw () { }

	virtual const char* what() const throw ()
	{
	    return msg_.c_str();
	}

    protected:
	std::string msg_;
    };

    class InvalidBoundError : public UtilException
    {
    public:

	explicit InvalidBoundError(double lower_bound, double upper_bound)
	: UtilException(std::string{ "Upper bound (" +
			std::to_string(upper_bound) +
			") has to be strict greater than lower bound (" +
			std::to_string(lower_bound) + ")." }) { }

	~InvalidBoundError() override = default;
    };

}


#endif /* EXCEPTION_H */

