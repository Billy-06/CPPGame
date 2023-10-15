//
// EnvironmentSetup.cpp
//

#
#include <iostream>
#include "EnvironmentSetup.h"

void EnvironementSetup::SetUp()
{		
	std::cout << "EnvironmentSetup::SetUp()" << std::endl;
}

void EnvironementSetup::TearDown()
{
	std::cout << "EnvironmentSetup::TearDown()" << std::endl;
}
