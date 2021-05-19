#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

#include <string>	// for input
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Command_Factory.h"
#include "Stack.h"

class Stack_Command_Factory: public Command_Factory {
public:
	Stack_Command_Factory(Stack <int>& stack);

	virtual ~Stack_Command_Factory(void);
	virtual Number_Command* create_number_command(int num);
	virtual Add_Command* create_add_command(void);
	virtual Subtract_Command* create_subtract_command(void);
	virtual Multiply_Command* create_multiplication_command(void);
	virtual Divide_Command* create_division_command(void);
	virtual Modulus_Command* create_modulus_command(void);
private:
	Stack <int>& stack_;
};
#endif