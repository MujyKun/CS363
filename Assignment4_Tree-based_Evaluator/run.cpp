#include "Calculator.h"
#include <string>
#include "Tree_Builder.h"
#include "Builder.h"

int main(int argc, char* argv[])
{
	Builder* builder = new Tree_Builder();
	Calculator* calc = new Calculator(*builder);

	std::string infix_input;  // contains user input.
	bool keep_going = true;
	while (keep_going) {  // constant loop until QUIT is called

		try {
			// clear existing vars to have them reusable without reallocating.
			infix_input.clear();

			std::cout << "\nPlease enter a math expression or type QUIT to exit.\n";
			std::getline(std::cin, infix_input);  // get input

			// exit case.
			if (infix_input == "QUIT") {
				keep_going = false;
				break;
			}

			// evaluate the expression.
			std::cout << calc->evaluate(infix_input);

			// evaluate postfix

		}
		catch (std::runtime_error & err) {
			std::cout << "An error has occurred -> " << err.what() << "\n";
		}
		catch (std::exception & err) {
			std::cout << "An error has occurred -> " << err.what() << "\n";
		}
		catch (...) {
			std::cout << "An unknown error has occurred.";
		}
	}

	delete calc;


    return 0;
}