#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>          // for input
#include <iostream>         // for cout
#include <sstream>			// for istringstream
#include "Stack.h"
#include "Array.h"
#include "Command.h"
#include "Command_Factory.h"
#include "Stack_Command_Factory.h"
#include "Array_Iterator.h"
#include "Queue.h"


class Calculator {
	public:
		// default constructor
		Calculator(void);

		/*
		Starts the Calculator Loop.
		Takes in Input and spits out result.
	
		To exit, type "QUIT" (case-sensitive)
		*/
		void run();
	private:
		/*
		Converts the an infix string to postfix.

		@param[in]      infix		   String for the infix.
		@param[in]      factory        The factory that creates the Commands.
		@param[in]      postfix        Array to fill with Commands.
		*/
		void convert_to_postfix(const std::string & infix, Command_Factory & factory, Array<Command*> postfix);

		/*
		Executes a list of commands.

		@param[in]      iter        Iterator to execute the commands.
		*/
		void evaluate_postfix(Array_Iterator<Command*>& iter);

		/*
		removes the operators enlisted in a parenthesis
		created to avoid duplicate code.

		@param[in]  operators_to_pop		A stack that holds the amount of operators to pop (using parenthesis)
		@param[in]  temp_queue				Temporary queue that holds the commands
		@param[in]  temp_operators			Stack that contains the operators
		*/
		void register_parenthesis_operators(Stack <int> & operators_to_pop, Queue<Command*> & temp_queue, Stack <Command*> & temp_operators);

};
#endif