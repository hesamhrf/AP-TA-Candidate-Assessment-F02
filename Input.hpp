#ifndef INPUT_HPP
#define INPUT_HPP
#include "Tree.hpp"


class Input {

public:
	Input(Tree *tree);
	void InputTree();
	void InputListener();


private:
	Tree *tree;
	void InputNode();


};

#endif