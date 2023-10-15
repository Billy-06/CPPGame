//
// EnvironmentSetup.h
//

#pragma once
#include "pch.h"


class EnvironementSetup : public ::testing::Environment
{
	public:
	virtual void SetUp();

	virtual void TearDown();
};