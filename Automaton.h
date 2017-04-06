#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <iostream>
#include <queue>
#include "AutomatonState.h"
#include "Node.h"
typedef std::vector<char> Input;

class Automaton {
	bool accepted;
	Input input;
	std::vector <Node> Nodes;
	std::queue <AutomatonState> States;
public:
	void run();
	void processState(AutomatonState);
};

#endif