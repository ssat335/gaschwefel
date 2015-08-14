/*
 * SchwefelFunction.cpp
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#include "SchwefelFunction.h"

#include <assert.h>
#include <vector>
#include <math.h>

SchwefelFunction::SchwefelFunction() {
	m_result = 0.0;

}

double SchwefelFunction::EvaluateFunction(const std::vector<double>& parameters) {
	int d = parameters.size();
	assert(d > 0);

	//Usually evaluated on the hypercube xi ∈ [-500, 500], for all i = 1, …, d.
	for(int i = 0; i < d; i++) {
		double xi = parameters[i];
		m_result += (-xi) * sin(sqrt(fabs(xi)));
	}
	m_result = 418.9829 * d + m_result;
	return m_result;
}

double SchwefelFunction::getVal() {
	return m_result;
}

SchwefelFunction::~SchwefelFunction() {
	// TODO Auto-generated destructor stub
}

