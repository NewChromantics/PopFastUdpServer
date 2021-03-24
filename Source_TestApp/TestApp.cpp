#include "PopTemplate.h"
#include <iostream>

int main()
{
	int Version[] = { PopTemplate_GetVersion_Major(), PopTemplate_GetVersion_Minor(), PopTemplate_GetVersion_Patch() };
	
	std::cout << "Version " << Version[0] << "." << Version[1] << "." << Version[2] << std::endl;
	
	return 0;
}

