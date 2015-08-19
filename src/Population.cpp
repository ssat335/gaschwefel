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
#include <iostream>
#include <cmath>
#include "Debug.h"

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

std::vector<double> Population::getNormalisedFitnessVector() {

	return m_IndividualFitness;
}

double Population::getTotalFitnessPopulation() {

	return m_totalFitness;
}

std::vector<double> Population::getProbabilityVector() {
	return m_ProbablityOfIndividual;
}

std::vector<double> Population::getCumulativeProbailityEachIndividual() {

	m_IndividualFitness.clear();
	for (int i = 0; i < m_Population.size(); i++) {
		m_IndividualFitness.push_back(1/(getIndividual(i).getFitnessOfIndividual() + 1));
	}
	PRINT_VECTOR(m_IndividualFitness);

	assert(m_IndividualFitness.size() == m_Population.size());
	m_totalFitness = 0;
	for (int i = 0; i < m_Population.size(); i++) {
		m_totalFitness += m_IndividualFitness[i];
	}
	PRINT_VARIABLE(m_totalFitness);

	m_ProbablityOfIndividual.clear();
	for (int i = 0; i < m_Population.size(); i++) {
		m_ProbablityOfIndividual.push_back(m_IndividualFitness[i]/m_totalFitness);
	}
	PRINT_VECTOR(m_ProbablityOfIndividual);

	m_CumulativeProbability.clear();
	m_CumulativeProbability.push_back(m_ProbablityOfIndividual[0]);
	for (int i = 1; i < m_Population.size(); i++) {
		m_CumulativeProbability.push_back(m_CumulativeProbability[i-1] + m_ProbablityOfIndividual[i]);
		assert(m_CumulativeProbability[i] >= 0 && m_CumulativeProbability[i] <= 1.001);
	}
	PRINT_VECTOR(m_CumulativeProbability);

	assert(m_ProbablityOfIndividual.size() == m_Population.size());
	return m_CumulativeProbability;
}

void Population::setIndividual(int index, Individual individual) {
	assert(index >= 0 || index >= m_Population.size());
	m_Population[index] = individual;
}

void Population::print() {
	std::cout << "--------------------------------------------------"<< std::endl;
	int size = m_Population.size();
	std::cout << "Population Size: " << size << std::endl;
	for (int i = 0; i < size; i++) {
		Individual myIndi = m_Population[i];
		myIndi.print();
	}
	std::cout << std::endl << "--------------------------------------------------" << std::endl;
}

Population::~Population() {
}

