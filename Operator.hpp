#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include "define.hpp"
#include "Node.hpp"
#include "Exception.hpp"


class Operator : public Node {

public:
	std::string GetValue();
	Operator(int index, Node* parent);
	void SetValue(std::string value);
	bool CanAddChild();
	bool NumOfChildValid();
protected:
	virtual bool CanAddCondition() = 0;
	virtual bool NumOfChildCondition() = 0;

};

class And : public Operator {
public:
	And(int index, Node* parent);
	bool CanAddCondition();
	std::string GetOperation();
	bool NumOfChildCondition();
};

class ArethmaticAnd : public And {
public:
	ArethmaticAnd(int index, Node* parent);
	int CalculateResult();

};

class BitwiseAnd :public And {
public:
	BitwiseAnd(int index, Node* parent);
	int CalculateResult();
};

class Or : public Operator {
public:
	Or(int index, Node* parent);
	bool CanAddCondition();
	std::string GetOperation();
	bool NumOfChildCondition();
};

class ArethmaticOr : public Or {

public:
	ArethmaticOr(int index, Node* parent);
	int CalculateResult();

};

class BitwiseOr :public Or {
public:
	BitwiseOr(int index, Node* parent);
	int CalculateResult();
};

class Not : public Operator {
public:
	Not(int index, Node* parent);
	bool CanAddCondition();
	std::string GetOperation();
	bool NumOfChildCondition();
};

class ArethmaticNot : public Not {

public:
	ArethmaticNot(int index, Node* parent);
	int CalculateResult();

};

class BitwiseNot :public Not {
public:
	BitwiseNot(int index, Node* parent);
	int CalculateResult();
};

class Xor : public Operator {
public:
	Xor(int index, Node* parent);
	bool CanAddCondition();
	std::string GetOperation();
	bool NumOfChildCondition();
};

class ArethmaticXor : public Xor {
public:
	ArethmaticXor(int index, Node* parent);
	int CalculateResult();

};

class BitwiseXor :public Xor {
public:
	BitwiseXor(int index, Node* parent);
	int CalculateResult();
};

#endif