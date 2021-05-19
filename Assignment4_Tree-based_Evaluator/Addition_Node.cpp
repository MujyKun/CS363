#include "Addition_Node.h"
#include "Node_Visitor.h"

Addition_Node::Addition_Node()
	:Binary_Node(1)
{
}

void Addition_Node::accept(Node_Visitor& visitor)
{
	visitor.visit_addition_node(*this);
}
