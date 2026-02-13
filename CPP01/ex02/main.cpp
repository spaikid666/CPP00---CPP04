#include <string>
#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of the string variable:\n";
	std::cout << &str << "\n";

	std::cout << "Memory address of the pointer to the string:\n";
	std::cout << stringPTR << "\n";

	std::cout << "Memory address of the reference to the string:\n";
	std::cout << &stringREF << "\n";

	std::cout << "\n";

	std::cout << "Value of the string variable:\n";
	std::cout << str << "\n";

	std::cout << "Value of the pointer to the string:\n";
	std::cout << *stringPTR << "\n";

	std::cout << "Value of the reference to the string:\n";
	std::cout << stringREF << "\n";
}