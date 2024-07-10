#include "Operator.hpp"


Operator::Operator(int index, Node* parent) :Node(index, parent) {

}

bool Operator::NumOfChildValid() {
	if (NumOfChildCondition()) {
		for (Node* child : children) {
			if (!child->NumOfChildValid()) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Operator::SetValue(std::string value) {
	throw NodeException(index,"this Node is Operator and doesn't have value");
}

std::string Operator::GetValue() {
	throw NodeException(index,"this Node is Operator and doesn't have value");
}

bool Operator::CanAddChild() {
	if (CanAddCondition()) {
		return true;
	}
	else {
		throw Exception("Maximum argument");
		return false;
	}
}




And::And(int index, Node* parent) :Operator(index, parent) {

}

bool And::NumOfChildCondition() {
	return children.size() == 2;
}

std::string And::GetOperation() {
	return "AND";
}

bool And::CanAddCondition() {
	return children.size() + 1 <= 2;
}




ArethmaticAnd::ArethmaticAnd(int index, Node* parent) :And(index, parent) {

}

int ArethmaticAnd::CalculateResult() {
	int temp = children[0]->CalculateResult() * children[1]->CalculateResult();
	return temp;
}



BitwiseAnd::BitwiseAnd(int index, Node* parent) :And(index, parent) {

}

int BitwiseAnd::CalculateResult() {
	return children[0]->CalculateResult() & children[1]->CalculateResult();
}



Or::Or(int index, Node* parent) :Operator(index, parent) {

}

bool Or::NumOfChildCondition() {
	return children.size() == 2;
}

std::string Or::GetOperation() {
	return "OR";
}

bool Or::CanAddCondition() {
	return children.size() + 1 <= 2;
}




ArethmaticOr::ArethmaticOr(int index, Node* parent) :Or(index, parent) {

}

int ArethmaticOr::CalculateResult() {
	int temp = children[0]->CalculateResult() + children[1]->CalculateResult();
	return temp;
}



BitwiseOr::BitwiseOr(int index, Node* parent) :Or(index, parent) {

}

int BitwiseOr::CalculateResult() {
	return children[0]->CalculateResult() | children[1]->CalculateResult();
}



Not::Not(int index, Node* parent) :Operator(index, parent) {

}

bool Not::NumOfChildCondition() {
	return children.size() == 1;
}

std::string Not::GetOperation() {
	return "NOT";
}

bool Not::CanAddCondition() {
	return children.size() + 1 == 1;
}




ArethmaticNot::ArethmaticNot(int index, Node* parent) :Not(index, parent) {

}

int ArethmaticNot::CalculateResult() {
	int temp = -1 * children[0]->CalculateResult();
	return temp;
}



BitwiseNot::BitwiseNot(int index, Node* parent) :Not(index, parent) {

}

int BitwiseNot::CalculateResult() {
	return ~children[0]->CalculateResult();
}








Xor::Xor(int index, Node* parent) :Operator(index, parent) {

}

bool Xor::NumOfChildCondition() {
	return children.size() >= 1;
}

std::string Xor::GetOperation() {
	return "XOR";
}

bool Xor::CanAddCondition() {
	return true;
}




ArethmaticXor::ArethmaticXor(int index, Node* parent) :Xor(index, parent) {

}

int ArethmaticXor::CalculateResult() {

	
	int size = children.size();
	auto compare = [](Node* a, Node* b) {
		return a->CalculateResult() < b->CalculateResult();
	};
	std::vector<Node*> sortedChildren = children;
	std::sort(sortedChildren.begin(), sortedChildren.end(), compare);
	if (size % 2)
	{
		return sortedChildren[(size / 2)]->CalculateResult();
	}
	else
	{
		return (sortedChildren[(size / 2)]->CalculateResult() + sortedChildren[(size / 2) - 1]->CalculateResult()) / 2;
	}

}


BitwiseXor::BitwiseXor(int index, Node* parent) :Xor(index, parent) {

}

int BitwiseXor::CalculateResult() {
	int result = children[0]->CalculateResult();
	for (int i = 1; i < children.size(); i++) {
		result = children[i]->CalculateResult() ^ result;
	}
	return result;
}
