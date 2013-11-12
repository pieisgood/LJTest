#include "SimpleAssert.h"
#include <fstream>


//we write our assert failures to a text file for easier reference
bool QDGE_ASSERT( bool exp, char* desc, int line, char* file_name)
{
	if( exp )
	{
		return !exp;
	}
	else
	{
		std::ofstream assertFile;
		assertFile.open("assert_failures.txt", std::ios_base::app);
		assertFile << "Failure File: " << file_name << '\n';
		assertFile << "Failure Line: " << line << '\n';
		assertFile << "Failure Description: " << desc << '\n';
		assertFile << '\n';
		assertFile.close();

		return !exp;
	}
}
