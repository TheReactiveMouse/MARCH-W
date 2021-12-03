//
// Created by there on 12/1/2021.
//

#include <exception>

#ifndef MARCHW_ERROROUTOFTHERANGE_H
#define MARCHW_ERROROUTOFTHERANGE_H

#endif //MARCHW_ERROROUTOFTHERANGE_H

struct CPUStop_OutOfMemoryRange : public std::exception{
    const char * what () const throw ()
    {
        return "You got out of the range memory";
    }
};