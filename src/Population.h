/*
 * Population.h
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include "Individual.h"

#include <vector>

class Population {
	std::vector<Individual> m_Population;
	bool m_isExisting;
	std::vector<double> m_IndividualFitness;
	double m_totalFitness;
	std::vector<double> m_ProbablityOfIndividual;
	std::vector<double> m_CumulativeProbability;


public:
	Population(int pop_size, int individual_size);
	Individual getIndividual(int index);
	int getPopulationSize();
	Individual getHighestFitIndividual();
	int getHighestFitIndex();
	std::vector<double> getNormalisedFitnessVector();
	double getTotalFitnessPopulation();
	std::vector<double> getProbabilityVector();
	std::vector<double> getCumulativeProbailityEachIndividual();
	void setIndividual(int index, Individual individual);
	void print();
	virtual ~Population();
};

#endif /* POPULATION_H_ */
