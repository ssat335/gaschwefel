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
	double minimum = 100;
	double x1 = 0;
	double x2 = 0;
	for(int i = 0; i< 1000; i++) {
		for( int j= 0; j < 1000; j++) {
			vals.push_back(i);
			vals.push_back(j);
			double val = testFunction.EvaluateFunction(vals);
			if (val < minimum) {
				minimum = val;
				x1 = i;
				x2 = j;
			}
			vals.clear();
		}
	}
	ASSERT_EQUAL_DELTA(921, x1 , 0.01);
	ASSERT_EQUAL_DELTA(921, x2 , 0.01);
	ASSERT_EQUAL_DELTA(0.000271968, minimum , 0.0001);
}

void SchwefelFunctionTest::operator() () {

}

SchwefelFunctionTest::~SchwefelFunctionTest() {
	// TODO Auto-generated destructor stub
}

