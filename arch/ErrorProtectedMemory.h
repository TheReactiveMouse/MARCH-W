//
// Created by there on 12/1/2021.
//
#include <exception>
#include <iostream>
#ifndef MARCHW_ERRORPROTECTEDMEMORY_H
#define MARCHW_ERRORPROTECTEDMEMORY_H

#endif //MARCHW_ERRORPROTECTEDMEMORY_H

struct CPUCriticalStop_AccessProtectedMemory : public std::exception
{
    const char * what () const throw ()
    {
        return "You attempted to access the memory that is protected and reserved for Advanced Processor Features, you have to read the CPU Engineer Documentation and checkout for reserved, protected, and reachable memory pointers.";
    }
};