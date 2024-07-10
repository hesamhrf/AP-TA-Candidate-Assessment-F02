#ifndef NODE_HPP
#define NODE_HPP
#include "define.hpp"
#include "Exception.hpp"


class Node {

public:
	Node();
	Node(int index, Node* parent);
	Node* FindNode(int index);
	template<typename T> static  Node* CreateOperand(int index, Node* parent, std::string argument);
	template<typename T> static  Node* CreateOperator(int index, Node* parent);
	void AddChild(Node* child);
	void operator=(const Node &node);
	virtual std::string GetValue() = 0;
	virtual void SetValue(std::string value) = 0;
	virtual int CalculateResult() = 0;
	virtual std::string GetOperation() = 0;
	virtual bool CanAddChild() = 0;
	virtual bool NumOfChildValid() = 0;
	void Destroy();
private:
	const int INVALID_INDEX = -1;
	Node* parent;
	void ReplaceChild(Node* parent);
protected:
	std::vector<Node*> children;
	int index;

};

typedef std::map<char, Node* (*) (int, Node*, std::string)> OperandMap;
typedef std::map<std::pair<std::string, char>, Node* (*) (int, Node*)> OperatorMap;

template<typename T>   Node* Node::CreateOperand(int index, Node* parent, std::string argument) {
	return new T(index, parent, argument);
}

template<typename T>   Node* Node::CreateOperator(int index, Node* parent) {
	return new T(index, parent);
}

#endif