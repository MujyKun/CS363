#pragma once
#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Node.h"
class Node_Visitor;

class Number_Node : public Node {
public:
	Number_Node();  // constructor 
	Number_Node(int num);  // constructor that takes in the value of the number node.
	virtual void accept(Node_Visitor& visitor);  // visit the number node.
	int get_value();  // get the number node's value.
	virtual bool is_leaf();  // check if the node is a leaf. Always true on number node.
private:
	int value_;  // value of the node.
};

#endif