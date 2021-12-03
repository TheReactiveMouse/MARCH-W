//
// Created by there on 12/1/2021.
//

#include <exception>

#ifndef MARCHW_ERRORINVALIDMATHEXECUTION_H
#define MARCHW_ERRORINVALIDMATHEXECUTION_H

#endif //MARCHW_ERRORINVALIDMATHEXECUTION_H

struct CPUCritical_MathExecutionIncorrect : public std::exception {
    const char * what () const throw ()
    {
        return "Sorry, but the processor can't handle it. You should to use numbers smaller than you want. It's 16 bits!";
    }
};