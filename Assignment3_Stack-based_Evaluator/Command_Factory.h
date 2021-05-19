#ifndef _COMMAND_FACTORY_H_
#define _COMMAND_FACTORY_H_

#include <string>	// for input
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"

class Command_Factory {
	public:
		Command_Factory();  // default constructor
		virtual ~Command_Factory(void);
		virtual Number_Command* create_number_command(int num) = 0;
		virtual Add_Command* create_add_command(void) = 0;
		virtual Subtract_Command* create_subtract_command(void) = 0;
		virtual Multiply_Command* create_multiplication_command(void) = 0;
		virtual Divide_Command* create_division_command(void) = 0;
		virtual Modulus_Command* create_modulus_command(void) = 0;
	private:
		// operations not allowed (based on lecture and powerpoint).
		// Command_Factory(const Command_Factory&);
		//const Command_Factory& operator = (const Command_Factory&);

};
#endif