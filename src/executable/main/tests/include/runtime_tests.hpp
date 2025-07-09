#pragma once
#include "gtest/gtest.h"
#include "runtime.hpp"

using namespace p2exe;


class runtime_tests : public ::testing::Test
{
protected: 
	
	runtime *rt;

	int test1();


	void SetUp() override;

	void TearDown() override;
};
