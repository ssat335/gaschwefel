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
#include <iostream>
#include <cstdlib>
#include "Debug.h"


GA::GA(int populationSize) {
	// TODO Auto-generated constructor stub
	m_genCount = 0;
	m_tempPopSize = 5;
	m_crossOverPercentage = 0.5;
	m_mutatePercentage = 0.25;
	m_IndividualSize = 2;
	m_PopulationSize = populationSize;
	m_crossOverVal = 1;
	m_mutateRange = 1;
	Initialise();

}

void GA::Initialise() {
	assert(m_PopulationSize > 0);
	m_pPopulation = new Population(m_PopulationSize, m_IndividualSize);
	assert(m_pPopulation != 0);
}

void GA::Run() {
	assert(m_tempPopSize > 0);
	while(m_pPopulation->getHighestFitIndividual().getFitnessOfIndividual() > 1e-4) {
	//while(m_genCount < 20) {

		//TRACE("Initial Population: ");
		//m_pPopulation->print();

		m_genCount ++;
		//PRINT_VARIABLE(m_genCount);

		SelectPopulation();
		//TRACE("Selected Population");
		//m_pPopulation->print();

		CrossOverIndividuals();
		//TRACE(" After cross over and before mutation ");
		//m_pPopulation->print();

		Mutate();
		//TRACE(" After mutation ");
		//m_pPopulation->print();

		PRINT_VARIABLE(m_pPopulation->getHighestFitIndividual().getFitnessOfIndividual());
	}
	std::cout << "Solution at " << m_genCount << " is: " << std::endl;
	m_pPopulation->getHighestFitIndividual().print();
}

void GA::SelectPopulation() {
	std::vector<double> cumulativeProbaility = m_pPopulation->getCumulativeProbailityEachIndividual();
	for (int i = 0; i < m_PopulationSize; i++) {
		double random = ((double) rand() / (RAND_MAX));
		for(int j = 0; (j < m_PopulationSize); j++) {
			if (random < cumulativeProbaility[j]) {
				m_pPopulation->setIndividual(i, m_pPopulation->getIndividual(j));
				j = m_PopulationSize;
			}
		}

	}
}
void GA::CrossOverIndividuals() {
	std::vector<Individual> parent;
	std::vector<int> parent_index;
	for (int i = 0; i < m_PopulationSize; i++) {
		if(((double) rand() / (RAND_MAX)) < m_crossOverPercentage) {
			parent.push_back(m_pPopulation->getIndividual(i));
			parent_index.push_back(i);
		}
	}
	int num_pairs = int (parent_index.size() / 2);
	for (int i = 0; i < num_pairs; i++) {
		Individual offspring1 = parent[i*2].generateCrossOver(parent[(i*2)+1],  m_crossOverVal);
		m_pPopulation->setIndividual(parent_index[i*2], offspring1);
		m_pPopulation->setIndividual(parent_index[(i*2)+1], parent[(i*2)+1]);
	}
}

void GA::Mutate() {
	for (int i = 0; i < m_PopulationSize; i++) {
		Individual mutated_individual = m_pPopulation->getIndividual(i).mutate(m_mutatePercentage, m_mutateRange);
		m_pPopulation->setIndividual(i, mutated_individual);
	}
}



GA::~GA() {
	delete m_pPopulation;
}

