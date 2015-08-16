/*
 * GA.h
 *
 *  Created on: 14/08/2015
 *      Author: ssat335
 */

#ifndef GA_H_
#define GA_H_

#include "Population.h"

class GA {

private:
	Population* m_pPopulation;
	int m_PopulationSize;
	int m_genCount;
	int m_tempPopSize;
	int m_crossOverVal;
	int m_mutatePar;
	double m_crossOverPercentage; // 0.25 equivalent
	double m_mutatePercentage;
	int m_IndividualSize;

public:
	GA();
	void Initialise(int populationSize);
	void Run();
	void SelectPopulation();
	void CrossOverIndividuals();
	void Mutate();
	virtual ~GA();
};

#endif /* GA_H_ */
