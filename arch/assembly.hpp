#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <thread>
#include "GuardRules.h"
#include "Variables.h"
#include "Threading.h"
#include "GPU.h"
using namespace std;


class Memory {
    public:
        char memory[768];
        std::map<int, std::function<void()>> memory_func{};

};

namespace processor {
    Memory InternalMemory;
    int RegisteredFunctions = 0;
    
    Threading::Core Core1;
    Threading::Core Core2;
    Threading::Core Core3;
    Threading::Core Core4;
    Threading::Core Core5;
    Threading::Core Core6;
    Threading::Core Core7;
    Threading::Core Core8;

    /*
     * Guard Rules.
     */



    void mov(int address1, int address2 = -1, char address2_t[] = NULL) {

        GuardCheckRAMRequest(address1, address2, InternalMemory.memory);
        if (address2 == NULL && address2_t != NULL && sizeof(address2_t) > 1) {
            for (int x = 0; x < sizeof(address2_t); x++) {
                InternalMemory.memory[address1 + x] = address2_t[x];
            }
        }
        if (address2 == NULL && address2_t != NULL && sizeof(address2_t) == 1) {
            InternalMemory.memory[address1] = address2_t[0];
        }
    }

    void add(int address1, int address2) {
        GuardCheckMathCorrect_Add(address1, address2, InternalMemory.memory);
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] + (int) InternalMemory.memory[address2];
    }

    void dec(int address1, int address2) {
        GuardCheckMathCorrect_Dec(address1, address2, InternalMemory.memory);
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] - (int) InternalMemory.memory[address2];
    }

    void div(int address1, int address2) {
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] / (int) InternalMemory.memory[address2];
    }

    void mul(int address1, int address2) {
        GuardCheckMathCorrect_Mul(address1, address2, InternalMemory.memory);
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] * (int) InternalMemory.memory[address2];
    }

    void cmp(int address1, int address2) {
        GuardCheckLogicCorrect_Cmp(address1, address2, InternalMemory.memory);
    }

    void reg(std::function<void()> Function) {
        InternalMemory.memory_func[RegisteredFunctions] = Function;
        RegisteredFunctions++;
    }


    void jmp(int address, int Core) {

        switch(Core)
        {
            case 1:
                Core1.Launch(InternalMemory.memory_func[address]);
            case 2:
                Core2.Launch(InternalMemory.memory_func[address]);
            case 3:
                Core3.Launch(InternalMemory.memory_func[address]);
            case 4:
                Core4.Launch(InternalMemory.memory_func[address]);
            case 5:
                Core5.Launch(InternalMemory.memory_func[address]);
            case 6:
                Core6.Launch(InternalMemory.memory_func[address]);
            case 7:
                Core7.Launch(InternalMemory.memory_func[address]);
            case 8:
                Core8.Launch(InternalMemory.memory_func[address]);

        }
    }

    void je(int Pointer, int Core) {
        if (InternalMemory.memory[3] == '1') {
            jmp(Pointer, Core);
        }
    }

    void jne(int Pointer, int Core) {
        if (InternalMemory.memory[3] == '0') {
            jmp(Pointer, Core);
        }
    }

    void ssc() { exit(0); }

    void rui(int address) {
        std::cin >> InternalMemory.memory[address];
    }

    void loop(int Pointer, int Core)
    {
        while(InternalMemory.memory[3] != '1')
        {
            jmp(Pointer, Core);
        }
    }
}