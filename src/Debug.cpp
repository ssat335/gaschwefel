/*
 * Debug.cpp
 *
 *  Created on: 16/08/2015
 *      Author: shameer
 */

#include "Debug.h"

#include <execinfo.h> //For backtrace
#include <stdlib.h>
std::string FormDebugHead()
{
    std::stringstream header;
    header << "DEBUG: ";
    return header.str();
}


void PrintTheStack()
{
    // If you ever need backtrace in Windows then the RTFM begins at "CaptureStackBackTrace"
    TRACE("Stack information");
#ifndef _MSC_VER
    // storage array for stack trace address data
    void* address_list[20u]; //20 is about the number of stack symbols we are going to print

    // retrieve current stack addresses
    unsigned num_addresses = backtrace(address_list, sizeof(address_list) / sizeof(void*));

    char** symbol_list = backtrace_symbols(address_list, num_addresses);

    // iterate over the returned symbol lines.
    for (unsigned i = 0; i < num_addresses; i++)
    {
        // We could demangle, but this may not be portable on GNU Linux versus Mac OSX
        // char* ret = abi::__cxa_demangle(begin_name, funcname, &funcnamesize, &status);
        TRACE("Level " << i << ": " << symbol_list[i]);
    }
    free(symbol_list);
#endif //_MSC_VER
}



