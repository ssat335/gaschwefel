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

public:
	Population();
	Population(int pop_size, int individual_size);
	Individual getIndividual(int index);
	int getPopulationSize();
	Individual getHighestFitIndividual();
	int getHighestFitIndex();
	void setIndividual(int index, Individual individual);
	void print();
	virtual ~Population();
};

#endif /* POPULATION_H_ */
