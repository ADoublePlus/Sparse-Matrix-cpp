#pragma once

#define __SPARSEMATRIX_EXCEPTIONS_H__

#include <exception>
#include <string>

class Exception : public std::exception
{
	public:
		explicit Exception(const std::string& message) : exception(), message(message) {}
		virtual ~Exception(void) throw () {}

		inline std::string getMessage(void) const { return this->message; }

	protected:
		std::string message;
};

class InvalidDimensionsException : public Exception
{
	public:
		InvalidDimensionsException(const std::string& message) : Exception(message) {}
};

class InvalidCoordinatesException : public Exception
{
	public:
		InvalidCoordinatesException(const std::string& message) : Exception(message) {}
};