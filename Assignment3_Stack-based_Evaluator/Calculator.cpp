#include "Calculator.h"


Calculator::Calculator() {
	// do nothing
}

void Calculator::run() {

	Stack <int> result;  // contains final result of current expression.
	Stack_Command_Factory factory = Stack_Command_Factory(result); // command factory
	std::string infix_input;  // contains user input.
	bool keep_going = true;
	while (keep_going) {  // constant loop until QUIT is called

		try {
			// clear existing vars to have them reusable without reallocating.
			infix_input.clear();
			result.clear();

			std::cout << "\nPlease enter a math expression or type QUIT to exit.\n";
			std::getline(std::cin, infix_input);  // get input

			// exit case.
			if (infix_input == "QUIT") {
				keep_going = false;
				break;
			}

			Array <Command*> postfix;
			// turn infix to postfix.
			convert_to_postfix(infix_input, factory, postfix);
			// evaluate postfix

			// get final result.
			int final_result = result.top();
			std::cout << final_result;
		}
		catch (std::exception& err) {
			std::cout << "An error has occurred -> " << err.what() << "\n";
		}
	}
}

void Calculator::convert_to_postfix(const std::string & infix, Command_Factory & factory, Array<Command*> postfix)
{
	Queue<Command*> temp_queue = Queue<Command*>();
	std::istringstream input_stream(infix);
	std::string c_value;  // holds the current stream value
	Stack <Command*> temp_operators;
	Command* cmd = 0;
	Command* temp_cmd = 0;
	Stack <int> operators_to_pop; // contains the amount of operators to pop in a parenthesis

	while (!input_stream.eof()) {
		input_stream >> c_value;

		if (c_value == "+") {
			cmd = factory.create_add_command();
		}
		else if (c_value == "-") {
			cmd = factory.create_subtract_command();
		}
		else if (c_value == "*") {
			cmd = factory.create_multiplication_command();
		}
		else if (c_value == "/") {
			cmd = factory.create_division_command();
		}
		else if (c_value == "%") {
			cmd = factory.create_modulus_command();
		}
		else if (c_value == "(") {
			// open parantheses
			// cmd = factory.create_parenthesis_command();
			// temp_operators.push(cmd);

			// add another integer to the queue indicating there is a new parenthesis
			operators_to_pop.push(0);
			continue;
		}
		else if (c_value == ")") {
			// close parantheses
			if (operators_to_pop.is_empty()) {
				throw std::runtime_error("Closed parenthesis does not match any open parenthesis.");
			}

			// get the amount of operators to pop.
			register_parenthesis_operators(operators_to_pop, temp_queue, temp_operators);
			operators_to_pop.pop();

			// if there is another parenthesis, confirm the operations in between are registered.
			// ex ( ( 9 + 4 ) * ( 5 + 4 ) ) -> Where the * should be registered earlier.
			if (!operators_to_pop.is_empty())
				register_parenthesis_operators(operators_to_pop, temp_queue, temp_operators);

			continue;
		}

		else {
			cmd = factory.create_number_command(std::stoi(c_value));
			// add cmd to queue then put it into array 
			// this is beneficial for knowing the exact amount to resize the array to.
			temp_queue.enqueue(cmd);
			continue;
			
		}


		//  If there are parenthesis OR ( if the concrete value is an operator AND (the stack is empty OR the operator is a greater precedence than the top of the stack) ) )
		if (!operators_to_pop.is_empty() || (cmd->get_concrete_value() > 0 && (temp_operators.is_empty() || (cmd->get_concrete_value() > temp_operators.top()->get_concrete_value())))) {
			// if there are any parenthesis, update the amount of operators to pop.
			if (!operators_to_pop.is_empty()) {
				int incremented_value = operators_to_pop.top() + 1;
				operators_to_pop.pop();
				operators_to_pop.push(incremented_value);
			}

			// push to stack
			temp_operators.push(cmd);



		}
		else {
			temp_queue.enqueue(temp_operators.top());
			temp_operators.pop();
			temp_operators.push(cmd);

			// if there are any parenthesis, update the amount of operators to pop.
			if (!operators_to_pop.is_empty()) {
				int decremented_value = operators_to_pop.top() - 1;
				operators_to_pop.pop();
				operators_to_pop.push(decremented_value);
			}
		}

	}  // end of while loop

	// empty any remaining operators in the stack.
	while (!temp_operators.is_empty()) {
		temp_queue.enqueue(temp_operators.top());
		temp_operators.pop();
	}

	int amount_of_operators = 0;


	// move from queue to array
	postfix.resize(temp_queue.size());
	for (int i = 0; !temp_queue.is_empty(); i++) {
		Command* cmd = temp_queue.dequeue();
		if (cmd->get_concrete_value() > 0) {
			amount_of_operators++;
		}

		// prints out the postfix format in regards to the precedence.
		// std::cout << "command -> " << cmd->get_concrete_value() << "\n";
		postfix[i] = cmd;
	}


	// do not allow an expression to proceed if there are no operators and more than one number.
	if (postfix.size() > 1 && not amount_of_operators) {
		throw std::runtime_error("No operators were found in the expression and a number was not found by itself.");
	}

	Array_Iterator<Command*> iterator = Array_Iterator<Command*> (postfix);
	evaluate_postfix(iterator);
}

void Calculator::evaluate_postfix(Array_Iterator<Command*>& iter)
{
	for (; !iter.is_done(); iter.advance()) {
		(*iter)->execute();
		delete* iter;
	}
}

void Calculator::register_parenthesis_operators(Stack<int> & operators_to_pop, Queue<Command*> & temp_queue, Stack<Command*> & temp_operators)
{
	int number_of_operators_to_pop = operators_to_pop.top();

	while (number_of_operators_to_pop > 0) {
		temp_queue.enqueue(temp_operators.top());
		temp_operators.pop();
		number_of_operators_to_pop--;
	}

	// Incase we have parenthesis inside of each other
	operators_to_pop.pop(); 
	operators_to_pop.push(number_of_operators_to_pop); // basically pushing 0
}
