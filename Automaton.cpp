#include "Automaton.h"
#include <iostream>
using namespace std;

bool Automaton::run(std::string inp) {

	//Clear the states queue
	std::queue <AutomatonState> q;
	States = q;

	accepted = false;
	input = inp;
	stack<unsigned int> stk;
	AutomatonState init (0, 0, stk);
	States.push(init);
	while (!States.empty() && !accepted) {
		AutomatonState s = States.front();
		States.pop();
		processState(s);
	}
	if (accepted)
		return true;
	else
		return false;
}

void Automaton::processState(AutomatonState s) {
//	cout << "processing "<<s.getNodeId()<<endl;
	Node currNode = Nodes.at(s.getNodeId());
	unsigned int progress = s.getProgress();
	stack<unsigned int> stk = s.getStack();

	if (progress == input.size()) {
		if (currNode.getFinal()) {
			if (!stk.empty())
				cout<<"in state "<<currNode.getId()<<" but stk is bad\n" << stk.top() << " "<<stk.size();
			accepted = true;
		}
		return;
	}

	LocalTransition lTransitions;
	StackTransition sTransitions;
	unsigned int topOfStack;

	char inputBit = input.at(progress);
	switch (inputBit) {
		case 'a' :
			sTransitions = currNode.getATransitions();
			for (int i = 0; i < sTransitions.size(); i++) {
				stk.push(sTransitions.at(i).second);
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
				stk.pop();
			}
		break;
		case 'b':
			sTransitions = currNode.getBTransitions();
			for (int i = 0; i < sTransitions.size(); i++) {
				stk.push(sTransitions.at(i).second);
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
				stk.pop();
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
		topOfStack = stk.top();
		sTransitions = currNode.getETransitions();
		stk.pop();
		for (int i = 0; i < sTransitions.size(); i++) {
			if (sTransitions.at(i).second == topOfStack || sTransitions.at(i).second == 0) {
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
			}
		}
		break;
		case 'f':
		topOfStack = stk.top();
		sTransitions = currNode.getFTransitions();
		stk.pop();
		for (int i = 0; i < sTransitions.size(); i++) {
			if (sTransitions.at(i).second == topOfStack || sTransitions.at(i).second == 0) {
				AutomatonState newState (progress + 1, sTransitions.at(i).first, stk);
				States.push(newState);
			}
		}
		break;
	}
}