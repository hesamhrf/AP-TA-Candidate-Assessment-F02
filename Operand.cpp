#include "Operand.hpp"


const std::string Operand::chars = "0123456789ABCDEF";


Operand::Operand() {

}

Operand::Operand(int index, Node* parent, std::string value) : Node(index, parent) {
	this->value = value;
}

bool Operand::NumOfChildValid() {
	if (children.size() == 0) {
		return true;
	}
	return false;
}

bool Operand::CanAddChild() {
	return false;
}

std::string Operand::GetOperation() {
	throw NodeException(this->index, "Node is an operand that has no operations");
}

std::string Operand::GetValue() {
	return this->value;
}

void Operand::SetValue(std::string value, bool condition) {
	if (condition) {
		this->value = value;
	}
	else {
		throw NodeException(this->index, "Invalid value");
	}
}

int Operand::CalculateValue(int base) {
	int val = 0;
	for (int i = 0; i < value.size(); i++) {
		val = val * base + chars.find(value[i]);
	}
	return val;
}

std::string Operand::Convert(int value, int base) {
	std::string result = "";
	std::string sign = "";
	if (value < 0) {
		sign = "-";
		value = abs(value);
	}

	while (value > 0) {
		int rem = value % base;
		result = chars[rem] + result;
		value /= base;
	}

	return sign + result;
}

bool Operand::IsValidValue(std::string value, int base) {
	const std::string validChars = chars.substr(0, base);
	for (char ch : value) {
		if (validChars.find(ch) == std::string::npos) {
			return false;
		}
	}
	return true;
}




Decimal::Decimal() {}

Decimal::Decimal(int index, Node* parent, std::string value) :Operand(index, parent, value) {

};

void Decimal::SetValue(std::string value) {
	Operand::SetValue(value, IsValidValue(value));
}

int Decimal::CalculateResult() {
	return CalculateValue(base);
}


std::string Decimal::Convert(int value) {
	return Operand::Convert(value, base);
}

bool  Decimal::IsValidValue(std::string value) {
	return Operand::IsValidValue(value, base);
}


Binary::Binary() {}


Binary::Binary(int index, Node* parent, std::string value) :Operand(index, parent, value) {
};

void Binary::SetValue(std::string value) {
	Operand::SetValue(value, IsValidValue(value));
}

int Binary::CalculateResult() {
	return CalculateValue(base);
}

std::string Binary::Convert(int value) {
	return Operand::Convert(value, base);
}
bool  Binary::IsValidValue(std::string value) {
	return Operand::IsValidValue(value, base);
}




Octal::Octal() {

}

Octal::Octal(int index, Node* parent, std::string value) :Operand(index, parent, value) {
};

void Octal::SetValue(std::string value) {
	Operand::SetValue(value, IsValidValue(value));
}

int Octal::CalculateResult() {
	return CalculateValue(base);
}

std::string Octal::Convert(int value) {
	return Operand::Convert(value, base);
}

bool  Octal::IsValidValue(std::string value) {
	return Operand::IsValidValue(value, base);
}



Hex::Hex() {}


Hex::Hex(int index, Node* parent, std::string value) :Operand(index, parent, value) {
};

void Hex::SetValue(std::string value) {
	Operand::SetValue(value, IsValidValue(value));
}

int Hex::CalculateResult() {
	return CalculateValue(base);
}

std::string Hex::Convert(int value) {
	return Operand::Convert(value, base);
}

bool  Hex::IsValidValue(std::string value) {
	return Operand::IsValidValue(value, base);
}