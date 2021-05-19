#include "Division_Node.h"
#include "Node_Visitor.h"

Division_Node::Division_Node()
	:Binary_Node(2)
{
}

void Division_Node::accept(Node_Visitor& visitor)
{
	visitor.visit_division_node(*this);
}
