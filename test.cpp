#include "Node.h"
#include "Automaton.h"
#include <iostream>
using namespace std;
int main() {
	Node n;
	n.setName("node0");
	unsigned int c;
	LocalTransition v;
	v.push_back(3);
	StackTransition v2;
	v2.push_back(make_pair(2, c));
	n.setCTransitions(v);
	n.setETransitions(v2);
	Automaton a;
}