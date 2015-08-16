/*
 * Debug.h
 *
 *  Created on: 16/08/2015
 *      Author: shameer
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

std::string FormDebugHead();

void PrintTheStack();

#define TRACE(stuff) std::cout << FormDebugHead() << stuff << std::endl << std::flush;

#define MARK std::cout << FormDebugHead() <<  __FILE__ << " at line " << __LINE__ << std::endl << std::flush;

/** Print the name and value of the given variable.
 * @param var */
#define PRINT_VARIABLE(var) std::cout << FormDebugHead() << #var " = " << var << std::endl << std::flush;

/** Print the name and value of the given variables.
 * @param var1
 * @param var2
 */
#define PRINT_2_VARIABLES(var1,var2) std::cout << FormDebugHead() << #var1 " = " << var1 << ", " \
    #var2 " = " << var2 << std::endl << std::flush;

/** Print the name and value of the given variables.
 * @param var1
 * @param var2
 * @param var3
 */
#define PRINT_3_VARIABLES(var1,var2,var3) std::cout << FormDebugHead() << #var1 " = " << var1 << ", " \
    #var2 " = " << var2 << ", " #var3 " = " << var3 << std::endl << std::flush;

/** Print the name and value of the given variables.
 * @param var1
 * @param var2
 * @param var3
 * @param var4
 */
#define PRINT_4_VARIABLES(var1,var2,var3,var4) std::cout << FormDebugHead() << #var1 " = " << var1 << ", " \
    #var2 " = " << var2 << ", " #var3 " = " << var3 << ", " \
    #var4 " = " << var4 << std::endl << std::flush;

/** Print the name and value of the given variables.
 * @param var1
 * @param var2
 * @param var3
 * @param var4
 * @param var5
 */
#define PRINT_5_VARIABLES(var1,var2,var3,var4,var5) std::cout << FormDebugHead() << #var1 " = " << var1 << ", " \
    #var2 " = " << var2 << ", " #var3 " = " << var3 << ", " \
    #var4 " = " << var4 << ", " #var5 " = " << var5 <<std::endl << std::flush;

/** Quit (assert(0)) on the n-th time this line is reached, for the given n.
 * @param n */
#define QUIT_AFTER_N_VISITS(n) { static unsigned counter=0; if (++counter==(n)) {TRACE("User-forced quit."); assert(0);} }

/** Print how many times this line has been reached, everytime it is reached.
 * @param message  message to include in brackets */
#define HOW_MANY_TIMES_HERE(message) { \
    static unsigned counter=1; \
    std::cout << FormDebugHead() << "Num times here (" << message << "): " << counter++ << std::endl << std::flush; }

/** Prints the given message, but only from the n-th time that line is reached, for the given n.
 * @param stuff  what to print
 * @param n */
#define TRACE_FROM_NTH_VISIT(stuff,n) { \
    static unsigned counter=0; \
    if (++counter>=(n)) {TRACE(stuff<<" (visit "<<counter<<")");} }

/** Display a std::vector.
 * @param v */
#define PRINT_VECTOR(v) \
    { std::cout << FormDebugHead() << #v " = {"; \
      for (unsigned _i=0; _i<v.size(); _i++) { \
          std::cout << (_i==0?"":",") << v[_i]; } \
      std::cout << "}" << std::endl << std::flush; }

/** (For debugging on a seriously large number of processes)
 * Show the mark that we have reached this line of code, but do it in process order, which
 * is important if we suspect that one or more processes are missing.
 *
 * This will also isolate all the MARKs which appear for a particular line of code, since all process have to synchronise at
 * the beginning of the round-robin.
 *
 * Note that this will change the parallel behaviour of the code -- if one process really is missing then the first barrier inside
 * the round-robin will cause deadlock.
 */
#define MARK_IN_ORDER PetscTools::BeginRoundRobin(); MARK; PetscTools::EndRoundRobin();

/**
 * In extremis, print enough of the stack to see how we got to this point (e.g. at EXCEPTION time)
 */
#define STACK PrintTheStack();

#endif /* DEBUG_H_ */
