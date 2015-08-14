/*
 * Individual.cpp
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#include <assert.h>
#include <cstdlib>
#include "Individual.h"
#include "SchwefelFunction.h"

Individual::Individual() {
	m_dimension = 0;
	m_fitness = 0;
	m_vIndividual.clear();
	m_ValRangeMax = 1000;
	m_ValRangeMin = 0;
}

Individual::Individual(int dimension, int maxVal, int minVal) {
	m_dimension = dimension;
	m_ValRangeMax = maxVal;
	m_ValRangeMin = minVal;
	createRandomIndividual();
}

void Individual::createRandomIndividual() {
	assert(m_dimension > 0);
	assert(m_ValRangeMax != m_ValRangeMin);
	for(int i = 0; i < m_dimension; i++)
	{
		m_vIndividual.push_back(rand()%(m_ValRangeMax-m_ValRangeMin + 1) + m_ValRangeMin);
	}
}

double Individual::getAValInIndividual(int index) {
	assert(m_dimension > 0);
	assert(index < m_vIndividual.size());
	return m_vIndividual[index];
}

void Individual::setAValInIndividula(double val, int index) {
	assert(m_dimension > 0);
	assert(index < m_vIndividual.size());
	m_vIndividual[index] = val;
}

int Individual::getIndividualDimension() {
	return m_dimension;
}

double Individual::getFitnessOfIndividual() {
	assert(m_dimension > 0);
	assert(m_vIndividual.size()> 0);
	SchwefelFunction testFunction;
	m_fitness = testFunction.EvaluateFunction(m_vIndividual);
	assert(m_fitness >= 0);
	return m_fitness;
}

Individual Individual::generateCrossOver(Individual individual, int crossoverpoint) {
	assert(crossoverpoint < m_dimension);
	for(int i =0; i < m_dimension; i++) {
		if( i >= crossoverpoint)
			m_vIndividual[i] = (m_vIndividual[i] + individual.getAValInIndividual(i))/2;
	}
	return *this;
}

Individual Individual::mutate(int mutateParameter) {
	assert(mutateParameter < m_dimension);
	for(int i =0; i < m_dimension; i++) {
		if( i >= mutateParameter)
			m_vIndividual[i] += (double)rand() / (double)RAND_MAX;
	}
	return *this;
}

Individual::~Individual() {
	// TODO Auto-generated destructor stub
}

