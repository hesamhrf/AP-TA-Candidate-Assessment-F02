#include "Tree.hpp"


Tree::Tree() {
	Tree::operatorCreatorMap[std::pair<std::string, char>("AND", 'a')] = &Node::CreateOperator<ArethmaticAnd>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("OR", 'a')] = &Node::CreateOperator<ArethmaticOr>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("NOT", 'a')] = &Node::CreateOperator<ArethmaticNot>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("XOR", 'a')] = &Node::CreateOperator<ArethmaticXor>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("AND", 'b')] = &Node::CreateOperator<BitwiseAnd>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("OR", 'b')] = &Node::CreateOperator<BitwiseOr>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("NOT", 'b')] = &Node::CreateOperator<BitwiseNot>;
	Tree::operatorCreatorMap[std::pair<std::string, char>("XOR", 'b')] = &Node::CreateOperator<BitwiseXor>;

	Tree::operandCreatorMap['d'] = &Node::CreateOperand<Decimal>;
	Tree::operandCreatorMap['b'] = &Node::CreateOperand<Binary>;
	Tree::operandCreatorMap['o'] = &Node::CreateOperand<Octal>;
	Tree::operandCreatorMap['h'] = &Node::CreateOperand<Hex>;

}

void Tree::Destroy() {
	root->Destroy();
}

Tree::~Tree() {
	this->Destroy();
}

void Tree::CheckTree() {
	if (!root->NumOfChildValid()) {
		throw FatalException("Invalid tree");
	}
}

bool Tree::IsvalidInput(std::string list, char input) {
	if (list.find(input) == std::string::npos) {
		return false;
	}
	return true;
}

Node* Tree::MakeNode(std::string type, int index, Node* parent, std::string argument) {
	if (type == "input") {
		return operandCreatorMap['d'](index, parent, argument);
	}
	else {
		if (std::find(validOperation.begin(), validOperation.end(), argument) == validOperation.end()) {
			throw Exception("Invalid Operator Type : " + argument);
		}
		return operatorCreatorMap[std::pair<std::string, char>(argument, 'a')](index, parent);
	}
}

std::string Tree::Evaluate(char base) {
	int result = root->CalculateResult();
	std::string showValue = "";
	switch (base) {
	case 'd':
		showValue = Decimal::Convert(result);
		break;
	case 'b':
		showValue = Binary::Convert(result);
		break;
	case 'o':
		showValue = Octal::Convert(result);
		break;
	case 'h':
		showValue = Hex::Convert(result);
		break;
	default:
		throw Exception("Invalid base for evaluate");
	}
	return showValue;
}

void Tree::Reset(int index, std::string value) {
	try {
		FindNode(index)->SetValue(value);
	}
	catch (Exception &exeption) {
		exeption.print();
	}

}

void Tree::Remode(int index, char mode) {
	if (!Tree::IsvalidInput(this->validOperatorType, mode)) {
		throw Exception("Invalid mode for remode");
	}
	Node* oldNode;
	try {
		oldNode = FindNode(index);
	}
	catch (Exception &exception) {
		exception.print();
		return;
	}
	Node* newNode = operatorCreatorMap[std::pair<std::string, char>(oldNode->GetOperation(), mode)](-1, NULL);
	try {
		*newNode = *oldNode;
	}
	catch (Exception &exception) {
		delete newNode;
	}
}


void Tree::Rebase(int index, char base) {
	if (!Tree::IsvalidInput(this->validBases, base)) {
		throw Exception("Invalid base for rebase");
	}
	Node* oldNode;
	std::string value;
	Node* newNode;
	try {
		oldNode = FindNode(index);
		value = oldNode->GetValue();
	}
	catch (Exception &exception) {
		exception.print();
		return;
	}
	try {
		newNode = operandCreatorMap[base](-1, NULL, "");
		newNode->SetValue(value);
		*newNode = *oldNode;
	}
	catch (Exception &exception) {
		exception.print();
		delete newNode;
	}

}


Node* Tree::FindNode(int index) {
	if (root != NULL) {
		Node* node = root->FindNode(index);
		if (node != NULL) {
			return node;
		}
		else {
			throw Exception("Node whit index " + std::to_string(index) + " not found");
		}
	}
	throw Exception("Tree is empty");
}


void Tree::AddNode(int index, int parent_index, std::string type, std::string argument) {
	Node* parent, *newNode;
	try {
		parent = FindNode(parent_index);
	}
	catch (Exception &exception) {
		if (index == ROOT_INDEX) {
			parent = NULL;
		}
		else {
			exception.print("parent of node with index (" + std::to_string(index) + ") invalid");
			throw exception;
		}
	}
	newNode = MakeNode(type, index, parent, argument);
	if (index == ROOT_INDEX) {
		this->root = newNode;
		return;
	}
	try {
		parent->AddChild(newNode);
	}
	catch (NodeException &exeption) {
		exeption.print();
		delete newNode;
		throw exeption;
	}

}