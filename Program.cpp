#include "Program.hpp"


void Program::Start() {
	try {
		Input input(&tree);
		input.InputTree();
		input.InputListener();
	}
	catch (FatalException &exception) {
		exception.print();
	}

}