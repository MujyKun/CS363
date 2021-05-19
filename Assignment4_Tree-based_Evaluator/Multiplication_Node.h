#pragma once
#ifndef _MULTIPLICATION_NODE_H_
#define _MULTIPLICATION_NODE_H_

#include "Binary_Node.h"
#include "Node_Visitor.h"

class Multiplication_Node : public Binary_Node {
	public:
		Multiplication_Node();  // constructor
		virtual void accept(Node_Visitor& visitor);  // visit multiplication node
};



#endif