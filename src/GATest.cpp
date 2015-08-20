/*
 * GATest.cpp
 *
 *  Created on: 14/08/2015
 *      Author: ssat335
 */

#include "GATest.h"
#include "GA.h"

GATest::GATest() {
	GA* m_pmyGA = new GA(1000);
	m_pmyGA->Run();
}

void GATest::operator() () {

}

GATest::~GATest() {
	// TODO Auto-generated destructor stub
	delete m_pmyGA;
}

