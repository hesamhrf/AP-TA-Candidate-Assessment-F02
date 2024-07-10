
#include "Input.hpp"



Input::Input(Tree *tree) {
	this->tree = tree;
}

void Input::InputNode() {
	int index, parentIndex;
	std::string type, argument;
	std::cin >> index >> parentIndex >> type >> argument;
	tree->AddNode(index, parentIndex, type, argument);
}

void Input::InputTree() {
	int numOfNodes = 0;
	std::cin >> numOfNodes;
	for (int inputCount = 0; inputCount < numOfNodes; inputCount++) {
		try {
			InputNode();
		}
		catch (Exception &exception) {
			inputCount--;
		}
	}
	tree->CheckTree();
}

void Input::InputListener() {
	while (true) {
		try {
			std::string operation;
			std::cin >> operation;
			if (operation == "evaluate") {
				std::string base;
				std::cin >> base;
				std::cout << tree->Evaluate(base[1]) << std::endl;
			}
			else if (operation == "rebase") {
				std::string base;
				int index;
				std::cin >> base >> index;
				tree->Rebase(index, base[1]);
			}
			else if (operation == "remode") {
				std::string mode;
				int index;
				std::cin >> mode >> index;
				tree->Remode(index, mode[1]);
			}
			else if (operation == "reset") {
				std::string value;
				int index;
				std::cin >> index >> value;
				tree->Reset(index, value);
			}
			else {
				throw Exception("Invalid command");
			}
		}
		catch (Exception &exception) {
			exception.print();
		}
	}

}
