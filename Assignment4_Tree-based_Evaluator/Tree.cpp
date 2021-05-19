#include "Tree.h"

Tree::Tree()
	:head_(nullptr),
	visitor_(new Post_Node_Visitor())
{
}

Tree::~Tree()
{
	if (head_ != nullptr) {
		delete head_;
		head_ = nullptr;
	}
	delete visitor_;
	visitor_ = nullptr;
}

int Tree::eval(void)
{
	if (head_ == nullptr) {
		throw std::runtime_error("Tree Head was nullptr");
	}

	head_->accept(*visitor_);
	return visitor_->get_result();
}

Node& Tree::get_head()
{
	return *head_;
}

void Tree::set_head(Node& node)
{
	this->head_ = &node;
}
