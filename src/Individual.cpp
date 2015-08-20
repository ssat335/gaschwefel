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
#include <iostream>
#include <cmath>
#include "Debug.h"

Individual::Individual(int dimension, int maxVal, int minVal) {
	m_dimension = dimension;
	m_ValRangeMax = maxVal;
	m_ValRangeMin = minVal;
	m_vIndividual.clear();
	createRandomIndividual();
}

void Individual::createRandomIndividual() {
	assert(m_dimension > 0);
	assert(m_ValRangeMax != m_ValRangeMin);
	assert(m_vIndividual.size() == 0);
	for(int i = 0; i < m_dimension; i++)
	{
		double val = m_ValRangeMin + (double)rand() / RAND_MAX * (m_ValRangeMax-m_ValRangeMin);
		m_vIndividual.push_back(val);
	}
}

double Individual::getAValInIndividual(int index) {
	assert(m_dimension > 0);
	assert((unsigned int) index < m_vIndividual.size());
	return m_vIndividual[index];
}

void Individual::setAValInIndividula(double val, int index) {
	assert(m_dimension > 0);
	assert((unsigned int) index < m_vIndividual.size());
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

Individual Individual::generateCrossOver(Individual& individual, int crossoverpoint) {
	assert(crossoverpoint < m_dimension);
	Individual temp = individual;
	for(int i =0; i < m_dimension; i++) {
		if( i >= crossoverpoint) {
			individual.setAValInIndividula(m_vIndividual[i], i);
			m_vIndividual[i] = temp.getAValInIndividual(i);
		}
	}
	return *this;
}

Individual Individual::mutate(double mutatePercentage, double range) {
	assert(mutatePercentage > 0 && range > 0);
	double random = 0;
	for(int i =0; i < m_dimension; i++) {
		random = (double) rand() / (RAND_MAX);
		if(random < mutatePercentage) {
			double temp = pow((-1),round((double)rand())) * range * (double)rand() / (double)RAND_MAX;
			while ((temp + m_vIndividual[i]) > m_ValRangeMax || (temp + m_vIndividual[i]) < m_ValRangeMin) {
				temp = pow((-1),round((double)rand())) * range * (double)rand() / (double)RAND_MAX;
			}
			m_vIndividual[i]+=temp;
		}
	}
	return *this;
}

void Individual::print(){
	for(int i =0; i < m_dimension; i++) {
		std::cout << "[" << i << "] " << m_vIndividual[i] << "\t| ";
 	}
	std::cout << std::endl;
}

Individual::~Individual() {
	// TODO Auto-generated destructor stub
}

