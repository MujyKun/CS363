#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command {
public:
	Command(void); // default constructor
	Command(int concrete_value);
	~Command(void); // destructor

	virtual void execute(void) = 0;

	// gets the value that the concrete type is assigned to in hierachy.
	int get_concrete_value();

private:
	int concrete_value_; // representation of the hierachy of the operator (precedence).
};
#endif