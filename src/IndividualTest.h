/*
 * IndividualTest.h
 *
 *  Created on: 15/08/2015
 *      Author: shameer
 */

#ifndef INDIVIDUALTEST_H_
#define INDIVIDUALTEST_H_

#include "Individual.h"

class IndividualTest {
private:
	Individual* m_myIndi;

public:
	IndividualTest();
	void operator()();
	virtual ~IndividualTest();
};

#endif /* INDIVIDUALTEST_H_ */
