#include "Node.h"
#include "Automaton.h"
#include <iostream>

using namespace std;
int main() {
	Automaton a;
	Node f0, f1, s0, s1;
	std::pair <unsigned int, unsigned int> p;
	StackTransition sTransitions;
	LocalTransition lTransitions;

//f0 starts

	f0.setName("f0");
	f0.setId(0);

	p.first = 0;
	p.second = 0;
	sTransitions.push_back(p);
	p.first = 1;
	p.second = 2;
	sTransitions.push_back(p);
	f0.setATransitions(sTransitions);

	sTransitions.clear();

	p.first = 0;
	p.second = 1;
	sTransitions.push_back(p);
	f0.setBTransitions(sTransitions);

	sTransitions.clear();

	lTransitions.push_back(2);
	lTransitions.push_back(3);
	f0.setCTransitions(lTransitions);

	lTransitions.clear();

	lTransitions.push_back(2);
	f0.setDTransitions(lTransitions);

	lTransitions.clear();

	p.first = 2;
	p.second = 0;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 2;
	sTransitions.push_back(p);
	f0.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 1;
	sTransitions.push_back(p);
	f0.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(f0);

//f1 starts

	f1.setName("f1");
	f1.setId(1);

	p.first = 1;
	p.second = 1;
	sTransitions.push_back(p);
	f1.setATransitions(sTransitions);

	sTransitions.clear();

	p.first = 0;
	p.second = 0;
	sTransitions.push_back(p);
	p.first = 1;
	p.second = 2;
	sTransitions.push_back(p);
	f1.setBTransitions(sTransitions);

	sTransitions.clear();

	lTransitions.push_back(3);
	f1.setCTransitions(lTransitions);

	lTransitions.clear();

	lTransitions.push_back(2);
	lTransitions.push_back(3);
	f1.setDTransitions(lTransitions);

	lTransitions.clear();

	p.first = 3;
	p.second = 1;
	sTransitions.push_back(p);
	f1.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 0;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 2;
	sTransitions.push_back(p);
	f1.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(f1);

//s0 starts
	s0.setName("s0");
	s0.setId(2);

	p.first = 2;
	p.second = 0;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 2;
	sTransitions.push_back(p);
	s0.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 1;
	sTransitions.push_back(p);
	s0.setFTransitions(sTransitions);

	sTransitions.clear();
	s0.setFinal(true);
	a.addNode(s0);

//s1 starts
	s1.setName("s1");
	s1.setId(3);

	p.first = 3;
	p.second = 1;
	sTransitions.push_back(p);
	s1.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 0;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 2;
	sTransitions.push_back(p);
	s1.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(s1);

	a.run("aaaeee");
}