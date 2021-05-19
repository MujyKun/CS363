#pragma once
#ifndef _POST_NODE_VISITOR_H_
#define _POST_NODE_VISITOR_H_
// post-order traversal logic  ( visit left, visit right, perform operation ) 

#include "Node_Visitor.h"
#include "Stack.h"

class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Number_Node;
class Node;
class Binary_Node;

// visit nodes in post order.
class Post_Node_Visitor: public Node_Visitor {
	public:
		Post_Node_Visitor();  // constructor
		~Post_Node_Visitor();  // destructor

		virtual void visit_addition_node(Addition_Node& node);  // visit the Addition node.
		virtual void visit_subtraction_node(Subtraction_Node& node); // visit the Subtraction node.
		virtual void visit_multiplication_node(Multiplication_Node& node); // visit the Multiplication node.
		virtual void visit_division_node(Division_Node& node); // visit the Division node. 
		virtual void visit_modulus_node(Modulus_Node& node); // visit the Modulus node.
		virtual void visit_number_node(Number_Node& node); // visit the Number node. 
		int get_result(void);  // get the result.
	private:
		void eval_children(Binary_Node& bin_node);  // push leaf nodes to 
		int result_;  // the final result of an expression after computations are done.
		int num1_;  // variable to hold left side number of an expression
		int num2_; // variable to hold right side number of an expression.
		Stack<int>* stack_;  // stack to hold values while going through the nodes.
};

#endif