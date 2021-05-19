#pragma once
#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Math_Expression.h"

class Builder {
	public:
		Builder();
		virtual ~Builder() = 0;
		virtual void start_expression(void) = 0;  // start a new expression.

		// build the nodes into a concrete Math_Expression.
		virtual void build_number(int number) = 0;
		virtual void build_addition_operator(void) = 0;
		virtual void build_subtraction_operator(void) = 0;
		virtual void build_multiplication_operator(void) = 0;
		virtual void build_division_operator(void) = 0;
		virtual void build_modulus_operator(void) = 0;
		virtual void build_open_parenthesis(void) = 0;
		virtual void build_close_parenthesis(void) = 0;

		/*
		If the current builder has its own calculator 
		meaning that it is evaluating a sub-expression.
		This also means that the concrete builder can go down to another branch.

		Not required across all concrete builders, will default return false
		since the calculator would not exist in this abstract class.

		@returns	boolean		If builder has a calculator.
		*/
		virtual bool has_calculator(void);
		virtual Math_Expression& get_expression(void) = 0;  // get the Math_Expression (abstract) involved with the builder.
};

#endif