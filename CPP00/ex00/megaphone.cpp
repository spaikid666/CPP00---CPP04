#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int j = 1; j < argc; ++j)
    	{
			for (int i = 0; argv[j][i] != '\0'; ++i)
      	    	std::cout << (char)toupper(argv[j][i]);
    	}
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (0);
}