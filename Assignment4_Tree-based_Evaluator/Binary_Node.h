#pragma once
#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_

#include "Node.h"
#include <stdexcept>
class Node_Visitor;

class Binary_Node : public Node {
	public: 
		Binary_Node();  // constructor
		Binary_Node(int precedence);  // constructor passing in the precedence of the node
		virtual ~Binary_Node() = 0;  // destructor
		virtual void accept(Node_Visitor& visitor) = 0;  // visit the node

		/*
		Get the left child node.

		@returns	Node*	Left Child Node
		*/
		Node* get_left_node(void);

		/*
		Get the right child node.

		@returns	Node*	Left Child Node
		*/
		Node* get_right_node(void);

		/*
		Set the left child node.

		@param[in]		Node*	New Left Child Node
		*/
		void set_left_node(Node& node);

		/*
		Set the right child node.

		@param[in]		Node*	New Right Child Node
		*/
		void set_right_node(Node& node);

		/*
		Get the node precedence

		@returns	int		Precedence of node
		*/
		int get_precedence(void);

		/*
		Determines if the node is a leaf.
		
		@returns	boolean		If the node is a leaf.
		*/
		virtual bool is_leaf();
private:
	Node* left_node_;  // left child node
	Node* right_node_;  // right child node
	// precedence level
	// 0 null
	// 1 Addition, Subtraction
	// 2 modulus, division, multiplication
	int precedence_; 
};


#endif