#include "AutomatonState.h"

AutomatonState::AutomatonState(unsigned int prog, unsigned int currNode, std::stack<StackAlphabet> stk) {
	inputProgress = prog;
	nodeId = currNode;
	s = stk;
}