#include "Modulus_Node.h"

Modulus_Node::Modulus_Node()
	:Binary_Node(2)
{
}

void Modulus_Node::accept(Node_Visitor& visitor)
{
	visitor.visit_modulus_node(*this);
}
