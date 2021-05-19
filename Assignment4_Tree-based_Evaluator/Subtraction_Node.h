#pragma once
#ifndef _SUBTRACTION_NODE_H_
#define _SUBTRACTION_NODE_H_

#include "Binary_Node.h"
class Node_Visitor;

class Subtraction_Node : public Binary_Node {
	public:
		Subtraction_Node();
		virtual void accept(Node_Visitor& visitor);
};

#endif