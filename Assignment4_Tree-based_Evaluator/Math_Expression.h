#pragma once
#ifndef _MATH_EXPRESSION_H_
#define _MATH_EXPRESSION_H_

class Math_Expression{
	public:
		Math_Expression();  // constructor
		virtual ~Math_Expression();  // destructor
		virtual int eval(void) = 0;  // evaluate the expression and get back the result.
};

#endif