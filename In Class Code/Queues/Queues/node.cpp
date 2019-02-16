#include "node.h"
Node::Node(const string &s) {
	name = s;
	//start using nullptr instead of NULL (better overall
	next = nullptr;
}