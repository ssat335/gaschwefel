/*
 * SchwefelFunction.h
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#ifndef SCHWEFELFUNCTION_H_
#define SCHWEFELFUNCTION_H_

#include <vector>
using namespace std;

class SchwefelFunction {

private:
	double m_result;

public:
	SchwefelFunction();
	double EvaluateFunction(const std::vector<double>&);
	double getVal();
	virtual ~SchwefelFunction();
};

#endif /* SCHWEFELFUNCTION_H_ */

