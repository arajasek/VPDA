#include "AutomatonState.h"

AutomatonState::AutomatonState(unsigned int prog, unsigned int currNode, std::stack<unsigned int> stk) {
	inputProgress = prog;
	nodeId = currNode;
	s = stk;
}