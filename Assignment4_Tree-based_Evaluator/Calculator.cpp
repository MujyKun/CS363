#include "Calculator.h"


Calculator::Calculator() 
	:builder_(nullptr)
{
}

Calculator::Calculator(Builder& builder)
	:builder_(&builder)
{
}

Calculator::~Calculator()
{
	if (builder_ != nullptr) {
		delete builder_;
		builder_ = nullptr;
	}
}

int Calculator::evaluate(const std::string& infix)
{
	std::istringstream input_stream(infix);
	std::string c_value;  // holds the current stream value
	this->builder_->start_expression();

	while (!input_stream.eof()) {
		input_stream >> c_value;
		evaluate_val(c_value);
	}

	return get_result();
}

void Calculator::evaluate_val(const std::string& val)
{
	if (val == "+") {
		builder_->build_addition_operator();
	}
	else if (val == "-") {
		builder_->build_subtraction_operator();
	}
	else if (val == "*") {
		builder_->build_multiplication_operator();
	}
	else if (val == "/") {
		builder_->build_division_operator();
	}
	else if (val == "%") {
		builder_->build_modulus_operator();
	}
	else if (val == "(") {
		builder_->build_open_parenthesis();
	}
	else if (val == ")") {
		builder_->build_close_parenthesis();
	}
	else {
		// assuming int
		builder_->build_number(std::stoi(val));
	}
}

int Calculator::get_result()
{
	if (this->builder_ == nullptr) {
		throw std::runtime_error("No Builder was found inside the calculator. No result can be given.");
	}
	return this->builder_->get_expression().eval();
}

void Calculator::start_manual_expression() {
	this->builder_->start_expression();
}

Builder& Calculator::get_builder(void)
{
	if (builder_ == nullptr) {
		throw std::runtime_error("Builder does not exist on retrieval.");
	}
	return *builder_;
}
