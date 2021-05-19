#pragma once
#ifndef _NODE_H_
#define _NODE_H_

class Node_Visitor;

class Node {
	public:
		Node(void);  // constructor
		virtual ~Node(void) = 0;  // destructor

		/*
		Accept a node visitor.
		
		@param[in]		visitor		The Node Visitor that has a certain algo attached to it.
		*/
		virtual void accept(Node_Visitor & visitor) = 0;

		/*
		Determines if the node is a leaf.
		
		@returns	boolean		If the node is a leaf.
		*/
		virtual bool is_leaf() = 0;

};


#endif