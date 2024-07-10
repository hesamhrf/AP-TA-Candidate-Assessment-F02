#ifndef TREE_HPP
#define TREE_HPP
#include "define.hpp"
#include "Exception.hpp"
#include "Operator.hpp"
#include "Operand.hpp"


class Tree {

public:
	Tree();
	~Tree();
	Node* FindNode(int index);
	void AddNode(int index, int parent, std::string type, std::string argument);
	void CheckTree();
	std::string Evaluate(char base);
	void Rebase(int index, char base);
	void Remode(int index, char mode);
	void Reset(int index, std::string value);
	Node* MakeNode(std::string type, int index, Node* parent, std::string argument);
	void Destroy();
private:
	const int ROOT_INDEX = 0;
	Node *root = NULL;
	OperatorMap operatorCreatorMap;
	OperandMap operandCreatorMap;
	const std::string validBases = "dboh";
	const std::string validOperatorType = "ba";
	const std::vector<std::string> validOperation = { "AND","OR","NOT","XOR" };
	static bool IsvalidInput(std::string list, char input);
};

#endif