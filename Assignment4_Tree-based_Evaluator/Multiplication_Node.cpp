#include "Multiplication_Node.h"

Multiplication_Node::Multiplication_Node()
	:Binary_Node(2)
{
}

void Multiplication_Node::accept(Node_Visitor& visitor)
{
	visitor.visit_multiplication_node(*this);
}
