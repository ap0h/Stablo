#include "Node.h"

Node::Node()
{
	lp = dp = NULL;
}

Node::Node(int el, Node *levi, Node *desni)
{
	key = el;
	lp = levi;
	dp = desni;
}
Node::Node(int el)
{
	key = el;
	lp = NULL;
	dp = NULL;
}
bool Node::operator==(int el)
{
	return key == el;
}

bool Node::operator>(int el)
{
	return key > el;
}
bool Node::operator<(int el)
{
	return key < el;
}
bool Node::operator<=(int el)
{
	return key <= el;
}
bool Node::operator>=(int el)
{
	return key >= el;
}

void Node::setleft(Node * p)
{
	lp = p;
}
void Node::setright(Node * p)
{
	dp = p;
}
