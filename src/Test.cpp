#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "SchwefelFunctionTest.h"
#include "GATest.h"
#include "IndividualTest.h"

void runSuite(){
	cute::suite s;
	//s.push_back(SchwefelFunctionTest());
	//s.push_back(IndividualTest());
	s.push_back(GATest());
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



