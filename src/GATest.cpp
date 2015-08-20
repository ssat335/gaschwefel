/*
 * GATest.cpp
 *
 *  Created on: 14/08/2015
 *      Author: ssat335
 */

#include "GATest.h"
#include "GA.h"
#include <cstdlib>
#include <time.h>
#include "Debug.h"

GATest::GATest() {
	unsigned int seed = time(NULL);
	PRINT_VARIABLE(seed);
	srand(seed);
	GA* m_pmyGA = new GA(1000);
	m_pmyGA->Run();
}

void GATest::operator() () {

}

GATest::~GATest() {
	// TODO Auto-generated destructor stub
	delete m_pmyGA;
}

