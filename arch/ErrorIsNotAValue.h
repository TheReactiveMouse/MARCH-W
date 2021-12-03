//
// Created by there on 12/2/2021.
//

#include <exception>

#ifndef MARCHW_ERRORISNOTAVALUE_H
#define MARCHW_ERRORISNOTAVALUE_H

#endif //MARCHW_ERRORISNOTAVALUE_H

struct CPUError_IsNotAvalue : public std::exception {
    const char * what () const throw ()
    {
        return "This value cannot be processed due to an unknown error, you have to match it really exists.";
    }
};