#ifndef OPERAND_HPP
#define OPERAND_HPP
#include "define.hpp"
#include "Node.hpp"
#include "Exception.hpp"


class Operand : public Node {

public:
	Operand();
	Operand(int index, Node* parent, std::string value);
	std::string GetValue();
	std::string GetOperation();
	bool CanAddChild();
	bool NumOfChildValid();
private:
	std::string value;
	static const std::string chars;
protected:
	void SetValue(std::string value, bool condition = true);
	int CalculateValue(int base);
	static std::string Convert(int value, int base);
	static bool IsValidValue(std::string value, int base);

};

class Decimal : public Operand {
public:
	Decimal();
	Decimal(int index, Node* parent, std::string value);
	int CalculateResult();
	static std::string Convert(int value);
	static bool IsValidValue(std::string value);
	void SetValue(std::string value);
private:
	static const int base = 10;
};

class Binary : public Operand {
public:
	Binary();
	Binary(int index, Node* parent, std::string value);
	int CalculateResult();
	static std::string Convert(int value);
	static bool IsValidValue(std::string value);
	void SetValue(std::string value);
private:
	static const int base = 2;
};

class Octal : public Operand {
public:
	Octal();
	Octal(int index, Node* parent, std::string value);
	int CalculateResult();
	static std::string Convert(int value);
	static bool IsValidValue(std::string value);
	void SetValue(std::string value);
private:
	static const int base = 8;
};

class Hex : public Operand {
public:
	Hex();
	Hex(int index, Node* parent, std::string value);
	int CalculateResult();
	static std::string Convert(int value);
	static bool IsValidValue(std::string value);
	void SetValue(std::string value);
private:
	static const int base = 16;
};

#endif