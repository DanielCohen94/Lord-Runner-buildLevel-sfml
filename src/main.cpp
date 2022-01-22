#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "Controller.h"

int main()
{
	try { 
		Controller c;
		c.build_map();
	}
	catch (std::exception & er)
	{
		std::cout << "\nException: " << er.what() << std::endl;
	}

	return( EXIT_SUCCESS );
} // end main
