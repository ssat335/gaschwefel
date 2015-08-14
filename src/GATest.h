/*
 * GATest.h
 *
 *  Created on: 14/08/2015
 *      Author: ssat335
 */

#ifndef GATEST_H_
#define GATEST_H_

#include "GA.h"

class GATest {

private:
	GA* m_pmyGA;

public:
	GATest();
	void operator()();
	virtual ~GATest();
};

#endif /* GATEST_H_ */
