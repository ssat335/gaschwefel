/*
 * IndividualTest.cpp
 *
 *  Created on: 15/08/2015
 *      Author: shameer
 */

#include "IndividualTest.h"
#include "Individual.h"
#include <iostream>
#include <assert.h>

IndividualTest::IndividualTest() {
	for (int i = 0; i < 10; i++) {
		Individual* m_myIndi = new Individual(2, 1000, 0);
		m_myIndi->print();
		assert(m_myIndi->getFitnessOfIndividual() > 0);
		delete m_myIndi;
	}

	Individual myIndividual(2, 1000, 0);
	myIndividual.print();
	for (int i = 0; i < 2; i++ ) {
		myIndividual.mutate(i);
		myIndividual.print();
		assert(myIndividual.getFitnessOfIndividual() > 0);
	}

	Individual secondIndi(2, 1000, 0);
	secondIndi.print();
	myIndividual.generateCrossOver(secondIndi, 1);
	myIndividual.print();

	Individual secondIndi2(2, 921, 920.23);
	secondIndi2.print();
	assert(secondIndi2.getFitnessOfIndividual() < 1);;
}

void IndividualTest::operator() () {

}

IndividualTest::~IndividualTest() {
}

