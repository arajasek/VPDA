#include "Automaton.h"
using namespace std;

void Automaton::run() {
	accepted = false;
	stack<unsigned int> stk;
	AutomatonState init (0, 0, stk);
	States.push(init);
	while (!States.empty() && !accepted) {
		AutomatonState s = States.front();
		States.pop();
		processState(s);
	}
}

void Automaton::processState(AutomatonState s) {
	Node currNode = Nodes.at(s.getNodeId());
	unsigned int progress = s.getProgress();
	stack<unsigned int> stk = s.getStack();

	if (progress == input.size()) {
		if (stk.empty() && currNode.getFinal())
			accepted = true;
		return;
	}

	LocalTransition lTransitions;
	StackTransition sTransitions;
	unsigned int topOfStack = stk.top();

	char inputBit = input.at(progress);
	switch (inputBit) {
		case 'a' :
			sTransitions = currNode.getATransitions();
			for (int i = 0; i < sTransitions.size(); i++) {
				stk.push(sTransitions.at(i).second);
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
			}
		break;
		case 'b':
			sTransitions = currNode.getBTransitions();
			for (int i = 0; i < sTransitions.size(); i++) {
				stk.push(sTransitions.at(i).second);
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
			}
		break;
		case 'c':
			lTransitions = currNode.getCTransitions();
			for (int i = 0; i < lTransitions.size(); i++) {
				AutomatonState newState (progress + 1, lTransitions.at(i), stk);
				States.push(newState);
			}
		break;
		case 'd':
			lTransitions = currNode.getDTransitions();
			for (int i = 0; i < lTransitions.size(); i++) {
				AutomatonState newState (progress + 1, lTransitions.at(i), stk);
				States.push(newState);
			}
		break;
		case 'e':
		sTransitions = currNode.getETransitions();
		stk.pop();
		for (int i = 0; i < sTransitions.size(); i++) {
			if (sTransitions.at(i).second == topOfStack) {
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
			}
		}
		break;
		case 'f':
		sTransitions = currNode.getFTransitions();
		stk.pop();
		for (int i = 0; i < sTransitions.size(); i++) {
			if (sTransitions.at(i).second == topOfStack) {
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
			}
		}
		break;
	}
}