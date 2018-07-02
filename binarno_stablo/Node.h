#pragma once
#include <iostream>
class Node
{
private:
	int key;
	Node *lp, *dp;
public:
	Node();//sdsd
	Node(int el, Node *levi, Node *desni);
	Node(int el);
	inline void visit() { std::cout << key << " "; };
	int getKey() { return key; };
	void setKey(int k) { key = k; };
	bool operator==(int el);
	bool operator>(int el);
	bool operator<(int el);
	bool operator<=(int el);
	bool operator>=(int el);
	Node * getleft() { return lp; }
	Node * getright() { return dp; }
	void setleft(Node *p);
	void setright(Node *p);
	inline void setleft(int null) { lp = NULL; }
	inline void setright(int null) { dp = NULL; }
};