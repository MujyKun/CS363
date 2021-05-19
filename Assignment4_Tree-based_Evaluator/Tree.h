#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include "Math_Expression.h"
#include "Node.h"
#include "Post_Node_Visitor.h"
#include <stdexcept>

class Tree: public Math_Expression {
	public:
		Tree();  // constructor
		~Tree();  // destructor
		virtual int eval(void);  // evaluates the tree and returns result. Throws runtime_error if there is no head.
		Node& get_head();  // get the head of the tree. 
		void set_head(Node& node);  // set the head of the tree.

	private:
		Node* head_;  // head node.
		Post_Node_Visitor* visitor_;  // node visitor
};

#endif