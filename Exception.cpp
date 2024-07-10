#include "Exception.hpp"


Exception::Exception(std::string message) {
	this->message = message;
}

void Exception::print() {
	std::cout << message << std::endl;
}

void Exception::print(std::string additional_message) {
	std::cout << message << " " << additional_message << std::endl;
}



NodeException::NodeException(int index, std::string message) :Exception(message) {
	this->index = index;
}

void NodeException::PrintNodeInformation() {
	std::cout << "In Node with Index(" << index << ") : ";
}

void NodeException::print(std::string additional_message) {
	PrintNodeInformation();
	Exception::print(additional_message);
}

void NodeException::print() {
	PrintNodeInformation();
	Exception::print();
}



FatalException::FatalException(std::string message) :Exception(message) {

}