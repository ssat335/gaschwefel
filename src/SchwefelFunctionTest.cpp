/*
 * SchwefelFunctionTest.cpp
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#include "cute.h"

#include "SchwefelFunction.h"
#include "SchwefelFunctionTest.h"

SchwefelFunctionTest::SchwefelFunctionTest() {

	SchwefelFunction testFunction;
	std::vector<double> vals;
	vals.push_back(420);
	vals.push_back(20);
	double val = testFunction.EvaluateFunction(vals);
	std::cout << "Inside test val " << val << std::endl;
	ASSERT_EQUAL_DELTA(438.5268, val, 0.01);
}

void SchwefelFunctionTest::operator() () {

}

SchwefelFunctionTest::~SchwefelFunctionTest() {
	// TODO Auto-generated destructor stub
}

