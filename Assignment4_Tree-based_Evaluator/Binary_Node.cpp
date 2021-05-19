#include "Binary_Node.h"

Binary_Node::Binary_Node()
	:left_node_(nullptr),
	right_node_(nullptr),
	precedence_(0)
{
}

Binary_Node::Binary_Node(int precedence)
	:left_node_(nullptr),
	right_node_(nullptr),
	precedence_(precedence)
{
}

Binary_Node::~Binary_Node()
{
	if (left_node_ != nullptr) {
		delete left_node_;
	}
	if (right_node_ != nullptr) {
		delete right_node_;
	}
}

Node* Binary_Node::get_left_node(void)
{
	if (left_node_ == nullptr) {
			throw std::runtime_error("Unable to retrieve left node. This means an invalid expression was created or was used at the wrong time.");
		}
	return left_node_;
}

Node* Binary_Node::get_right_node(void)
{
	if (right_node_ == nullptr) {
		throw std::runtime_error("Unable to retrieve right node. This means an invalid expression was created or was used at the wrong time.");
	}
	return right_node_;
}

void Binary_Node::set_left_node(Node& node)
{
	this->left_node_ = &node;
}

void Binary_Node::set_right_node(Node& node)
{
	this->right_node_ = &node;
}

int Binary_Node::get_precedence(void)
{
	return precedence_;
}

bool Binary_Node::is_leaf()
{
	return (get_left_node() == nullptr && get_right_node() == nullptr);
}
