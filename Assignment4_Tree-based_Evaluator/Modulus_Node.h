#pragma once
#ifndef _MODULUS_NODE_H_
#define _MODULUS_NODE_H_

#include "Binary_Node.h"
#include "Node_Visitor.h"

class Modulus_Node : public Binary_Node{
	public:
		Modulus_Node();  // constructor 
		virtual void accept(Node_Visitor& visitor);  // visit modulus node
};


#endif