#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

// pairs of (destination state, stack letter)
// stack letter 0 corresponds to "anything"
// stack letter 1 corresponds to "0, 0"
// stack letter 2 corresponds to "0, 1" ("1, 0" case is symmetric)
// stack letter 3 corresponds to "1, 1"
typedef std::vector<std::pair<unsigned int, unsigned int> > StackTransition;

typedef std::vector<unsigned int> LocalTransition;

class Node {
	bool final;	
	unsigned int id;
	std::string name;
	StackTransition aTransitions;
	StackTransition bTransitions;
	LocalTransition cTransitions;
	LocalTransition dTransitions;
	StackTransition eTransitions;
	StackTransition fTransitions;

public:
	std::string getName() { return name;}
	unsigned int getId() { return id;}
	bool getFinal() { return final;}
	StackTransition getATransitions() { return aTransitions;}
	StackTransition getBTransitions() { return bTransitions;}
	LocalTransition getCTransitions() { return cTransitions;}
	LocalTransition getDTransitions() { return dTransitions;}
	StackTransition getETransitions() { return eTransitions;}
	StackTransition getFTransitions() { return fTransitions;}

	void setName(std::string n) { name = n;}
	void setId(unsigned int n) { id = n;}
	void setFinal(bool b) { final = b;}
	void setATransitions(StackTransition v) {aTransitions = v;}
	void setBTransitions(StackTransition v) {bTransitions = v;}
	void setCTransitions(LocalTransition v) {cTransitions = v;}
	void setDTransitions(LocalTransition v) {dTransitions = v;}
	void setETransitions(StackTransition v) {eTransitions = v;}
	void setFTransitions(StackTransition v) {fTransitions = v;}
};

#endif
