//
// Created by there on 12/3/2021.
//

#include <exception>

#ifndef MARCHW_ERRORDIVIDEBYZERO_H
#define MARCHW_ERRORDIVIDEBYZERO_H

#endif //MARCHW_ERRORDIVIDEBYZERO_H

struct CPUCriticalError_DivideByZero : public std::exception {
    const char * what () const throw () {
        return "CPU can't continue to work, you tried to divide by zero. Sorry, but we do not support breaking the math rules.";
    }
};