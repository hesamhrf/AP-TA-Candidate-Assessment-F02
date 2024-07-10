#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include "define.hpp"


class Exception {
public:
	Exception(std::string message);
	virtual void print();
	virtual void print(std::string additional_message);
private:
	std::string message;

};


class NodeException : public Exception {
public:
	NodeException(int index, std::string message);
	void PrintNodeInformation();
	void print();
	void print(std::string additional_message);
private:
	int index;
};


class FatalException : public Exception {
public:
	FatalException(std::string message);
};

#endif