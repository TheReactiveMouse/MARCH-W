//
// Created by there on 12/9/2021.
//

#include <string>

#ifndef MARCHW_VARIABLES_H
#define MARCHW_VARIABLES_H

#endif //MARCHW_VARIABLES_H

class dt {
    public:
        dt(std::string Text)
        {
            value = Text;
        }
        const char * get()
        {
            return value.c_str();
        }
    private:
        std::string value = "";
};

class dn {
    public:
        dn(int Number)
        {
            value = Number;
        }
        int get()
        {
            return value;
        }
    private:
        int value = 0;
};

class df {
    public:
        df(float FloatNumber)
        {
            value = FloatNumber;
        }
        float get()
        {
            return value;
        }
    private:
        float value = 0.00;
};

