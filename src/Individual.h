/*
 * Individual.h
 *
 *  Created on: 13/08/2015
 *      Author: ssat335
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include <vector>

class Individual {

private:
	int m_dimension;
	std::vector<double> m_vIndividual;
	double m_fitness;
	int m_ValRangeMax;
	int m_ValRangeMin;

public:
	Individual();
	Individual(int dimension, int maxVal, int minVal);
	void createRandomIndividual();
	double getAValInIndividual(int index);
	void setAValInIndividula(double val, int index);
	int getIndividualDimension();
	double getFitnessOfIndividual();
	Individual generateCrossOver(Individual individual, int crossover);
	Individual mutate(int mutateParameter);
	virtual ~Individual();
};

#endif /* INDIVIDUAL_H_ */
