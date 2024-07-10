#include "Node.hpp"

Node::Node() {
	this->index = INVALID_INDEX;
	this->parent = NULL;
}

Node::Node(int index, Node* parent) {
	this->index = index;
	this->parent = parent;
}

void Node::Destroy() {
	for (int i = 0; i < children.size(); i++) {
		children[i]->Destroy();
	}
	delete this;
}
void Node::ReplaceChild(Node* node) {
	for (int i = 0; i < children.size(); i++) {
		Node* temp = children[i];
		if (children[i]->index == node->index) {
			children[i] = node;
			delete temp;
			break;
		}
	}
}

void Node::operator=(const Node &node) {
	this->index = node.index;
	this->parent = node.parent;
	for (int i = 0; i < node.children.size(); i++) {
		this->children.push_back(node.children[i]);
	}
	if (parent != NULL) {
		this->parent->ReplaceChild(this);
	}
}

void Node::AddChild(Node* child) {
	if (CanAddChild()) {
		this->children.push_back(child);
	}
	else {
		throw NodeException(this->index, "You cant add child");
	}
}



Node* Node::FindNode(int index) {
	if (this->index == index) {
		return this;
	}
	else {
		for (Node* child : children) {
			Node* result = child->FindNode(index);
			if (result != NULL) {
				return result;
			}
		}
		return NULL;
	}
}