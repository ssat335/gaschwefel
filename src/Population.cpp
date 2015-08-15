/*
 * Population.cpp
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#include "Population.h"
#include "Individual.h"
#include "SchwefelFunction.h"

#include <assert.h>

Population::Population() {
	m_isExisting = false;
	m_Population.clear();
}

Population::Population(int pop_size, int individual_size) {
	assert(pop_size > 0 || individual_size > 0 || m_Population.size() == 0);
	m_Population.clear();
	for (int i = 0; i < pop_size; i++)
	{
		Individual individual(individual_size, 1000, 0);
		m_Population.push_back(individual);
	}
}

Individual Population::getIndividual(int index) {
	assert(index >= 0);
	return m_Population[index];
}

int Population::getPopulationSize() {
	return m_Population.size();
}

Individual Population::getHighestFitIndividual() {
	return m_Population[getHighestFitIndex()];
}

int Population::getHighestFitIndex() {
	int pop_size = m_Population.size();
	assert(pop_size>0);
	int fittestIndex = 0;
	for(int i = 1; i < pop_size; i++) {
		if(m_Population[fittestIndex].getFitnessOfIndividual() >
										m_Population[i].getFitnessOfIndividual()) {
			fittestIndex = i;
		}
	}
	return fittestIndex;
}

void Population::setIndividual(int index, Individual individual) {
	assert(index >= 0 || index >= m_Population.size());
	m_Population[index] = individual;
}

Population::~Population() {
}

