#pragma once
#ifndef _ADDITION_NODE_H_
#define _ADDITION_NODE_H_

#include "Binary_Node.h"
class Node_Visitor;

class Addition_Node : public Binary_Node {
	public:
		Addition_Node();
		virtual void accept(Node_Visitor& visitor);
};

#endif