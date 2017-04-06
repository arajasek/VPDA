#include "Automaton.h"
using namespace std;

void Automaton::run() {
	accepted = false;
	stack<StackAlphabet> stk;
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
	stack<StackAlphabet> stk = s.getStack();

	LocalTransition lTransitions;
	StackTransition sTransitions;

	char inputBit = input.at(progress);
	switch (inputBit) {
		case 'a' :
			sTransitions = currNode.getATransitions();
			for (int i = 0; i < sTransitions.size(); i++) {
				stk.push(sTransitions.at(i).second());
				AutomatonState newState (progress + 1, sTransitions.at(i).first(), stk);
				States.push(newState);
			}
		break;
		case 'b':
			sTransitions = currNode.getBTransitions();
			for (int i = 0; i < sTransitions.size(); i++) {
				stk.push(sTransitions.at(i).second());
				AutomatonState newState (progress + 1, sTransitions.at(i).first(), stk);
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
		break;
		case 'f':
		break;
	}
}