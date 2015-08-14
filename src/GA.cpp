/*
 * GA.cpp
 *
 *  Created on: 14/08/2015
 *      Author: ssat335
 */

#include "GA.h"
#include<assert.h>
#include "Population.h"
#include "Individual.h"

GA::GA() {
	// TODO Auto-generated constructor stub

}

void GA::Initialise(int populationSize) {
	m_genCount = 0;
	m_tempPopSize = 5;
	m_crossOverVal = 1;
	m_mutatePar = 1;
	m_IndividualSize = 2;
	m_pPopulation = new Population(m_PopulationSize, m_IndividualSize);
	assert(m_pPopulation != 0);
}

void GA::Run() {
	assert(m_tempPopSize > 0);
	int highestFitIndex = m_pPopulation->getHighestFitIndex();
	while(m_pPopulation->getHighestFitIndividual().getFitnessOfIndividual() > 1e-3) {
		m_genCount ++;
		for (int i = 0; i < m_PopulationSize; i++) {
			if (i != highestFitIndex) {
				Population* pTempPopulation1 = new Population(m_tempPopSize, m_IndividualSize);
				Population* pTempPopulation2 = new Population(m_tempPopSize, m_IndividualSize);
				Individual individual1 = pTempPopulation1->getHighestFitIndividual();
				Individual individual2 = pTempPopulation2->getHighestFitIndividual();
				Individual cross_over_individual = individual1.generateCrossOver(individual1, m_crossOverVal);
				m_pPopulation->setIndividual(i, cross_over_individual);
			}
		}
		Mutate();
	}
}

void GA::Mutate() {
	for (int i = 0; i < m_PopulationSize; i++) {
		Individual mutated_individual = m_pPopulation->getIndividual(i).mutate(m_mutatePar);
		m_pPopulation->setIndividual(i, mutated_individual);
	}
}



GA::~GA() {
	delete m_pPopulation;
}

