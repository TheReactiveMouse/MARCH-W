//
// Created by there on 12/9/2021.
//
#include "ErrorProtectedMemory.h"
#include "ErrorOutOfTheRange.h"
#include "ErrorInvalidMathExecution.h"
#include "ErrorIsNotAValue.h"
#include "ErrorDivideByZero.h"

    /*
     * Memory Guardians.
     */

    void GuardCheckRAMRequest(int address1, int address2, char* MemoryAgent) {
        if (address1 > sizeof(MemoryAgent) ||
            address2 > sizeof(MemoryAgent)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (address2 != NULL && address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 10) { throw CPUCriticalStop_AccessProtectedMemory(); }
        if (address2 != NULL && address2 < 10) { throw CPUCriticalStop_AccessProtectedMemory(); }
    }

    /*
     *  Math Guardians.
     */

    void GuardCheckMathCorrect_Add(int address1, int address2, char* MemoryAgent)
    {
        if (address1 > sizeof(MemoryAgent) ||
            address2 > sizeof(MemoryAgent)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (MemoryAgent[address1] > 65536 ||
                MemoryAgent[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(MemoryAgent[address1]) != true ||
            isdigit(MemoryAgent[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (MemoryAgent[address1] + MemoryAgent[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
    }

    void GuardCheckMathCorrect_Dec(int address1, int address2, char* MemoryAgent)
    {
        if (address1 > sizeof(MemoryAgent) ||
            address2 > sizeof(MemoryAgent)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (MemoryAgent[address1] > 65536 ||
            MemoryAgent[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(MemoryAgent[address1]) != true ||
            isdigit(MemoryAgent[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (MemoryAgent[address1] + MemoryAgent[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
    }

    void GuardCheckMathCorrect_Div(int address1, int address2, char* MemoryAgent)
    {
        if (address1 > sizeof(MemoryAgent) ||
            address2 > sizeof(MemoryAgent)) { throw CPUStop_OutOfMemoryRange(); }
        if (MemoryAgent[address1] == '0' ||
            MemoryAgent[address2] == '0') { throw CPUCriticalError_DivideByZero(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (MemoryAgent[address1] > 65536 ||
            MemoryAgent[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(MemoryAgent[address1]) != true ||
            isdigit(MemoryAgent[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (MemoryAgent[address1] + MemoryAgent[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
    }

    void GuardCheckMathCorrect_Mul(int address1, int address2, char* MemoryAgent)
    {
        if (address1 > sizeof(MemoryAgent) ||
            address2 > sizeof(MemoryAgent)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (MemoryAgent[address1] > 65536 ||
            MemoryAgent[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(MemoryAgent[address1]) != true ||
            isdigit(MemoryAgent[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (MemoryAgent[address1] + MemoryAgent[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
    }

    // Logic Guardians.

    void GuardCheckLogicCorrect_Cmp(int address1, int address2, char* MemoryAgent)
    {
        if (address1 > sizeof(MemoryAgent) ||
            address2 > sizeof(MemoryAgent)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (MemoryAgent[address1] > 65536 ||
            MemoryAgent[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (MemoryAgent[address2] == MemoryAgent[address1]) { MemoryAgent[3] = '1'; }
        else { MemoryAgent[3] = '0'; }
    }

