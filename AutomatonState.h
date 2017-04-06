#ifndef AUTOMATON_STATE_H
#define AUTOMATON_STATE_H

#include "StackAlphabet.h"
#include <stack>

class AutomatonState {
	unsigned int inputProgress;
	unsigned int nodeId;
	std::stack <unsigned int> s;
public:
	AutomatonState(unsigned int, unsigned int, std::stack<unsigned int>);
	unsigned int getProgress() { return inputProgress;}
	unsigned int getNodeId() { return nodeId;}
	std::stack <unsigned int> getStack() { return s;}

	void setProgress(unsigned int p) { inputProgress = p;}
	void setNodeId(unsigned int n) { nodeId = n;}
	void setStack(std::stack <unsigned int> stk) { s = stk;}
};

#endif