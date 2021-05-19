#pragma once
#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include "Binary_Node.h"
class Node_Visitor;

class Division_Node : public Binary_Node {
	public:
		Division_Node();  // constructor 
		virtual void accept(Node_Visitor& visitor);  // visit division node
};

#endif