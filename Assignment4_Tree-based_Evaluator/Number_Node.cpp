#include "Number_Node.h"
#include "Node_Visitor.h"

Number_Node::Number_Node()
	:value_(0)
{
}

Number_Node::Number_Node(int num) 
	:value_(num)
{
}

void Number_Node::accept(Node_Visitor& visitor)
{
	visitor.visit_number_node(*this);
}

int Number_Node::get_value()
{
	return value_;
}

bool Number_Node::is_leaf()
{
	return true;
}
