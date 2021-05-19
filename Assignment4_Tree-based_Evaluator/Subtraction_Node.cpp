#include "Subtraction_Node.h"
#include "Node_Visitor.h"

Subtraction_Node::Subtraction_Node()
	:Binary_Node(1)
{
}

void Subtraction_Node::accept(Node_Visitor& visitor)
{
	visitor.visit_subtraction_node(*this);
}
