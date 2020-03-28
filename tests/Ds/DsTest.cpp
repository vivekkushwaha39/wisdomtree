/*
 * DsTest.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: vivek
 */
#include "hcf_lcm.h"
#include <iostream>
#include <CppUTest/TestHarness.h>

TEST_GROUP(DS) {

};

TEST(DS, HCFTest) {
	int ans = findHcf(12, 12);
	CHECK_EQUAL(12, ans);
}

