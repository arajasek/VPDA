#include "Node.h"
#include "Automaton.h"
#include <iostream>
using namespace std;
int main() {
	Node n;
	n.setName("node0");
	StackAlphabet c;
	c.b3 = true;
	LocalTransition v;
	v.push_back(3);
	StackTransition v2;
	v2.push_back(make_pair(2, c));
	n.setCTransitions(v);
	n.setETransitions(v2);
	cout<<n.getName()<<endl<<c.b1<<" "<<c.b3<<"ll";
	Automaton a;
}