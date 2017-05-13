#include "Node.h"
#include "Automaton.h"
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>

using namespace std;

void convertOdd(string &s) {
	for (int i = 0; i < s.size()/2; i++) {
		if (s.at(i) == '0')
			s.at(i) = 'a';
		else
			s.at(i) = 'b';
	}

	if (s.at(s.size()/2) == '0')
		s.at(s.size()/2) = 'c';
	else
		s.at(s.size()/2) = 'd';

	for (int i = s.size()/2 + 1; i < s.size(); i++) {
		if (s.at(i) == '0')
			s.at(i) = 'e';
		else
			s.at(i) = 'f';
	}
}

void convertEven(string &s) {
	for (int i = 0; i < s.size()/2; i++) {
		if (s.at(i) == '0')
			s.at(i) = 'a';
		else
			s.at(i) = 'b';
	}

	for (int i = s.size()/2; i < s.size(); i++) {
		if (s.at(i) == '0')
			s.at(i) = 'e';
		else
			s.at(i) = 'f';
	}
}

void convert(string &s) {
	if (s.size() % 2 == 0)
		convertEven(s);
	else
		convertOdd(s);
}

int main() {

	Automaton a;
	Node f0, f1, s0, s1, t00, t01, t10, t11, u000, u001, u010, u011, u100, u101, u110, u111;
	std::pair <unsigned int, unsigned int> p;
	StackTransition sTransitions;
	LocalTransition lTransitions;

//f0 starts

	f0.setName("f0");
	f0.setId(0);

	p.first = 0;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 1;
	p.second = 3;
	sTransitions.push_back(p);
	f0.setATransitions(sTransitions);

	sTransitions.clear();

	p.first = 0;
	p.second = 2;
	sTransitions.push_back(p);
	f0.setBTransitions(sTransitions);

	sTransitions.clear();

	lTransitions.push_back(2);
	lTransitions.push_back(3);
	lTransitions.push_back(4);
	f0.setCTransitions(lTransitions);

	lTransitions.clear();

	lTransitions.push_back(2);
	lTransitions.push_back(5);
	f0.setDTransitions(lTransitions);

	lTransitions.clear();

	p.first = 2;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 3;
	sTransitions.push_back(p);
	p.first = 4;
	p.second = 0;
	sTransitions.push_back(p);
	f0.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 2;
	sTransitions.push_back(p);
	p.first = 5;
	p.second = 0;
	sTransitions.push_back(p);
	f0.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(f0);

//f1 starts

	f1.setName("f1");
	f1.setId(1);

	p.first = 1;
	p.second = 2;
	sTransitions.push_back(p);
	f1.setATransitions(sTransitions);

	sTransitions.clear();

	p.first = 0;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 1;
	p.second = 3;
	sTransitions.push_back(p);
	f1.setBTransitions(sTransitions);

	sTransitions.clear();

	lTransitions.push_back(3);
	lTransitions.push_back(6);
	f1.setCTransitions(lTransitions);

	lTransitions.clear();

	lTransitions.push_back(2);
	lTransitions.push_back(3);
	lTransitions.push_back(7);
	f1.setDTransitions(lTransitions);

	lTransitions.clear();

	p.first = 3;
	p.second = 2;
	sTransitions.push_back(p);
	p.first = 6;
	p.second = 0;
	sTransitions.push_back(p);
	f1.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 3;
	sTransitions.push_back(p);
	p.first = 7;
	p.second = 0;
	sTransitions.push_back(p);
	f1.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(f1);

//s0 starts
	s0.setName("s0");
	s0.setId(2);

	p.first = 2;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 3;
	sTransitions.push_back(p);
	s0.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 2;
	sTransitions.push_back(p);
	s0.setFTransitions(sTransitions);

	sTransitions.clear();
	s0.setFinal(true);
	a.addNode(s0);

//s1 starts
	s1.setName("s1");
	s1.setId(3);

	p.first = 3;
	p.second = 2;
	sTransitions.push_back(p);
	s1.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 2;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 3;
	p.second = 3;
	sTransitions.push_back(p);
	s1.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(s1);

//t00 starts

	t00.setName("t00");
	t00.setId(4);

	p.first = 4;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 6;
	p.second = 3;
	sTransitions.push_back(p);
	t00.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 5;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 7;
	p.second = 3;
	sTransitions.push_back(p);
	t00.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(t00);

//t01 starts

	t01.setName("t01");
	t01.setId(5);

	p.first = 4;
	p.second = 2;
	sTransitions.push_back(p);
	t01.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 5;
	p.second = 2;
	sTransitions.push_back(p);
	t01.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(t01);

//t10 starts

	t10.setName("t10");
	t10.setId(6);

	p.first = 6;
	p.second = 2;
	sTransitions.push_back(p);
	t10.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 7;
	p.second = 2;
	sTransitions.push_back(p);
	t10.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(t10);

//t11 starts

	t11.setName("t11");
	t11.setId(7);

	p.first = 4;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 6;
	p.second = 3;
	sTransitions.push_back(p);
	t11.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 5;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 7;
	p.second = 3;
	sTransitions.push_back(p);
	t11.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(t11);

//u000 starts

	u000.setName("u000");
	u000.setId(8);

	p.first = 8;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 12;
	p.second = 3;
	sTransitions.push_back(p);
	u000.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 9;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 13;
	p.second = 3;
	sTransitions.push_back(p);
	u000.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u000);

//u001 starts

	u001.setName("u001");
	u001.setId(9);

	p.first = 10;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 14;
	p.second = 3;
	sTransitions.push_back(p);
	u001.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 11;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 15;
	p.second = 3;
	sTransitions.push_back(p);
	u001.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u001);

//u010 starts

	u010.setName("u010");
	u010.setId(10);

	p.first = 8;
	p.second = 2;
	sTransitions.push_back(p);
	u010.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 9;
	p.second = 2;
	sTransitions.push_back(p);
	u010.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u010);

//u011 starts

	u011.setName("u011");
	u011.setId(11);

	p.first = 10;
	p.second = 2;
	sTransitions.push_back(p);
	u011.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 11;
	p.second = 2;
	sTransitions.push_back(p);
	u011.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u011);

//u100 starts

	u100.setName("u100");
	u100.setId(12);

	p.first = 12;
	p.second = 2;
	sTransitions.push_back(p);
	u100.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 13;
	p.second = 2;
	sTransitions.push_back(p);
	u100.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u100);

//u101 starts

	u101.setName("u101");
	u101.setId(13);

	p.first = 14;
	p.second = 2;
	sTransitions.push_back(p);
	u101.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 15;
	p.second = 2;
	sTransitions.push_back(p);
	u101.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u101);

//u110 starts

	u110.setName("u110");
	u110.setId(14);

	p.first = 8;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 12;
	p.second = 3;
	sTransitions.push_back(p);
	u110.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 9;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 13;
	p.second = 3;
	sTransitions.push_back(p);
	u110.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u110);

//u111 starts

	u111.setName("u111");
	u111.setId(14);

	p.first = 10;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 14;
	p.second = 3;
	sTransitions.push_back(p);
	u111.setETransitions(sTransitions);

	sTransitions.clear();

	p.first = 11;
	p.second = 1;
	sTransitions.push_back(p);
	p.first = 15;
	p.second = 3;
	sTransitions.push_back(p);
	u111.setFTransitions(sTransitions);

	sTransitions.clear();
	a.addNode(u111);

// try all binary strings

	for (unsigned int i = 2; i <= 5; i++) {
		int counter = 0;
		unsigned int limit = pow (2,i);
		for (unsigned int j = 0; j < limit; j++) {
			string word = bitset< 64 >( j ).to_string();
			word = word.substr(word.size() - i, i);
			if (word.at(0) == '0')
				continue;
			std::reverse(word.begin(),word.end());
			convert (word);
			//cout << "Trying " <<word<<endl;
			a.run(word);
		}
	}
}