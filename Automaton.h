#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <iostream>
#include <queue>
#include "AutomatonState.h"
#include "Node.h"

class Automaton {
	bool accepted;
	std::string input;
	std::vector <Node> Nodes;
	std::queue <AutomatonState> States;
public:
	void run(std::string s);
	void processState(AutomatonState);
	void addNode(Node n) { Nodes.push_back(n); }
};

#endif